#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCore/QDebug>
QT_CHARTS_USE_NAMESPACE

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPieSeries *series = new QPieSeries();
    series->setHoleSize(0.5);
    series->append("Protein 4.2%", 4.2);
    QPieSlice *slice = series->append("Fat 15.6%", 15.6);
    slice->setExploded();
    slice->setLabelVisible();
    series->append("Other 23.8%", 23.8);
    series->append("Carbs 56.4%", 56.4);
    QChartView *chartView = new QChartView();
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->chart()->setTitle("Donut with a lemon glaze (100g)");
    chartView->chart()->addSeries(series);
    chartView->chart()->legend()->setAlignment(Qt::AlignBottom);
    chartView->chart()->setTheme(QChart::ChartThemeDark);
    QMainWindow window;
    window.setCentralWidget(chartView);
    window.setFont(QFont("Arial", 12));
    window.resize(400, 300);
    window.show();
    return a.exec();
}
