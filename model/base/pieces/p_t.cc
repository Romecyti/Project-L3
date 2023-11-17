#include "p_t.hh"


const Position P_T::defaultSizeOfT = {3,2,1};



P_T::P_T(couleur c): Piece(P_T::defaultSizeOfT,c){
//on va ensuite venir placer un à un les cube de la forme
   //on en créer un de la bonne couleur
    Cube cub(c);
    _matrice.Ajout(c,{1,0,0});
    _matrice.Ajout(c,{0,1,0});
    _matrice.Ajout(c,{1,1,0});
    _matrice.Ajout(c,{2,1,0});
}

P_T &P_T::operator=(const P_T &p)
{
    Piece::operator=(p);
    return *this;
}

std::unique_ptr<Piece> P_T::clone() const
{
    return std::make_unique<P_T>(P_T(*this));
}



