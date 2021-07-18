#ifndef TOWER_H
#define TOWER_H
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QObject>
class Tower:public QObject,public QGraphicsPixmapItem{
     Q_OBJECT
public:
    Tower();
    void keyPressEvent(QKeyEvent *event);
public slots:
    void sprawdz_zdrowie();
   };
#endif // TOWER_H
