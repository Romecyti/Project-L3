#include "p_classique_3.hh"


P_classique_3::P_classique_3(couleur c):Piece(Position{3,1,1},c)
{

    _matrice.Ajout(Cube(c),Position{0,0,0});
    _matrice.Ajout(Cube(c),Position{2,0,0});


}

P_classique_3 &P_classique_3::operator=(const P_classique_3 &p)
{
    Piece::operator=(p);
    return *this;
}

std::unique_ptr<Piece> P_classique_3::clone() const
{
    return std::make_unique<P_classique_3>(P_classique_3(*this));
}
