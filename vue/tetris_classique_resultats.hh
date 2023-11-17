#pragma once

#include <QtWidgets>
//#include<QLayout>

class TetrisClassiqueResultats : public QWidget
{
    Q_OBJECT
public:
    TetrisClassiqueResultats(QWidget *parent = nullptr);
    ~TetrisClassiqueResultats();
    void Resultat(int points , int etages);
private:
     QVBoxLayout *_Vlay;

     QLabel *_titre;
    // QVBoxLayout *_Vlay2;
     QLabel * _points;
     QLabel * _etages;

     QHBoxLayout *_Hlay;
     QPushButton * _reset;
     QPushButton * _Quit;




signals:
      void Rejouer();
      void Quitter();

public slots:

};

