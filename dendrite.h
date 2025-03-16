#pragma once

#include "fractalwidget.h"

class Dendrite : public FractalWidget {
public:
    explicit Dendrite(QWidget *parent = nullptr);
    
protected:
    void generateFractal(QPainter& painter) override;
};
