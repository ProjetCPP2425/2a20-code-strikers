#include "pie.h"
#include <QPainter>
#include <QtMath>  // For qDegreesToRadians

PieChartWidget::PieChartWidget(QWidget *parent) : QWidget(parent) {
    // Default values
    values = {0, 0, 0};
    labels = {"A", "B", "C"};
    colors = {Qt::red, Qt::green, Qt::blue};
}

void PieChartWidget::setData(int a, int b, int c) {
    values = {a, b, c};
    labels = {"A", "B", "C"};  // You can customize this
    update();  // Repaint widget
}

void PieChartWidget::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    QFont font("Arial", 10, QFont::Bold);
    painter.setFont(font);
    QFontMetrics fm(font);

    QRectF pieRect(50, 50, 300, 300);
    int total = 0;
    for (int value : values)
        total += value;

    if (total == 0) return;

    int startAngle = 0;
    for (int i = 0; i < values.size(); ++i) {
        int spanAngle = static_cast<int>(360.0 * values[i] / total * 16); // Qt uses 1/16 degree
        painter.setBrush(colors[i]);
        painter.drawPie(pieRect, startAngle, spanAngle);

        // Calculate the percentage for the slice
        double percentage = (static_cast<double>(values[i]) / total) * 100;
        QString labelWithPercentage = labels[i] + " (" + QString::number(percentage, 'f', 1) + "%)";

        // Compute angle in radians for label placement (center of the slice)
        double angleDeg = (startAngle + spanAngle / 2) / 16.0;
        double angleRad = qDegreesToRadians(angleDeg);

        // Distance from center to place text
        double radius = 100;  // Adjust this value to place text closer or further from the center

        QPointF center = pieRect.center();
        QPointF textPos = center + QPointF(radius * cos(angleRad), radius * sin(angleRad));

        // Adjust text position for better centering
        int textWidth = fm.horizontalAdvance(labelWithPercentage);
        int textHeight = fm.height();

        // Shift the text position to center it
        textPos -= QPointF(textWidth / 2.0, textHeight / 2.0);

        // Draw the text
        painter.setPen(Qt::white);  // Use white for contrast
        painter.drawText(textPos, labelWithPercentage);

        startAngle += spanAngle;
    }
}
