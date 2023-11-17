#pragma once
#include<QtWidgets>
#include"opengl_tetrisc.hh"
#include"tetris_classique_resultats.hh"
class VueTetrisC : public QStackedWidget
{

  Q_OBJECT
private:

    TetrisClassiqueOpenGl _jeu;
    TetrisClassiqueResultats _resultat;
    NonAlterableSettings _options;

    void resetKeys();

   std::vector<bool> _InputPressed;
   virtual void keyPressEvent(QKeyEvent *e) override;
   virtual void keyReleaseEvent(QKeyEvent *e) override;

   QMediaPlaylist _ploop;
    QMediaPlayer _lecteur;

public:
    VueTetrisC(NonAlterableSettings set, QWidget *parent=nullptr);
    const TetrisClassiqueOpenGl &GetJeu()const;
    const TetrisClassiqueResultats &GetResultat()const;
    void reset();



signals:
    void AboutNbEtageDetruit(int & n);

public slots:

    void Ecranresultat(int p );



};

