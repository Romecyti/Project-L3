#include "cube.hh"

Cube::Cube(couleur coul):_couleur(coul){}

couleur Cube::GetCouleur() const
{
    return  _couleur;
}

void Cube::SetCouleur(couleur c)
{
    _couleur=c;
}
