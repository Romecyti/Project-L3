#pragma once

#include "piece.hh"
#include "matrice3d.hh"



enum class DIRECTION_MOUVEMENT{
    droite,
    gauche,
    bas,
    avant,
    arriere
};


class Plateau
{
private:
    //membres privés
    Matrice3D _plato;

    //fonctions et méthodes privées
    //fonctions qui renvoient vrai si une collision est prévu dans le cas d'un déplacement dans la direction prévue
    bool CollisionDroite(const Piece & piece, const Position & pos) const;
    bool CollisionGauche(const Piece & piece, const Position & pos) const;
    bool CollisionAvant(const Piece & piece, const Position & pos) const;
    bool CollisionArriere(const Piece & piece, const Position & pos) const;
    bool CollisionBasse(const Piece & piece, const Position & pos) const;

    void Decaler(int hauteur);

public:
    Plateau(const Position & pos);
    ~Plateau() = default;

    Plateau & operator=(Plateau const & p);

    //vérifie si une collision à lieu si la pièce est déplacé dans cette direction
    bool Collision(const Piece & piece, const Position & pos, DIRECTION_MOUVEMENT dir) const;

    //permet d'ajouter une pièce dans le plateau (l'éclate en autant de cube qu'elle est composée)
    void Ajout(const Piece & piece, const Position & pos);

    //supprime tous les carré plein et renvoie le nombre de carré supprimé
    unsigned int SupprimeCarrePlein();

    //vérifie si la pièce passée en paramètre est bien contenu dans la matrice du plateau
    bool Depasse(const Piece & piece, const Position & pos) const;

    //renvoie la taille de la matrice du plateau
    Position Size() const;

    //renvoie la matrice du plateau
    const Matrice3D & GetMatrice() const;

    //fonction qui permet la modification de la taille du plateau
    void ModifTaille(Position p);

    //renvoie vrai s'il y a une intersection entre la pièce passée en paramètre avec un cube du plateau
    bool Intersection(const Piece & piece, const Position & pos) const;

    bool AjoutCarre();

};





