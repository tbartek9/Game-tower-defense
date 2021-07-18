#include "gracz_zdrowie.h"
#include <QFont>
#include"gra.h"
extern Gra * gra;
Gracz_zdrowie::Gracz_zdrowie()
{
    zdrowie=100;
    setPlainText(QString("Zdrowie: ") +QString::number(zdrowie));
    setDefaultTextColor(Qt::green);
    setFont(QFont("times",16));
}

void Gracz_zdrowie::odejmij()
{
    zdrowie-=2;
    if(zdrowie>=0){
    setPlainText(QString("Zdrowie: ") +QString::number(zdrowie));
    }
}

void Gracz_zdrowie::dodaj()
{   if(zdrowie>80){
    zdrowie=100;
    }
    else if(zdrowie<=80){
    zdrowie+=20;
    }
    setPlainText(QString("Zdrowie: ") +QString::number(zdrowie));
}
