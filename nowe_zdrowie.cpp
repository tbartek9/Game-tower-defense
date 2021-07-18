#include "nowe_zdrowie.h"
#include <stdlib.h>
Nowe_zdrowie::Nowe_zdrowie()
{
    setPixmap(QPixmap(":/img/img/nowe_zdrowie.png"));
    int x=rand() % 760 + 20;
    int y=rand() % 500 + 40;
    setPos(x,y);
}
