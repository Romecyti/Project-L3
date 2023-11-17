#include "piece.hh"


Piece::Piece(const Position & pos, couleur c):_matrice(pos), _coul(c){}

Piece::Piece(const Piece &p):_matrice(p.GetMatrice()),_coul(p._coul){}

Piece &Piece::operator=(const Piece &p){
    if(this != &p){
        //on vient copier la matrice
        _matrice = p.GetMatrice();
        _coul = p._coul;
    }
    return *this;
}

Position Piece::Size() const{
    Position taille;
    taille._x = _matrice.Width();
    taille._y = _matrice.Height();
    taille._z = _matrice.Depth();

    return taille;
}

const Matrice3D & Piece::GetMatrice() const{
    return _matrice;
}

void Piece::Rotation(DIRECTION_ROT dir)
{
    if(dir==DIRECTION_ROT::rotX_gauche)
        _matrice.RotationX();

    else if(dir==DIRECTION_ROT::rotX_droite)
        _matrice.RotationMX();

    else if(dir==DIRECTION_ROT::rotY_gauche)
        _matrice.RotationY();

    else if(dir==DIRECTION_ROT::rotY_droite)
        _matrice.RotationMY();

    else if(dir==DIRECTION_ROT::rotZ_gauche)
        _matrice.RotationZ();

    else if(dir==DIRECTION_ROT::rotZ_droite)
        _matrice.RotationMZ();
}
