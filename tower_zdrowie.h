#ifndef TOWER_ZDROWIE_H
#define TOWER_ZDROWIE_H
#include <QGraphicsTextItem>
class Tower_zdrowie:public QGraphicsTextItem{
public:
    int zdrowie;
    Tower_zdrowie();
    void odejmij();
};

#endif // TOWER_ZDROWIE_H
