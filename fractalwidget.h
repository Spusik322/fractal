#pragma once

#include <cmath>
#include <QWidget>
#include <QPainter>
#include <QPen>
#include <complex>
#include <QRandomGenerator>

class FractalWidget : public QWidget {
    Q_OBJECT
public:
    explicit FractalWidget(QWidget *parent = nullptr);
    virtual void paintEvent(QPaintEvent *event) override;
    
protected:
    virtual void generateFractal(QPainter& painter) = 0;
    QColor getColor(int iterations, int maxIterations);
};