#include "p_classique_7.hh"

P_classique_7::P_classique_7(couleur c):Piece(Position{4,2,2},c)
{

    _matrice.Ajout(Cube(c),Position{0,1,0});
    _matrice.Ajout(Cube(c),Position{1,0,0});
    _matrice.Ajout(Cube(c),Position{2,0,1});
    _matrice.Ajout(Cube(c),Position{3,1,1});


}

P_classique_7 &P_classique_7::operator=(const P_classique_7 &p)
{
    Piece::operator=(p);
    return *this;
}

std::unique_ptr<Piece> P_classique_7::clone() const
{
    return std::make_unique<P_classique_7>(P_classique_7(*this));
}
