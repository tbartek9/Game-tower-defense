#include "tower_zdrowie.h"
#include <QFont>
#include"gra.h"
extern Gra * gra;
Tower_zdrowie::Tower_zdrowie()
{
    zdrowie=100;
    setPlainText(QString("Kondycja zamku: ") +QString::number(zdrowie));
    setDefaultTextColor(Qt::yellow);
    setFont(QFont("times",16));
}

void Tower_zdrowie::odejmij()
{
    zdrowie-=2;
    if(zdrowie>=0){
    setPlainText(QString("Kondycja zamku: ") +QString::number(zdrowie));
    }
}
