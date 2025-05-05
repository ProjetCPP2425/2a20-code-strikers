#ifndef PIECHARTWIDGET_H
#define PIECHARTWIDGET_H

#include <QWidget>
#include <QVector>
#include <QString>
#include <QColor>

class PieChartWidget : public QWidget {
    Q_OBJECT
public:
    explicit PieChartWidget(QWidget *parent = nullptr);
    void setData(int a, int b, int c);  // Pass 3 values

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QVector<int> values;
    QVector<QString> labels;
    QVector<QColor> colors;
};

#endif // PIECHARTWIDGET_H
