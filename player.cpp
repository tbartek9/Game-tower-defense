#include "player.h"
#include "przeszkoda.h"
#include "pocisk.h"
#include "gra.h"
#include "zapora.h"
#include "nowa_zapora.h"
#include "nowe_zdrowie.h"
#include <QKeyEvent>
#include <QList>
#include <QDebug> //qDebug()<<"";
#include <QGraphicsScene>
#include <QTimer>
#include <stdlib.h>
int ax;
extern Gra * gra;

void Gracz::keyPressEvent(QKeyEvent *event)//poruszanie obiektem
{
     QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
   if (typeid(*(colliding_items[0])) == typeid(Nowa_zapora)){
            gra->zapora_ilosc->zapory++;
            gra->zapora_ilosc->setPlainText(QString("Ilość zapór: ") +QString::number(gra->zapora_ilosc->zapory));
            scene()->removeItem(colliding_items[0]);
            delete colliding_items[0];
     }
   }

    QList<QGraphicsItem *> colliding_itemsX = collidingItems();
   for (int i = 0, n = colliding_itemsX.size(); i < n; ++i){
  if (typeid(*(colliding_itemsX[0])) == typeid(Nowe_zdrowie)){
           gra->gracz_zdrowie->dodaj();
           scene()->removeItem(colliding_itemsX[0]);
           delete colliding_items[0];
    }
  }





    if(event->key()==Qt::Key_Left && pos().x() >0)
       { setPos(x()-10,y());
    }
    else if(event->key()==Qt::Key_Right && pos().x()<770)
       { setPos(x()+10,y());
    }
    else if(event->key()==Qt::Key_Up && pos().y() > 0)
       { setPos(x(),y()-10);
    }
    else if(event->key()==Qt::Key_Down && pos().y() < 570)
       { setPos(x(),y()+10);
    }
        else if(event->key()== Qt::Key_Space){
        Pocisk * pocisk =new Pocisk();
        scene()->addItem(pocisk);
        pocisk->setPos(x(),y()-15);
    }
        else if(event->key()== Qt::Key_Enter && gra->zapora_ilosc->zapory >0){
        Zapora * zapora=new Zapora();
        zapora->setPos(x(),y());
        scene()->addItem(zapora);
        gra->zapora_ilosc->zapory--;
        gra->zapora_ilosc->setPlainText(QString("Ilość zapór: ") +QString::number(gra->zapora_ilosc->zapory));
    }

}

Gracz::Gracz()
{
    setPixmap(QPixmap(":/img/img/player.png"));
    QTimer *czas=new QTimer();
    connect(czas,SIGNAL(timeout()),this,SLOT(przeciwnicy()));
    czas->start(4500);

    QTimer *czas_zdrowie=new QTimer();
    connect(czas_zdrowie,SIGNAL(timeout()),this,SLOT(sprawdz_zdrowie()));
    czas_zdrowie->start(500);

    QTimer *koniec=new QTimer();
    connect(koniec,SIGNAL(timeout()),this,SLOT(koniec()));
    koniec->start(100);

    QTimer *zapora=new QTimer();
    connect(zapora,SIGNAL(timeout()),this,SLOT(nowa_zapora()));
    zapora->start(8000);

    QTimer *nowe_zdr=new QTimer();
    connect(nowe_zdr,SIGNAL(timeout()),this,SLOT(nowe_zdrowie()));
    nowe_zdr->start(15000);
}

void Gracz::przeciwnicy()
{
    if(gra->czas->czas<=10 ){
        nowy_przeciwnik();
    }
    if(gra->czas->czas>10 && gra->czas->czas<35){
        nowy_przeciwnik();
        QTimer *przeciwnik=new QTimer();
        connect(przeciwnik,SIGNAL(timeout()),this,SLOT(nowy_przeciwnik()));
        przeciwnik->start(15000);
    }
    if(gra->czas->czas>=35 && gra->czas->czas<55){
        nowy_przeciwnik();
        QTimer *przeciwnik=new QTimer();
        connect(przeciwnik,SIGNAL(timeout()),this,SLOT(nowy_przeciwnik()));
        przeciwnik->start(25000);
    }
    if(gra->czas->czas>=55 && gra->czas->czas<85){
        QTimer *przeciwnik=new QTimer();
        connect(przeciwnik,SIGNAL(timeout()),this,SLOT(nowy_przeciwnik()));
        przeciwnik->start(25000);
    }
    if(gra->czas->czas>=85 && gra->czas->czas<105){
        QTimer *przeciwnik=new QTimer();
        connect(przeciwnik,SIGNAL(timeout()),this,SLOT(nowy_przeciwnik()));
        przeciwnik->start(25000);
    }
    if(gra->czas->czas>=105){
        QTimer *przeciwnik=new QTimer();
        connect(przeciwnik,SIGNAL(timeout()),this,SLOT(nowy_przeciwnik()));
        przeciwnik->start(25000);
    }



}

void Gracz::nowy_przeciwnik()
{
    if(gra->sprawdz_koniec!=1){
    ax=rand() % 550;
    Przeszkoda *prz=new Przeszkoda();
    prz->setPos(ax,0);
    prz->setPixmap(QPixmap(":/img/img/przeszkoda.png"));
    scene()->addItem(prz);
    }
}

//void Gracz::przeciwnicy()
//{

    //   ax=rand() % 550;
    //   Przeszkoda *prz=new Przeszkoda();
    //   prz->setPos(ax,0);
     //  prz->setPixmap(QPixmap(":/img/img/przeszkoda.png"));
     //  scene()->addItem(prz);

//}
void Gracz::sprawdz_zdrowie()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
  if (typeid(*(colliding_items[0])) == typeid(Przeszkoda)){
           gra->gracz_zdrowie->odejmij();
           if(gra->gracz_zdrowie->zdrowie<=0){
               setPixmap(QPixmap(":/img/img/player0.png"));
               gra->sprawdz_koniec=1;
           }
    }
    }
}

void Gracz::koniec()
{
    gra->sprawdz();
}

void Gracz::nowa_zapora()
{
    if(gra->sprawdz_koniec!=1){
    Nowa_zapora * nowa_zapora=new Nowa_zapora();
    scene()->addItem(nowa_zapora);
    }
}

void Gracz::nowe_zdrowie()
{
    if(gra->sprawdz_koniec!=1){
    Nowe_zdrowie * nowe_zdrowie=new Nowe_zdrowie();
    scene()->addItem(nowe_zdrowie);
    }
}
