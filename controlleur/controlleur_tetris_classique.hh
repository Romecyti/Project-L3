#pragma once
#include "controlleur.hh"
#include "../model/jeu/tetrisclassique.hh"

#include"../vue/vue_tetris_c.h"

class ControlleurTetrisClassique:public Controlleur
{
private:
    TetrisClassique * _modele;
    VueTetrisC _vue;


    NIVEAU _n;
    Position _taille;
    SetDePiece _Setpiece;

public:
    ControlleurTetrisClassique(NIVEAU n,SetDePiece Sp,Position p,NonAlterableSettings set,QWidget * ptr=nullptr );
    QWidget * GetVue()  ;
    virtual ~ControlleurTetrisClassique()override;
    Q_OBJECT
public slots:

    void Lancer();
    void Rotation(DIRECTION_ROT d);
    void Deplacement(DIRECTION_MOUVEMENT d);

    void Pause();
    void Reset();
    void RetourMenu();
    void UseReserve();
    virtual void ChangeControlleur() override;
   // void ChangeDifficulté(NIVEAU n,Position p);


    void AboutPlateau(Matrice3D & m);
    void AboutReserve(std::unique_ptr<Piece> & res);
    void ReserveState(bool &b);

    void AboutSuivant(std::vector<std::unique_ptr<Piece>>& suiv);

   void  AboutPieceActuelle(std::unique_ptr<Piece> &p) ;
    void AboutPositionPieceActuelle(Position &p);

   void AboutScore( int & n);
    void  AboutNiveau(int & n);
    void  AboutNbEtageDetruits(int & n);
    void JeuPause(bool &b);
    void JeuFinit(bool & b);


signals:
    void RetourAuMenu();

};

