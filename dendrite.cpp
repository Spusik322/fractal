#define _USE_MATH_DEFINES
#include "dendrite.h"
#include <cmath>
#include <QRandomGenerator>

Dendrite::Dendrite(QWidget *parent) 
    : FractalWidget(parent) {}

void Dendrite::generateFractal(QPainter &painter) {
    const int iterations = 100000;
    const double angle = M_PI / 3.0;
    
    double x = 0.5 * width();
    double y = 0.5 * height();
    
    painter.fillRect(rect(), Qt::black);
    painter.setPen(Qt::white);
    
    for(int i = 0; i < iterations; i++) {
        int choice = QRandomGenerator::global()->bounded(3);
        
        switch(choice) {
            case 0:
                x = x / 2.0;
                y = y / 2.0;
                break;
            case 1:
                x = (x + width()) / 2.0;
                y = y / 2.0;
                break;
            case 2:
                x = x / 2.0 + 0.25 * width() * cos(angle);
                y = (y + height()) / 2.0 + 0.25 * height() * sin(angle);
                break;
        }
        
        painter.drawPoint(x, y);
    }
}