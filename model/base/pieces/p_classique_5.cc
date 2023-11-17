#include "p_classique_5.hh"

P_classique_5::P_classique_5(couleur c):Piece(Position{3,2,2},c)
{

    _matrice.Ajout(Cube(c),Position{0,0,0});
    _matrice.Ajout(Cube(c),Position{2,0,0});
    _matrice.Ajout(Cube(c),Position{1,1,1});


}

P_classique_5 &P_classique_5::operator=(const P_classique_5 &p)
{
    Piece::operator=(p);
    return *this;
}

std::unique_ptr<Piece> P_classique_5::clone() const
{
    return std::make_unique<P_classique_5>(P_classique_5(*this));
}
