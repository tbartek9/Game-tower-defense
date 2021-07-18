#include "wynik.h"
#include "gra.h"
#include <QFont>
#include <QDebug>
extern Gra * gra;
void Wynik::dodaj()
{
    if(gra->sprawdz_koniec!=1){
    wynik++;
    qDebug()<<"wynik+";
    setPlainText(QString("Score: ") +QString::number(wynik));
    }
}

Wynik::Wynik()
{
   wynik=0;
   setPlainText(QString("Score: ") +QString::number(wynik));
   setDefaultTextColor(Qt::red);
   setFont(QFont("times",16));

}
