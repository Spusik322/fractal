#pragma once

#include "fractalwidget.h"

class Julia : public FractalWidget {
public:
    explicit Julia(QWidget *parent = nullptr);
    
protected:
    void generateFractal(QPainter& painter) override;
};
