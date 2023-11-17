#include "p_classique_1.hh"



P_classique_1::P_classique_1(couleur c):Piece(Position{2,1,2},c)
{

    _matrice.Ajout(Cube(c),Position{0,0,1});
    _matrice.Ajout(Cube(c),Position{1,0,0});


}

P_classique_1 &P_classique_1::operator=(const P_classique_1 &p)
{
    Piece::operator=(p);
    return *this;
}

std::unique_ptr<Piece> P_classique_1::clone() const
{
    return std::make_unique<P_classique_1>(P_classique_1(*this));
}
