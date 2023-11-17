#include "p_l.hh"


P_L::P_L(couleur c):Piece (Position{3,2,1},c)
{
    for (int i=0;i<3;i++) {
        _matrice.Ajout(Cube(c),Position{i,0,0});

    }
    _matrice.Ajout(Cube(c),Position{0,1,0});
}

P_L &P_L::operator=(const P_L &p)
{
    Piece::operator=(p);
    return *this;
}

std::unique_ptr<Piece> P_L::clone() const
{
    return std::make_unique<P_L>(P_L(*this));
}

