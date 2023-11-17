#include "p_i.hh"



P_I::P_I(couleur c):Piece(Position{4,1,1},c)
{
    for (int i=0;i<4;i++) {
        _matrice.Ajout(Cube(c),Position{i,0,0});

    }
}

P_I &P_I::operator=(const P_I &p)
{
    Piece::operator=(p);
    return *this;
}

std::unique_ptr<Piece> P_I::clone() const
{
     return std::make_unique<P_I>(P_I(*this));
}
