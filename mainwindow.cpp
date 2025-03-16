#include "mainwindow.h"
#include "mandelbrot.h"
#include "julia.h"
#include "dendrite.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    QTabWidget *tabWidget = new QTabWidget(this);
    setCentralWidget(tabWidget);
    
    tabWidget->addTab(new Mandelbrot(), "Mandelbrot");
    tabWidget->addTab(new Julia(), "Julia Set");
    tabWidget->addTab(new Dendrite(), "Dendrite");
    
    resize(800, 600);
    setWindowTitle("Fractal Explorer");
}