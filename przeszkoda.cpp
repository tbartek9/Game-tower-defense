#include "przeszkoda.h"
#include <QObject>
#include <QTimer>
#include "player.h"
#include <QList>
#include <QDebug>
#include <QGraphicsScene>
#include"gra.h"

extern Gra * gra;
int aw,ay;

Przeszkoda::Przeszkoda(): QObject(), QGraphicsPixmapItem()
{
    set_position(aw,ay);
    QTimer *czas=new QTimer();
    connect(czas,SIGNAL(timeout()),this,SLOT(ruch()));
    czas->start(250);
}

void Przeszkoda::set_position(int x, int y)
{
    setPos(x,y);
}

void Przeszkoda::ruch()
{
    if(gra->sprawdz_koniec!=1){
    setPos(x(),y()+8);
    }
    if(pos().y()>640){
    qDebug() <<"delete";
    scene()->removeItem(this);
    delete this;
    }
}



