#ifndef POCISK_H
#define POCISK_H
#include <QGraphicsPixmapItem>
#include <QObject>

class Pocisk:public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Pocisk();
public slots:
    void ruch();
};
#endif // POCISK_H
