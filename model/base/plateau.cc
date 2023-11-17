#include "plateau.hh"


//méthodes et fonctions privées de la classe Plateau

//vérifie si une collision va avoir lieu vers la droite
bool Plateau::CollisionDroite(const Piece & piece, const Position & pos) const{
    Position taillePiece = piece.Size();
    //on va d'abord vérifie que la matrice de la piece ne dépasse pas 
    if(Depasse(piece, pos)){
        return true;
    }

    int xmax =0;
    //on regarde ensuite si la pièce est collée au bord droit du plateau
    if((pos._x + piece.Size()._x) == _plato.Width()){
        //si oui, alors on ne testera pas la colision droite depuis la dernière colonne en largeur de la pièce
        xmax = taillePiece._x -1;
    }
    else{
        xmax = taillePiece._x;
    }

    //si la pièce ne dépasse pas alors on va venir tester un à un chaque position
    for (int i = 0; i < taillePiece._y; i++)
    {
        for (int j = 0; j < xmax; j++)
        {
            for (int k = 0; k < taillePiece._z; k++)
            {
                //on vient récupérurer le pointeur sur le cube de la pièce à la position {j,i,k}
                Position positioncube = {j,i,k};
                Position positionATetser = {pos._x + j + 1,pos._y + i, pos._z + k};
                //on vient ensuite vérifier si il y a un cube à cette position
                if(piece.GetMatrice().Exist({positioncube})){
                    //on vient ensuite vérifier si il y a un cube à cette position dans le plateau
                    if(_plato.Exist({positionATetser})){
                        return true;
                    }
                }
            }
            
        }
        
    }

    return false;
}

//vérifie si une collision va avoir lieu vers la gauche
bool Plateau::CollisionGauche(const Piece & piece, const Position & pos) const{
    Position taillePiece = piece.Size();
    //on va d'abord vérifie que la matrice de la piece ne dépasse pas 
    if(Depasse(piece, pos)){
        return true;
    }

    int xmin =0;
    //on regarde ensuite si la pièce est collée au bord gauche du plateau
    if(pos._x == 0){
        //si oui, alors on testera la colision gauche depuis la deuxième colonne en largeur de la pièce
        xmin = 1;
    }
    else{
        xmin = 0;
    }

    //si la pièce ne dépasse pas alors on va venir tester un à un chaque position
    for (int i = 0; i < taillePiece._y; i++)
    {
        for (int j = xmin; j < taillePiece._x; j++)
        {
            for (int k = 0; k < taillePiece._z; k++)
            {
                //on vient récupérurer le pointeur sur le cube de la pièce à la position {j,i,k}
                Position positioncube = {j,i,k};
                Position positionATetser = {pos._x + j - 1,pos._y + i, pos._z + k};
                //on vient ensuite vérifier si il y a un cube à cette position
                if(piece.GetMatrice().Exist({positioncube})){
                    //on vient ensuite vérifier si il y a un cube à cette position dans le plateau
                    if(_plato.Exist({positionATetser})){
                        return true;
                    }
                }
            }
            
        }
        
    }

    return false;
}

//vérifie si une collision va avoir lieu vers l'avant
bool Plateau::CollisionArriere(const Piece &piece, const Position &pos) const{
Position taillePiece = piece.Size();
    //on va d'abord vérifie que la matrice de la piece ne dépasse pas 
    if(Depasse(piece, pos)){
        return true;
    }

    int zmin =0;
    //on regarde ensuite si la pièce est collée au bord avant du plateau
    if(pos._z == 0){
        //si oui, alors on ne testera pas la colision avant depuis la première colonne en profondeur de la pièce
        zmin = 1;
    }
    else{
        zmin = 0;
    }

    //si la pièce ne dépasse pas alors on va venir tester un à un chaque position
    for (int i = 0; i < taillePiece._y; i++)
    {
        for (int j = 0; j < taillePiece._x; j++)
        {
            for (int k = zmin; k < taillePiece._z; k++)
            {
                //on vient récupérurer le pointeur sur le cube de la pièce à la position {j,i,k}
                Position positioncube = {j,i,k};
                Position positionATetser = {pos._x + j,pos._y + i, pos._z + k - 1};
                //on vient ensuite vérifier si il y a un cube à cette position
                if(piece.GetMatrice().Exist({positioncube})){
                    //on vient ensuite vérifier si il y a un cube à cette position dans le plateau
                    if(_plato.Exist({positionATetser})){
                        return true;
                    }
                }
            }
            
        }
        
    }

    return false;
}

