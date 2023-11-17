#pragma once

#include "matrice3d.hh"

enum class DIRECTION_ROT{
    rotX_droite,
    rotX_gauche,
    rotY_droite,
    rotY_gauche,
    rotZ_droite,
    rotZ_gauche
};

class Piece
{
protected:
    Matrice3D _matrice;
    couleur _coul;
public:
    Piece(const Position & pos, couleur c);
    Piece(const Piece & p);
    virtual ~Piece() = default;

    Piece & operator=(Piece const & p);

    Position Size() const; // renvoie la taille de la matrice sous forme de structure contenant la valeur des 3 dimensions
    const Matrice3D & GetMatrice() const; //renvoie la matrice de la pièce 

    virtual void Rotation(DIRECTION_ROT dir); //fait une rotation de la pièce dans le sens indiqué

    //méthode clone
    virtual std::unique_ptr<Piece> clone() const = 0;
};

