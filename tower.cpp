#include "tower.h"
#include "gra.h"
#include "przeszkoda.h"
#include <QTimer>
#include <QKeyEvent>
#include <QApplication>
extern Gra * gra;

void Tower::keyPressEvent(QKeyEvent *event){

;
}

Tower::Tower()
{
    setPixmap(QPixmap(":/img/img/tower.png"));
    QTimer *czas_zdrowie=new QTimer();
    connect(czas_zdrowie,SIGNAL(timeout()),this,SLOT(sprawdz_zdrowie()));
    czas_zdrowie->start(500);
}


void Tower::sprawdz_zdrowie()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
     for (int i = 0, n = colliding_items.size(); i < n; ++i){
      if (typeid(*(colliding_items[0])) == typeid(Przeszkoda)){
              gra->tower_zdrowie->odejmij();
              if(gra->tower_zdrowie->zdrowie<=80){
                  ;
               //  setPixmap(QPixmap(":/img/img/tower80.png"));
              }
              if(gra->tower_zdrowie->zdrowie<=60){
                  ;
                  //setPixmap(QPixmap(":/img/img/tower60.png"));
              }
              if(gra->tower_zdrowie->zdrowie<=40){
                  ;
                 // setPixmap(QPixmap(":/img/img/tower40.png"));
              }
              if(gra->tower_zdrowie->zdrowie<=20){
                  ;
                 // setPixmap(QPixmap(":/img/img/tower20.png"));
              }
              if(gra->tower_zdrowie->zdrowie<=0){
                  gra->sprawdz_koniec=1;
                  //setPixmap(QPixmap(":/img/img/tower0.png"));
              }
       }
}
}
