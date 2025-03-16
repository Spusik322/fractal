#include "mandelbrot.h"

Mandelbrot::Mandelbrot(QWidget *parent) : FractalWidget(parent) {}

void Mandelbrot::generateFractal(QPainter &painter) {
    const int maxIterations = 100;
    const double zoom = 300.0;
    const double offsetX = -width()/2.0;
    const double offsetY = -height()/2.0;

    for(int y = 0; y < height(); y++) {
        for(int x = 0; x < width(); x++) {
            std::complex<double> c(
                (x + offsetX) / zoom,
                (y + offsetY) / zoom
            );
            
            std::complex<double> z(0, 0);
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