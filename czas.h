#ifndef CZAS_H
#define CZAS_H
#include <QGraphicsTextItem>
class Czas:public QGraphicsTextItem{
    Q_OBJECT
public:
    int czas;
    int czas_koniec;
    Czas();
public slots:
    void czas_leci();

};

#endif // CZAS_H
