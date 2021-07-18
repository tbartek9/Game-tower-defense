#ifndef WYNIK_H
#define WYNIK_H
#include <QGraphicsTextItem>
class Wynik:public QGraphicsTextItem{
    public:
    int wynik;
    void dodaj();
    Wynik();
};

#endif // WYNIK_H
