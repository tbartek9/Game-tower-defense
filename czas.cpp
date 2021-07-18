#include "czas.h"
#include "gra.h"
#include <QTimer>
extern Gra * gra;
Czas::Czas()
{
    czas=0;
    setPlainText(QString("Czas: ") +QString::number(czas));
    setDefaultTextColor(Qt::black);
    setFont(QFont("times",16));
    QTimer *czas=new QTimer();
    connect(czas,SIGNAL(timeout()),this,SLOT(czas_leci()));
    czas->start(1000);
}

void Czas::czas_leci()
{
    czas+=1;
    if(gra->sprawdz_koniec!=1){
    setPlainText(QString("Czas: ") +QString::number(czas));
    czas_koniec=czas;
    }
}
