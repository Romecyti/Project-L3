#include "p_classique_2.hh"



P_classique_2::P_classique_2(couleur c):Piece(Position{3,1,3},c)
{

    _matrice.Ajout(Cube(c),Position{0,0,2});
    //_matrice.Ajout(Cube(c),Position{1,0,1});
    _matrice.Ajout(Cube(c),Position{2,0,0});


}

P_classique_2 &P_classique_2::operator=(const P_classique_2 &p)
{
    Piece::operator=(p);
    return *this;
}

std::unique_ptr<Piece> P_classique_2::clone() const
{
    return std::make_unique<P_classique_2>(P_classique_2(*this));
}
