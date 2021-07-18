#ifndef GRACZ_ZDROWIE_H
#define GRACZ_ZDROWIE_H
#include <QGraphicsTextItem>
class Gracz_zdrowie:public QGraphicsTextItem{

public:
    int zdrowie;
    Gracz_zdrowie();
    void odejmij();
    void dodaj();

};

#endif // GRACZ_ZDROWIE_H
