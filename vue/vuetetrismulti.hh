#pragma once
#include "opengl_tetrisc.hh"
#include"resultattetrismulti.hh"
class VueTetrisMulti:public QStackedWidget
{
    Q_OBJECT
public:
    VueTetrisMulti(NonAlterableSettings set, QWidget *parent=nullptr);

     const TetrisClassiqueOpenGl &GetJeu1()const;
     const TetrisClassiqueOpenGl &GetJeu2()const;
     const ResultatTetrisMulti &GetResult()const;
     void reset();
public slots:
      void EcranResultat();

private:

    QWidget w;
    TetrisClassiqueOpenGl _joueur1;
    TetrisClassiqueOpenGl _joueur2;
    QHBoxLayout _lay;

    ResultatTetrisMulti _resultat;
    bool _alreadyfinish;

    NonAlterableSettings _options;
    std::vector<bool> _InputPressed;


    QMediaPlaylist _ploop;
    QMediaPlayer _lecteur;
   void resetKeys();
   virtual void keyPressEvent(QKeyEvent *e) override;
   virtual void keyReleaseEvent(QKeyEvent *e) override;

signals:

   void nbEtagesDetruit(int & j1 , int & j2);
   void resultat(int & j1, int &j2);
   void Jeu1fini(bool & b);
   void Jeu2fin(bool & b);
};
