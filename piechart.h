#ifndef PIECHART_H
#define PIECHART_H

#include <QWidget>
#include <QtGui>
#include <QtCharts/QChart>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSlice>
#include <QPainter>
namespace Ui {
class pieChart;
}

class pieChart : public QWidget
{
    Q_OBJECT

public:
    int v;int d;int n;
    QString nom;
    pieChart(QWidget *parent,int a,int b,int c,QString nom);
    ~pieChart();

private:
    Ui::pieChart *ui;
};

#endif // PIECHART_H
