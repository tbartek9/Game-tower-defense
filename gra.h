#ifndef GRA_H
#define GRA_H
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "player.h"
#include "tower.h"
#include "wynik.h"
#include "tower_zdrowie.h"
#include "gracz_zdrowie.h"
#include "czas.h"
#include "zapora_ilosc.h"
#include <QObject>
#include <QGraphicsTextItem>
class Gra:public QGraphicsView{
     Q_OBJECT
public:
    void sprawdz();
    Gra(QGraphicsItem * parent=0);
       QGraphicsScene * scene;
       Gracz * gracz;
       Tower * tower;
       Wynik * wynik;
       Gracz_zdrowie * gracz_zdrowie;
       Tower_zdrowie * tower_zdrowie;
       Zapora_ilosc * zapora_ilosc;
       Czas * czas;
       QGraphicsTextItem * koniec;
       QGraphicsTextItem * koniec_wynik;
       QGraphicsTextItem * koniec_czas;
       QGraphicsTextItem * best;
       int sprawdz_koniec;
};
#endif // GRA_H
