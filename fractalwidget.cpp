#include "fractalwidget.h"

FractalWidget::FractalWidget(QWidget *parent)
    : QWidget(parent) {
    setFixedSize(1000, 1000);
}

void FractalWidget::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    generateFractal(painter);
}

QColor FractalWidget::getColor(int iterations, int maxIterations) {
    if(iterations == maxIterations) return Qt::black;
    
    double t = (double)iterations / maxIterations;
    return QColor::fromHsvF(t * 0.3 + 0.5, static_cast<float> (0.8), 1.0 - t);
}