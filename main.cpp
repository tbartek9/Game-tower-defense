#include <QApplication>
#include <gra.h>
#include <QDir>
Gra *gra;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    gra=new Gra();
    return a.exec();
}
