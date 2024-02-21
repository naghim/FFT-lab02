#include "mainwindow.h"

#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // UI komponensek létrehozása
    this->window = new QWidget;
    this->label = new QLabel("Hello GUI World!");
    this->button = new QPushButton("Quit!");
    this->layout = new QVBoxLayout;

    // elemek elrendezése layoutba
    this->layout->addWidget(this->label);
    this->layout->addWidget(this->button);

    // ha a gombra kattint a felhasználó, akkor az applikáció álljon le
    QObject::connect(this->button, SIGNAL(clicked()), QApplication::instance(), SLOT(quit()));

    // az ablak nevének beállítása
    this->setWindowTitle("Quit Button");

    // jelenítsük meg az elemeket a felületen
    this->window->setLayout(layout);
    this->setCentralWidget(window);
}
