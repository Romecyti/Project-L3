#include "p_cube.hh"


const Position P_Cube::defaultSizeOfCube = {2,2,2};



P_Cube::P_Cube(couleur c): Piece(P_Cube::defaultSizeOfCube,c){
//on va ensuite venir placer un à un les cube de la forme
   //on en créer un de la bonne couleur
    Cube cub(c);
    for (auto i(0); i < this->Size()._y; i ++) {
        for (auto j(0); j < this->Size()._x; j ++) {
            for (auto k(0); k < this->Size()._z; k ++) {
                _matrice.Ajout(c,{j,i,k});
            }
        }
    }
}

P_Cube &P_Cube::operator=(const P_Cube &p)
{
    Piece::operator=(p);
    return *this;
}

std::unique_ptr<Piece> P_Cube::clone() const
{
    return std::make_unique<P_Cube>(P_Cube(*this));
}

void P_Cube::Rotation(DIRECTION_ROT d)
{

}



