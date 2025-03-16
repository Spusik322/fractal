#include "julia.h"

Julia::Julia(QWidget *parent)
    : FractalWidget(parent) {}

void Julia::generateFractal(QPainter &painter) {
    const int maxIterations = 100;
    const double zoom = 400.0;
    const double offsetX = -width()/2.0;
    const double offsetY = -height()/2.0;
    const std::complex<double> c(-0.4, 0.6);

    for(int y = 0; y < height(); y++) {
        for(int x = 0; x < width(); x++) {
            std::complex<double> z(
                (x + offsetX) / zoom,
                (y + offsetY) / zoom
            );
            
            int iterations = 0;
            while(std::abs(z) < 2.0 && iterations < maxIterations) {
                z = z * z + c;
                iterations++;
            }
            
            painter.setPen(getColor(iterations, maxIterations));
            painter.drawPoint(x, y);
        }
    }
}