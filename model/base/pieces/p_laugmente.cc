#include "p_laugmente.hh"


P_LAugmente::P_LAugmente(couleur c):Piece(Position{3,2,2},c)
{
    for (int i=0;i<3;i++) {
        _matrice.Ajout(Cube(c),Position{i,0,0});

    }
    _matrice.Ajout(Cube(c),Position{0,1,0});
    _matrice.Ajout(Cube(c),Position{0,0,1});
}

P_LAugmente &P_LAugmente::operator=(const P_LAugmente &p)
{
    Piece::operator=(p);
    return *this;
}

std::unique_ptr<Piece> P_LAugmente::clone() const
{
     return std::make_unique<P_LAugmente>(P_LAugmente(*this));
}
