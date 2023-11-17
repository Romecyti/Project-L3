#include "p_z3d.hh"


const Position P_Z3d::defaultSizeOfZ3d = {3,2,3};



P_Z3d::P_Z3d(couleur c): Piece(P_Z3d::defaultSizeOfZ3d,c){
//on va ensuite venir placer un à un les cube de la forme
   //on en créer un de la bonne couleur
    Cube cub(c);
    _matrice.Ajout(c,{2,0,1});
    _matrice.Ajout(c,{1,0,1});
    _matrice.Ajout(c,{1,1,1});
    _matrice.Ajout(c,{0,1,1});
    _matrice.Ajout(c,{1,0,0});
    _matrice.Ajout(c,{1,1,2});
}

P_Z3d &P_Z3d::operator=(const P_Z3d &p)
{
    Piece::operator=(p);
    return *this;
}

std::unique_ptr<Piece> P_Z3d::clone() const
{
    return std::make_unique<P_Z3d>(P_Z3d(*this));
}



