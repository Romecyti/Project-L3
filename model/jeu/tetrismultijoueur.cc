#include "tetrismultijoueur.hh"

void TetrisMultijoueur::AjouteCarre()
{
    if(this->getplateau().AjoutCarre())
   {
        this->Setfinit(true);
    }


       auto p=this->GetPieceActuelle();
       this->SetPositionPieceActuelle(Position{p->pos._x,p->pos._y+1,p->pos._y});
       auto p2=this->GetPositionPieceActuelle();


       if(this->getplateau().Intersection(*p->piece,p2))
       {
           this->Setfinit(true);
       }

}


TetrisMultijoueur::TetrisMultijoueur(NIVEAU n, SetDePiece Sp, Position taille, QObject * ptr):TetrisClassique (n,Sp,taille,ptr)
{

}


void TetrisMultijoueur::ReceptionCarre(int nbl)
{
 for(int i(1);i<=nbl;i++)
     this->AjouteCarre();
}

void TetrisMultijoueur::SupprimerCarrePlein()
{
    unsigned int nbcarresupprime = this->getplateau().SupprimeCarrePlein();

    switch (nbcarresupprime)
    {
    case 0: //on ne modifie pas le score
        break;
    case 1:
        _nbPoint += 100;
        break;
    case 2:
        _nbPoint += 250;
        emit EnvoieLigne(1);
        break;
    case 3:
        _nbPoint += 600;
         emit EnvoieLigne(2);
        break;
    default: //4 et plus (normalement jamais autant car pièce la plus grande est de 4 de hauteur)
        _nbPoint += 1500;
         emit EnvoieLigne(4);
        break;
    }

    _nbEtagesDetruits+=nbcarresupprime;

    if(_nbEtagesDetruits >= 8 * (pow(2,_niveau)))
        IncrementeNiveau();
}

