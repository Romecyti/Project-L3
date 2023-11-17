#include "p_z.hh"


const Position P_Z::defaultSizeOfZ = {3,2,1};



P_Z::P_Z(couleur c): Piece(P_Z::defaultSizeOfZ,c){
//on va ensuite venir placer un à un les cube de la forme
   //on en créer un de la bonne couleur
    Cube cub(c);
    _matrice.Ajout(c,{2,0,0});
    _matrice.Ajout(c,{1,0,0});
    _matrice.Ajout(c,{1,1,0});
    _matrice.Ajout(c,{0,1,0});
}

P_Z &P_Z::operator=(const P_Z &p)
{
    Piece::operator=(p);
    return *this;
}

std::unique_ptr<Piece> P_Z::clone() const
{
    return std::make_unique<P_Z>(P_Z(*this));
}



