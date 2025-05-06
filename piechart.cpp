#include "piechart.h"
#include "ui_piechart.h"
#include <QVBoxLayout>

pieChart::pieChart(QWidget *parent,int a,int b,int c ,QString s)
    : QWidget(parent),v(a),d(b),n(c),nom(s),
    ui(new Ui::pieChart)
{
    ui->setupUi(this);
    this->resize(800,700);

    QPieSeries *series = new QPieSeries();
    series->append("victoire", v);
    series->append("defaite", d);
    series->append("null", n);

    series->setLabelsVisible(true);

    // Set percentage labels
    for (auto slice : series->slices()) {
        double percent = 100.0 * slice->percentage(); // percentage() gives a value between 0 and 1
        QString label = QString("%1 - %2%").arg(slice->label()).arg(QString::number(percent, 'f', 1));
        slice->setLabel(label);

    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle(nom + " statistics");



    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setParent(ui->widget); // <- inject it into your widget
    chartView->setGeometry(0, 0, ui->widget->width(), ui->widget->height());


    chartView->show();

    this->setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);

}

pieChart::~pieChart()
{
    delete ui;
}
