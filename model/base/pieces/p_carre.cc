#include "p_carre.hh"


P_Carre::P_Carre(couleur c):Piece(Position{2,1,2},c)
{

    _matrice.Ajout(Cube(c),Position{0,0,0});
    _matrice.Ajout(Cube(c),Position{1,0,0});
    _matrice.Ajout(Cube(c),Position{0,0,1});
    _matrice.Ajout(Cube(c),Position{1,0,1});
}

P_Carre &P_Carre::operator=(const P_Carre &p)
{
    Piece::operator=(p);
    return *this;
}

std::unique_ptr<Piece> P_Carre::clone() const
{
     return std::make_unique<P_Carre>(P_Carre(*this));
}
