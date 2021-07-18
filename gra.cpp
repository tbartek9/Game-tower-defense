#include "gra.h"
#include <QTimer>
#include <QFont>
#include <fstream>
using namespace std;

int best1;
fstream plik;
Gra::Gra(QGraphicsItem *parent)
{

    plik.open("best.txt", ios::in | ios::out);
    if( plik.good() == true )
        {
            plik >> best1;
            plik.close();
        }
    scene=new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setFixedSize(800,600);
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    gracz =new Gracz();
    tower =new Tower();
    wynik =new Wynik();
    best =new QGraphicsTextItem();
    best->setPlainText(QString("Reokrd: ")+QString::number(best1)+QString("pkt"));
    gracz_zdrowie=new Gracz_zdrowie();
    tower_zdrowie=new Tower_zdrowie();
    zapora_ilosc= new Zapora_ilosc();
    czas=new Czas();
    gracz->setFlag(Gracz::ItemIsFocusable);
    gracz->setFocus();
    gracz->setPixmap(QPixmap(":/img/img/player.png"));
    tower->setPixmap(QPixmap(":/img/img/tower.png"));
    scene->addItem(gracz);
    scene->addItem(tower);
    scene->addItem(wynik);
    scene->addItem(gracz_zdrowie);
    scene->addItem(tower_zdrowie);
    scene->addItem(zapora_ilosc);
    scene->addItem(czas);
    scene->addItem(best);
    gracz->setPos(200,200);
    tower->setPos(0,540);
    wynik->setPos(0,0);
    gracz_zdrowie->setPos(0,20);
    tower_zdrowie->setPos(0,40);
    zapora_ilosc->setPos(0,60);
    czas->setPos(0,80);
    best->setPos(730,0);
    show();
}



void Gra::sprawdz()
{
    if(sprawdz_koniec==1){
        koniec=new QGraphicsTextItem();
        koniec->setPlainText(QString("KONIEC GRY "));
        koniec->setDefaultTextColor(Qt::black);
        koniec->setFont(QFont("arial",36));
        koniec_czas=new QGraphicsTextItem();
        koniec_czas->setPlainText(QString("CZAS: ")+QString::number(czas->czas_koniec)+QString("s"));
        koniec_czas->setDefaultTextColor(Qt::black);
        koniec_czas->setFont(QFont("arial",36));
        koniec_wynik=new QGraphicsTextItem();
        koniec_wynik->setPlainText(QString("TWÓJ WYNIK ")+QString::number(wynik->wynik)+QString("pkt"));
        koniec_wynik->setDefaultTextColor(Qt::black);
        koniec_wynik->setFont(QFont("arial",36));
        scene->addItem(koniec);
        scene->addItem(koniec_czas);
        scene->addItem(koniec_wynik);
        koniec->setPos(200,150);
        koniec_czas->setPos(200,200);
        koniec_wynik->setPos(200,250);

        if(wynik->wynik>best1){
        best1=wynik->wynik;
        best->setPlainText(QString("Reokrd: ")+QString::number(best1)+QString("pkt"));
        QGraphicsTextItem *rekord=new QGraphicsTextItem();
        rekord->setPlainText(QString("NOWY REKORD!"));
        rekord->setDefaultTextColor(Qt::red);
        rekord->setFont(QFont("arial",36));
        scene->addItem(rekord);
        rekord->setPos(200,300);

        plik.open("best.txt", ios::trunc | ios::in | ios::out);
        if( plik.good() == true )
            {
                plik << best1;
                plik.close();
            }
        }
    } //koniec konca gry
}
