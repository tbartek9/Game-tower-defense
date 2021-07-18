#include "zapora_ilosc.h"
#include <QFont>
Zapora_ilosc::Zapora_ilosc()
{
    zapory=10;
    setPlainText(QString("Ilość zapór: ") +QString::number(zapory));
    setDefaultTextColor(Qt::yellow);
    setFont(QFont("times",16));
}
