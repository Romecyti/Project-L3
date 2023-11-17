#include "p_classique_6.hh"

P_classique_6::P_classique_6(couleur c):Piece(Position{4,1,2},c)
{

    _matrice.Ajout(Cube(c),Position{0,0,0});
    _matrice.Ajout(Cube(c),Position{1,0,1});
    _matrice.Ajout(Cube(c),Position{2,0,1});
    _matrice.Ajout(Cube(c),Position{3,0,0});


}

P_classique_6 &P_classique_6::operator=(const P_classique_6 &p)
{
    Piece::operator=(p);
    return *this;
}

std::unique_ptr<Piece> P_classique_6::clone() const
{
    return std::make_unique<P_classique_6>(P_classique_6(*this));
}
