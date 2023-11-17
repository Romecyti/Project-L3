#include "p_t3d.hh"


const Position P_T3d::defaultSizeOfT = {3,2,3};



P_T3d::P_T3d(couleur c): Piece(P_T3d::defaultSizeOfT,c){
//on va ensuite venir placer un à un les cube de la forme
   //on en créer un de la bonne couleur
    Cube cub(c);
    _matrice.Ajout(c,{1,0,1});
    _matrice.Ajout(c,{0,1,1});
    _matrice.Ajout(c,{1,1,1});
    _matrice.Ajout(c,{2,1,1});
    _matrice.Ajout(c,{1,1,0});
    _matrice.Ajout(c,{1,1,2});
}

P_T3d &P_T3d::operator=(const P_T3d &p)
{
    Piece::operator=(p);
    return *this;
}

std::unique_ptr<Piece> P_T3d::clone() const
{
    return std::make_unique<P_T3d>(P_T3d(*this));
}



