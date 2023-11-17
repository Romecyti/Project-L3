#include "p_classique_4.hh"


P_classique_4::P_classique_4(couleur c):Piece(Position{3,1,2},c)
{

    _matrice.Ajout(Cube(c),Position{0,0,0});
    _matrice.Ajout(Cube(c),Position{1,0,1});
    _matrice.Ajout(Cube(c),Position{2,0,0});


}

P_classique_4 &P_classique_4::operator=(const P_classique_4 &p)
{
    Piece::operator=(p);
    return *this;
}

std::unique_ptr<Piece> P_classique_4::clone() const
{
    return std::make_unique<P_classique_4>(P_classique_4(*this));
}
