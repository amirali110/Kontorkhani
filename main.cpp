#include "mainwindow.h"
#include <QApplication>
#include <QHBoxLayout>
#include <QComboBox>
#include <QDialog>


int main(int argc, char *argv[])
{
QApplication a(argc, argv);

    MainWindow w;
    w.show();
    return a.exec();
}

