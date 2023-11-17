#pragma once

#include <vector>
#include <memory>
#include"cube.hh"
#include"m3exceptions.h"
#include"m3exists.h"
struct Position
{
    int _x;
    int _y;
    int _z;
};


class Matrice3D
{
private:
    std::vector<std::vector<std::vector<Cube*>*>*> _matrice;
    Position _taille; //position du dernier cube par rapport à (0,0,0) qui est l'origine


    void NettoiePronf(Cube* pt);
    void NettoieLargeur(std::vector<Cube*>* pt);

    void NettoieHauteur(std::vector<std::vector<Cube*>*>* pt);

    // accesseur de membre
   Cube* At(const Position & pos)const;
    std::vector<std::vector<Cube*>*>* At(std::size_t  hauteur) const;


public:
    Matrice3D();
    Matrice3D(const Position & pos);
    Matrice3D(const Matrice3D & M);
    ~Matrice3D();//TODO

    void Ajout(const Cube & cube,const Position & pos);
    //void Ajout(const std::unique_ptr<std::vector<std::unique_ptr<Cube>>> & carre, int hauteur);//TODO

    // permet l'ajout d'une matrice de plus petite taille dans une autre matrice (avec gestion d'erreur)
    void Calque(const Matrice3D & sousMatrice,const Position & pos);


    //tester a la position p si il y a un cube
    bool Exist(Position p)const;
    bool ExistCarre(int h)const;
    int HauteurMax()const;

    Cube GetAt(Position pos)const;
    // accesseur de taille
    int Width() const; // taille en x
    int Height() const; //taille en y
    int Depth() const; //taille en z

    // modificateur de taille
    void ModifSize(const Position & pos);

    //fonctions de suppression
    void  SuppressionCube(const Position & pos );
    void  SuppressionCarre(int hauteur);
    void  MoveUp();

    //echange 2 carre entre la hauteur 1 et la hauteur 2
    void EchangeCarre(int hauteur1,int hauteur2);

    //permet de savoir si le carre a la hauteur h est plein
    bool CarrePlein(int hauteur) const;

    void RotationY();
    void RotationMY();

    void RotationX();
    void RotationMX();

    void RotationZ();
    void RotationMZ();

    bool operator==(Matrice3D const & M) ;

    void operator= (Matrice3D const & M);
/*
    //accesseur directe pour la classe Matrice3D
    std::unique_ptr<cube> FirstCube() const;
    std::unique_ptr<cube> LastCube() const;

    std::unique_ptr<std::vector<std::unique_ptr<cube>>> FirstCarre() const;
    std::unique_ptr<std::vector<std::unique_ptr<cube>>> LasteCarre() const;
*/

};

