#ifndef ZAPORA_H
#define ZAPORA_H
#include <QGraphicsPixmapItem>
class Zapora:public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Zapora();
public slots:
    void sprawdz();
};
#endif // ZAPORA_H
