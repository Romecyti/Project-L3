#pragma once
#include"tetrisclassique.hh"



class TetrisMultijoueur:public TetrisClassique
{
    Q_OBJECT
private:
    void AjouteCarre();
public:
    TetrisMultijoueur(NIVEAU n,SetDePiece Sp,Position taille,QObject * ptr=nullptr);


    virtual ~TetrisMultijoueur()override=default;

    virtual void SupprimerCarrePlein()override;


public slots:
    void ReceptionCarre(int nbl);
signals:
   void EnvoieLigne(int nbl);
};

