#include "nowa_zapora.h"
#include <stdlib.h>
Nowa_zapora::Nowa_zapora()
{
    setPixmap(QPixmap(":/img/img/nowa_zapora.png"));
    int x=rand() % 760 + 20;
    int y=rand() % 500 + 40;
    setPos(x,y);
}
