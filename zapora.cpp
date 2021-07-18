#include "zapora.h"
#include "przeszkoda.h"
#include "gra.h"
#include <stdlib.h>
#include <QTimer>
extern Gra * gra;
Zapora::Zapora()
{
    setPixmap(QPixmap(":/img/img/zapora.png"));
    QTimer *sprawdz=new QTimer();
    connect(sprawdz,SIGNAL(timeout()),this,SLOT(sprawdz()));
    sprawdz->start(150);
}

void Zapora::sprawdz()
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
}
