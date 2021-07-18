#ifndef OBIEKT_H
#define OBIEKT_H
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QObject>

class Gracz:public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
 public:
    void keyPressEvent(QKeyEvent *event);
    Gracz();
 public slots:
    void przeciwnicy();
    void nowy_przeciwnik();
    void sprawdz_zdrowie();
    void koniec();
    void nowa_zapora();
    void nowe_zdrowie();
   };
#endif // OBIEKT_H
