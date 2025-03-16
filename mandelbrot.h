#pragma once

#include "fractalwidget.h"

class Mandelbrot : public FractalWidget {
public:
    explicit Mandelbrot(QWidget *parent = nullptr);
    
protected:
    void generateFractal(QPainter& painter) override;
};
