#include "pocisk.h"
#include "przeszkoda.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug> //qDebug()<<"";
#include "gra.h"
extern Gra * gra;

Pocisk::Pocisk()
{
    setPixmap(QPixmap(":/img/img/pocisk.png"));
    QTimer *czas=new QTimer();
    connect(czas,SIGNAL(timeout()),this,SLOT(ruch()));
    czas->start(300);
}

void Pocisk::ruch()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
     for (int i = 0, n = colliding_items.size(); i < n; ++i){
      if (typeid(*(colliding_items[0])) == typeid(Przeszkoda)){
              gra->wynik->dodaj();
              scene()->removeItem(colliding_items[0]);
              scene()->removeItem(this);
              delete colliding_items[0];
              delete this;
              return;
       }
    }
    setPos(x(),y()-7);
    if( pos().y()<0){
        scene()->removeItem(this);
        delete this;
    }
}
