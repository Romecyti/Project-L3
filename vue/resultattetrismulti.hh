#pragma once
#include <QtWidgets>


enum class Gagnant{J1,J2};
class ResultatTetrisMulti : public QWidget
{
    Q_OBJECT
public:
    ResultatTetrisMulti(QWidget *parent = nullptr);
    ~ResultatTetrisMulti();
    void Resultat(int points1 , int etage1 ,int points2 , int etage2 ,Gagnant g);
private:


    QVBoxLayout * _Main_Vlay;


    QLabel * _titre;

    QHBoxLayout * _joueurscore_Hlay;
    QVBoxLayout * _J1_Vlay;
    QLabel * _J1;
    QLabel * _pointJ1;
    QLabel * _NbetageJ1;

    QVBoxLayout * _J2_Vlay;
    QLabel * _J2;
    QLabel * _pointJ2;
    QLabel * _NbetageJ2;


    QLabel * _gagnant;



     QHBoxLayout * _Hbuttonlay;
     QPushButton * _reset;
     QPushButton * _Quit;




signals:
      void Rejouer();
      void Quitter();


public slots:

};