//vérifie si une collision va avoir lieu vers l'arrière
bool Plateau::CollisionAvant(const Piece & piece, const Position & pos) const{
Position taillePiece = piece.Size();
    //on va d'abord vérifie que la matrice de la piece ne dépasse pas 
    if(Depasse(piece, pos)){
        return true;
    }

    int zmax =0;
    //on regarde ensuite si la pièce est collée au bord arrière du plateau
    if((pos._z + taillePiece._z) == _plato.Depth()){
        //si oui, alors on ne testera pas la colision arrière sur la denière colonne en profondeur de la pièce
        zmax = taillePiece._z -1;
    }
    else{
        zmax = taillePiece._z;
    }

    //si la pièce ne dépasse pas alors on va venir tester un à un chaque position
    for (int i = 0; i < taillePiece._y; i++)
    {
        for (int j = 0; j < taillePiece._x; j++)
        {
            for (int k = 0; k < zmax; k++)
            {
                //on vient récupérurer le pointeur sur le cube de la pièce à la position {j,i,k}
                Position positioncube = {j,i,k};
                Position positionATetser = {pos._x + j,pos._y + i, pos._z + k +1};
                //on vient ensuite vérifier si il y a un cube à cette position
                if(piece.GetMatrice().Exist({positioncube})){
                    //on vient ensuite vérifier si il y a un cube à cette position dans le plateau
                    if(_plato.Exist({positionATetser})){
                        return true;
                    }
                }
            }
            
        }
        
    }

    return false;
}

//vérifie si une collision va avoir lieu vers le bas
bool Plateau::CollisionBasse(const Piece & piece, const Position & pos) const{
Position taillePiece = piece.Size();
    //on va d'abord vérifie que la matrice de la piece ne dépasse pas 
    if(Depasse(piece, pos)){
        return true;
    }

    int yminPiece =0;
    //on regarde ensuite si la pièce est collée au sol du plateau
    if(pos._y == 0){
        //si oui, alors on ne testera pas la colision basse sur la denière ligne en hauteur de la pièce
        yminPiece = 1;
    }
    else{
        yminPiece = 0;
    }

    //si la pièce ne dépasse pas alors on va venir tester un à un chaque position
    for (int i = yminPiece; i < taillePiece._y; i++)
    {
        for (int j = 0; j < taillePiece._x; j++)
        {
            for (int k = 0; k < taillePiece._z; k++)
            {
                //on vient récupérer le pointeur sur le cube de la pièce à la position {j,i,k}
                Position positioncube = {j,i,k};
                //et le pointeur sur le cube du plateau à la position {j,i-1,k}
                Position positionATetser = {pos._x + j,pos._y + i - 1, pos._z + k};
                //on vient ensuite vérifier si il y a un cube à cette position
                if(piece.GetMatrice().Exist({positioncube})){
                    //on vient ensuite vérifier si il y a un cube à cette position dans le plateau
                    if(_plato.Exist({positionATetser})){
                        return true;
                    }
                }
            }
            
        }
        
    }

    return false;
}

//fonction qui décale d'un étage tous les étages au dessus de celui indiqué vers le bas
void Plateau::Decaler(int hauteur){
    for (int i = hauteur; i < _plato.Height()-1; i++)
    {
        _plato.EchangeCarre(i, i+1);
    }
}

//méthodes et fonctions publiques de la classe Plateau

Plateau::Plateau(const Position & pos):_plato(pos){}

Plateau &Plateau::operator=(const Plateau &p)
{
    if(this != &p){
        //on vient copier la matrice
        _plato = p.GetMatrice();
    }
    return *this;
}

