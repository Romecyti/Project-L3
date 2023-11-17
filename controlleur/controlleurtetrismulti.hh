#pragma once
#include"controlleur.hh"
#include"../model/jeu/tetrismultijoueur.hh"
#include"../vue/vuetetrismulti.hh"

class ControlleurTetrisMulti:public Controlleur
{
        Q_OBJECT
private:
    TetrisMultijoueur * _modele1;
    TetrisMultijoueur * _modele2;
    VueTetrisMulti _vue;

    NIVEAU _n;
    Position _taille;
    SetDePiece _Setpiece;
public:
    ControlleurTetrisMulti(NIVEAU n,SetDePiece Sp,Position p,NonAlterableSettings set,QWidget * ptr=nullptr);
    QWidget *GetVue()  ;
    virtual ~ControlleurTetrisMulti()override;

public slots:
    virtual void ChangeControlleur() override;
    void EnvoieCarreM1toM2(int nbl);
    void EnvoieCarreM2toM1(int nbl);

    void Pause();
    void LancerM1();
    void LancerM2();

     void JeuFinit(bool & b);
     void jeu1fini(bool & b);
     void jeu2finit(bool & b);
     void JeuPause(bool &b);
     void AboutPlateauM1(Matrice3D & m);
     void AboutPlateauM2(Matrice3D & m);

     void AboutReserveM1(std::unique_ptr<Piece> & res);
     void ReserveStateM1(bool &b);
     void AboutReserveM2(std::unique_ptr<Piece> & res);
     void ReserveStateM2(bool &b);

     void AboutSuivantM1(std::vector<std::unique_ptr<Piece>>& suiv);
     void AboutSuivantM2(std::vector<std::unique_ptr<Piece>>& suiv);

     void  AboutPieceActuelleM1(std::unique_ptr<Piece> &p) ;
     void  AboutPositionPieceActuelleM1(Position &p);
     void  AboutPieceActuelleM2(std::unique_ptr<Piece> &p) ;
     void  AboutPositionPieceActuelleM2(Position &p);

     void AboutScoreM1( int & n);
     void AboutNiveauM1(int & n);
     void AboutNbEtageDetruitsM1(int & n);//--
     void AboutScoreM2( int & n);
     void AboutNiveauM2(int & n);
     void AboutNbEtageDetruitsM2(int & n);//--

     void UseReserveM1();
     void RotationM1(DIRECTION_ROT d);
     void DeplacementM1(DIRECTION_MOUVEMENT d);
     void UseReserveM2();
     void RotationM2(DIRECTION_ROT d);
     void DeplacementM2(DIRECTION_MOUVEMENT d);

     void GetScores(int & j1 , int & j2);
     void GetNbEtages(int & j1 ,int & j2);

      void RetourMenu();
      void Reset();

signals:
      void RetourAuMenu();
/*

   ;
   void RetourMenu();



   // void ChangeDifficulté(NIVEAU n,Position p);

*/
};

