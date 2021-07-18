#ifndef PRZESZKODA_H
#define PRZESZKODA_H
#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsPixmapItem>

class Przeszkoda :public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
   public:
       Przeszkoda();
       void set_position(int x,int y);
   public slots:
      void ruch();
   };
#endif // PRZESZKODA_H