//vérifie si une collision à lieu si la pièce est déplacé dans cette direction
bool Plateau::Collision(const Piece & piece, const Position & pos, DIRECTION_MOUVEMENT dir) const{
    switch (dir)
    {
    case DIRECTION_MOUVEMENT::droite :
        return CollisionDroite(piece, pos);
    case DIRECTION_MOUVEMENT::gauche :
        return CollisionGauche(piece, pos);
    case DIRECTION_MOUVEMENT::avant :
        return CollisionAvant(piece, pos);
    case DIRECTION_MOUVEMENT::arriere :
        return CollisionArriere(piece, pos);
    case DIRECTION_MOUVEMENT::bas :
        return CollisionBasse(piece, pos);
    }
    return true;
}

//permet d'ajouter une pièce dans le plateau (l'éclate en autant de cube qu'elle est composée)
void Plateau::Ajout(const Piece & piece, const Position & pos){
    _plato.Calque(piece.GetMatrice(), pos);
}

//supprime tous les carré plein et renvoie le nombre de carré supprimé
unsigned int Plateau::SupprimeCarrePlein(){
    unsigned int nbcarresupprime = 0;
    for (int i = 0; i < _plato.Height(); i++)
    {
        if(_plato.CarrePlein(i)){
            _plato.SuppressionCarre(i);
            nbcarresupprime ++;
            Decaler(i);
            i--;
        }
    }
    return nbcarresupprime;
}

//vérifie si la pièce passée en paramètre est bien contenu dans la matrice du plateau
bool Plateau::Depasse(const Piece & piece, const Position & pos) const{
    return ((pos._x + piece.Size()._x > _plato.Width())
            || (pos._y + piece.Size()._y > _plato.Height())
            || (pos._z+ piece.Size()._z > _plato.Depth())
            || (pos._x < 0)
            || (pos._y < 0)
            || (pos._z < 0));
}

//renvoie la taille de la matrice du plateau
Position Plateau::Size() const{
    return {_plato.Width(),_plato.Height(), _plato.Depth()};
}

//renvoie la matrice du plateau
const Matrice3D & Plateau::GetMatrice() const{
    return _plato ;
}

//fonction qui permet la modification de la taille du plateau
void Plateau::ModifTaille(Position p){
    _plato.ModifSize(p);
}

//renvoie vrai s'il y a une intersection entre la pièce passée en paramètre avec un cube du plateau
bool Plateau::Intersection(const Piece & piece, const Position & pos) const{
    Position taillePiece = piece.Size();
    //on va d'abord vérifie que la matrice de la piece ne dépasse pas 
    if(Depasse(piece, pos)){
        return true;
    }

    //si la pièce ne dépasse pas alors on va venir tester un à un chaque position
    for (int i = 0; i < taillePiece._y; i++)
    {
        for (int j = 0; j < taillePiece._x; j++)
        {
            for (int k = 0; k < taillePiece._z; k++)
            {
                //on vient récupérurer le pointeur sur le cube de la pièce à la position {j,i,k}
                Position positioncube = {j,i,k};
                Position positionATetser = {pos._x + j,pos._y + i, pos._z + k};
                //on vient ensuite vérifier si il y a un cube à cette position
                if(piece.GetMatrice().Exist({positioncube})){
                    //on vient ensuite vérifier si il y a un cube à cette position dans le plateau
                    if(_plato.Exist({positionATetser})){
                        return true;
                    }
                }
            }
            
        }
        
    }

    return false;
}

bool Plateau::AjoutCarre(){

    bool ret=_plato.HauteurMax()>=_plato.Height()-1;
    int trouz=std::rand()%(_plato.Depth()-1);
    int troux=std::rand()%(_plato.Width()-1);
    int possedetrou=false;
    _plato.MoveUp();

    for (int w=0;w<_plato.Width();w++) {
            for (int d=0;d<_plato.Depth();d++) {
                    if(w==troux && d==trouz && !possedetrou)
                    {
                        possedetrou=true;
                    }
                    else {
                        _plato.Ajout(Cube(couleur::gris),Position{w,0,d});
                    }

            }

        }

        return ret;

}

