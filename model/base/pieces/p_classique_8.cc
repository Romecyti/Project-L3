#include "p_classique_8.hh"

P_classique_8::P_classique_8(couleur c):Piece(Position{3,1,3},c)
{

    _matrice.Ajout(Cube(c),Position{0,0,0});
    _matrice.Ajout(Cube(c),Position{1,0,0});

    _matrice.Ajout(Cube(c),Position{0,0,1});
    _matrice.Ajout(Cube(c),Position{2,0,1});
    _matrice.Ajout(Cube(c),Position{1,0,2});
    _matrice.Ajout(Cube(c),Position{2,0,2});


}

P_classique_8 &P_classique_8::operator=(const P_classique_8 &p)
{
    Piece::operator=(p);
    return *this;
}

std::unique_ptr<Piece> P_classique_8::clone() const
{
    return std::make_unique<P_classique_8>(P_classique_8(*this));
}
