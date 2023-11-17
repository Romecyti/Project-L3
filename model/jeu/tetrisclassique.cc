#include "tetrisclassique.hh"
#include <cmath>
//#include"./model/base/pieces/repertoire_piece.hh"


Position TetrisClassique::TetrisPlateauDefaultSize= {6,6,6};



//méthodes et fonctions privées de la classe TetrisClassique

//renvoie vrai si une collision va avoir lieu dans la direction passée en paramètre
bool TetrisClassique::Colision(DIRECTION_MOUVEMENT d)const{
    return _plateau.Collision(*_piece_actuelle.piece.get(), _piece_actuelle.pos,d);
}

//génère une pièce aléatoire parmis les pièces autorisées dans le mode de jeu
void TetrisClassique::GenererPiece(){
    unsigned long piecechoisit = static_cast<unsigned long>(std::rand())%_pieces_possibles.size();

    _piece_suivantes.push(_pieces_possibles.at(piecechoisit)->clone());
}

//pose la pièce à l'endroit passé en paramètre et modifie la pièce actuelle
void TetrisClassique::Pose(){
    emit PiecePose();
    //_nbPoint+=10;
    //on vient poser la pièce dans le plateau
    _plateau.Ajout(*_piece_actuelle.piece, _piece_actuelle.pos);

    SupprimerCarrePlein();

    //on vient ensuite récupérer la pièce du début de file pour la mettre en pièce actuelle
    PrendPieceSuivante();
}

//méthode qui enlève les carré plein et modifie le score en fonction
void TetrisClassique::SupprimerCarrePlein(){
    unsigned int nbcarresupprime = _plateau.SupprimeCarrePlein();
    
    switch (nbcarresupprime)
    {
    case 0: //on ne modifie pas le score
        break;
    case 1:
        _nbPoint += 100;
        break;
    case 2:
        _nbPoint += 250;
        break;
    case 3:
        _nbPoint += 600;
        break;
    default: //4 et plus (normalement jamais autant car pièce la plus grande est de 4 de hauteur)
        _nbPoint += 1500;
        break;
    }

    _nbEtagesDetruits+=nbcarresupprime;

    if(_nbEtagesDetruits >= 4 * (pow(2,_niveau)))
        IncrementeNiveau();
}

//méthode qui prend la première pièce de la liste des suivante et la place comme pièce actuelle (cela supprime la pièce atuelle)
void TetrisClassique::PrendPieceSuivante(){
    //on change la pièce actuelle
    _piece_actuelle.piece = std::move(_piece_suivantes.front());
    _piece_suivantes.pop();

    //on vient calculer la position de base de la pièce suivante
    _piece_actuelle.pos = { /*X*/ (_plateau.Size()._x - (_piece_actuelle.piece.get())->Size()._x )/ 2,
                            /*Y*/ _plateau.Size()._y - ((_piece_actuelle.piece.get())->Size()._y),
                            /*Z*/ (_plateau.Size()._z - (_piece_actuelle.piece.get())->Size()._z )/ 2};

    //on vient générer une nouvelle pièce pour la liste des pièces suivantes
    GenererPiece();

    //on remet le temps de descente à 0
    _tempDerniereDescente = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch()).count();
    //et l'on vient s'assurer que la réserve est accessible
    _verrouReserve = false;

    //on regarde maintenant si la nouvelle pièce génére une intersection, ce qui signifierait la fin de la partie
    if(_plateau.Intersection(*_piece_actuelle.piece.get(),_piece_actuelle.pos)){
        _jeufinit = true;
    }

}

Plateau &TetrisClassique::getplateau()
{
    return _plateau;
}

void TetrisClassique::Setfinit(bool state)
{
    _jeufinit=state;
}

void TetrisClassique::SetPositionPieceActuelle(Position p)
{
    if(p._x>=0 && p._x+_piece_actuelle.piece->Size()._x<_plateau.Size()._x)
        if(p._y>=0 && p._y+_piece_actuelle.piece->Size()._y<_plateau.Size()._y)
            if(p._z>=0 && p._z+_piece_actuelle.piece->Size()._z<_plateau.Size()._z)
                _piece_actuelle.pos=p;
}

const Position &TetrisClassique::GetPositionPieceActuelle() const
{
    return _piece_actuelle.pos;
}



//méthodes et fonctions publiques de la classe TetrisClassique
TetrisClassique::TetrisClassique(NIVEAU n, SetDePiece Sp, Position p, QObject *ptr):QObject (ptr), _plateau(TetrisPlateauDefaultSize){
    //on vient regarder si la taille du plateau passée en paramètre n'est pas différente de la taille par défaut (dans n'importe quelle dimensions)
    if((p._x != TetrisPlateauDefaultSize._x || p._y != TetrisPlateauDefaultSize._y || p._z != TetrisPlateauDefaultSize._z)){
        //si oui, on s'assure que aucune des tailles ne soit inférieur à la taille par défaut
        if(p._x < TetrisPlateauDefaultSize._x){
            p._x = TetrisPlateauDefaultSize._x;
        }
        if(p._y < TetrisPlateauDefaultSize._z){
            p._y = TetrisPlateauDefaultSize._z;
        }
        if(p._z < TetrisPlateauDefaultSize._z){
            p._z = TetrisPlateauDefaultSize._z;
        }
        //dans ce cas on vient redéfinir la taille du plateau
        _plateau.ModifTaille(p);
    }

    _jeufinit = false;
    _pause=false;

    //on vient générer la liste des pièces possible pour un tetris classique
    {
         _pieces_possibles.push_back(new P_I(couleur::rose));


        if(Sp== SetDePiece::old_schoolp || Sp==SetDePiece::all_star){

            _pieces_possibles.push_back(new P_Cube(couleur::cyan));
            _pieces_possibles.push_back(new P_LAugmente(couleur::sapin));
            _pieces_possibles.push_back(new P_Z3d(couleur::bordeaux));
            _pieces_possibles.push_back(new P_T3d(couleur::violet));
        }

        if(Sp==SetDePiece::old_schoolp ||Sp==SetDePiece::old_school || Sp==SetDePiece::all_star )
        {
            _pieces_possibles.push_back(new P_L(couleur::rouge));
            _pieces_possibles.push_back(new P_T(couleur::vert));
            _pieces_possibles.push_back(new P_Z(couleur::jaune));
            _pieces_possibles.push_back(new P_Carre(couleur::bleu));
        }

        if(Sp==SetDePiece::classique || Sp==SetDePiece::all_star)
        {
            _pieces_possibles.push_back(new P_classique_1(couleur::rouge));
            _pieces_possibles.push_back(new P_classique_2(couleur::vert));
            _pieces_possibles.push_back(new P_classique_3(couleur::jaune));
            _pieces_possibles.push_back(new P_classique_4(couleur::bordeaux));
            _pieces_possibles.push_back(new P_classique_5(couleur::bleu));
            _pieces_possibles.push_back(new P_classique_6(couleur::cyan));
            _pieces_possibles.push_back(new P_classique_7(couleur::sapin));
            _pieces_possibles.push_back(new P_classique_8(couleur::violet));

        }


    }




    //on initialise la pile des pièces à venir
    for(auto i(0); i < 3; i++){
        GenererPiece();
    }

    //on initialise le score à 0
    _nbPoint = 0;
    //on initialise le nombre d'etage detruit a 0
    _nbEtagesDetruits=0;

    //on met la réserve comme accessible
    _verrouReserve = false;

    //on initialise la valeur de descente pour le bon niveau
    switch (n)
    {
    case NIVEAU::facile:
        _tempDescente = 1800;
        break;
    case NIVEAU::normal:
        _tempDescente = 1500;
        break;
    case NIVEAU::difficile:
        _tempDescente = 1200;
        break;
    case NIVEAU::master:
        _tempDescente = 900;
        break;
    }

    //on initialise le niveau à 0;
    _niveau = 0;

    //on initialise le jeu
    PrendPieceSuivante();

    _tempsecouler=0;
    //on met à 0 le timer de descente
    _tempDerniereDescente = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch()).count();

}

TetrisClassique::~TetrisClassique()
{
    // on vient désallouer la mémoire associée aux pièces possibles
    for (auto i(_pieces_possibles.begin()); i != _pieces_possibles.end(); i++) {
        delete *i;
    }
}

void TetrisClassique::RotatationPiece(DIRECTION_ROT d){
    if(!_pause &&  !_jeufinit){
        Position taille_avant=_piece_actuelle.piece->Size();
        // Position pos_avant=_piece_actuelle.pos;

        //_piece_actuelle.piece->Rotation(d);
        auto i =GetPieceActuelle();
        i->piece->Rotation(d);

        Position taille_apres=i->piece->Size();

        i->pos._x+=(taille_avant._x-taille_apres._x)/2;
        i->pos._y+=(taille_avant._y-taille_apres._y)/2;
        i->pos._z+=(taille_avant._z-taille_apres._z)/2;

        if(! _plateau.Intersection(*(i->piece.get()),i->pos))
        {

            _piece_actuelle.pos=i->pos;
            _piece_actuelle.piece->Rotation(d);

        }
        else {
            emit RotationImpossible();
        }

    }



}

void TetrisClassique::Deplacement(DIRECTION_MOUVEMENT d){
    if(!_pause &&  !_jeufinit){

        bool colision=Colision(d);
        if(colision){
            //alors il y a une collision et on ne peut pas déplacer la place sauf si le déplacement est vers le bas et l'on pose la pièce
            if(d == DIRECTION_MOUVEMENT::bas)
                Pose();
            else {
                emit DeplacementImpossible();
            }

        }
        else{
            switch (d)
            {
            case DIRECTION_MOUVEMENT::avant:
                //on vient vérifier que la pièce n'est pas au bord de l'univers
                if(_piece_actuelle.pos._z + _piece_actuelle.piece->Size()._z < _plateau.Size()._z )
                    _piece_actuelle.pos._z +=1;
                else
                    emit DeplacementImpossible();

                break;
            case DIRECTION_MOUVEMENT::arriere:
                //on vient vérifier que la pièce n'est pas au bord de l'univers
                if(_piece_actuelle.pos._z > 0)
                    _piece_actuelle.pos._z -=1;
                else
                    emit DeplacementImpossible();
                break;
            case DIRECTION_MOUVEMENT::droite:
                //on vient vérifier que la pièce n'est pas au bord de l'univers
                if(_piece_actuelle.pos._x +_piece_actuelle.piece->Size()._x  < _plateau.Size()._x )
                    _piece_actuelle.pos._x +=1;
                else
                    emit DeplacementImpossible();
                break;
            case DIRECTION_MOUVEMENT::gauche:
                //on vient vérifier que la pièce n'est pas au bord de l'univers
                if(_piece_actuelle.pos._x > 0)
                    _piece_actuelle.pos._x -=1;
                else
                    emit DeplacementImpossible();
                break;
            case DIRECTION_MOUVEMENT::bas:
                //on vient vérifier que la pièce n'est pas au bord de l'univers
                if(_piece_actuelle.pos._y > 0){
                    _piece_actuelle.pos._y -=1;
                    _tempDerniereDescente = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch()).count();
                }
                else { //sinon on vient poser la pièce
                    Pose();
                }
                break;
            }
        }
    }

}

void TetrisClassique::Descente(){
    //on regarde dans un premier temps si le temps accordé pour la descente est passé
    if(((std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch()).count()) - _tempDerniereDescente) >= _tempDescente && (!_pause ||  !_jeufinit )){
        //si oui, alors on vient descendre la pièce
        Deplacement(DIRECTION_MOUVEMENT::bas);
    }
    //sinon, on ne fait rien
}

void TetrisClassique::IncrementeNiveau(){
    //on vient s'assurer que le niveau n'est pas supérieur au niveau max
    if(_niveau < 4){
        _niveau ++;
        _tempDescente -= 150; //toujours en miliseconde
    }
    //sinon, on ne fait rien
}

void TetrisClassique::MiseEnReserve(){
    //on vient vérifier si la réserve n'est pas vérouillée (c'est-à-dire que le joueur l'aurait déjà utilisée juste avant)
    if(!_verrouReserve &&( !_pause &&  !_jeufinit )){
        //si la réserve n'est pas vérouillée, alors on peut interchanger les pièces
        //on regarde si la réserve contient une pièce
        if(_reserve){
            //si oui, alors on vient prendre la pièce en réserve
            _reserve.swap(_piece_actuelle.piece);
            //et l'on recalcule la position de la pièce
            _piece_actuelle.pos = { /*X*/ (_plateau.Size()._x - (_piece_actuelle.piece.get())->Size()._x )/ 2,
                                    /*Y*/ _plateau.Size()._y - ((_piece_actuelle.piece.get())->Size()._y),
                                    /*Z*/ (_plateau.Size()._z - (_piece_actuelle.piece.get())->Size()._z )/ 2};
        }
        else{
            //sinon, alors on vient mettre la pièce actuelle en réserve et l'on prend la première pièce de la liste des suivantes
            _reserve = std::move(_piece_actuelle.piece);
            PrendPieceSuivante();
        }
        //et l'on vient bloquer la réserve
        _verrouReserve = true;
    }
    //sinon, on ne fait rien
}

void TetrisClassique::PriseReserve(){
    //on vérifie que la réserve est accessible (i.e. : non vérouiller) et qu'il y a bien une pièce dans celle-ci
    if(!_verrouReserve && _reserve && (!_pause &&  !_jeufinit ) ){
        //si la réserve n'est pas vérouillé et qu'il y à bien une pièce, alors on interchange la pièce actuelle avec la pièce de la réserve
        _reserve.swap(_piece_actuelle.piece);
        _piece_actuelle.pos = { /*X*/ (_plateau.Size()._x - (_piece_actuelle.piece.get())->Size()._x )/ 2,
                                /*Y*/ _plateau.Size()._y - ((_piece_actuelle.piece.get())->Size()._y),
                                /*Z*/ (_plateau.Size()._z - (_piece_actuelle.piece.get())->Size()._z )/ 2};
        //et l'on vient bloquer la réserve
        _verrouReserve = true;
        if(_plateau.Intersection(*_piece_actuelle.piece,_piece_actuelle.pos))
            _jeufinit=true;

    }
}


void TetrisClassique::DebutPause()
{
    if(!_pause &&  !_jeufinit)
    {
        _tempsecouler=(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch()).count())-_tempDerniereDescente;
        _pause=true;
    }
}

void TetrisClassique::FinPause()
{
    if(_pause ){
        _tempDerniereDescente=(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch()).count())-_tempsecouler;
        _tempsecouler=0;
        _pause=false;
    }
}

int TetrisClassique::GetNbEtageDetruits() const
{
    return _nbEtagesDetruits;
}

//retourne le niveau actuel
int TetrisClassique::GetNiveau()const{
    return _niveau;
}

//retourne la pièce actuellement en réserve
const std::unique_ptr<Piece> TetrisClassique::GetReserve()const{

    if(_reserve!=nullptr)
        return _reserve->clone();
    else {
        return nullptr;
    }
} 

//retourne la matrice du plateau
const  Plateau& TetrisClassique::GetPlateau()const{
    return _plateau;
} 

//retourne le nombre de points attribués à la partie en cours
int TetrisClassique::GetNbPoint()const{
    return _nbPoint;
} 

//retourne la pièce actuelle
const std::unique_ptr<piece_actuelle> TetrisClassique::GetPieceActuelle()const{
    //piece_actuelle p;
    //p.pos=_piece_actuelle.pos;
    //p.piece=_piece_actuelle.piece->clone();

    return  std::make_unique<piece_actuelle>(_piece_actuelle);
}

bool TetrisClassique::JeuFinit() const
{
    return _jeufinit;
}

bool TetrisClassique::JeuPause() const
{
    return  _pause;
}

long long TetrisClassique::GetTempDescente() const
{
    return  _tempDescente;
}

std::queue<std::unique_ptr<Piece> > TetrisClassique::GetListePieceSuivantes()
{
    std::queue<std::unique_ptr<Piece>> res;
    for(int i=0;i<_piece_suivantes.size();i++)
    {
        res.push(_piece_suivantes.front()->clone());
        _piece_suivantes.push(_piece_suivantes.front()->clone());
        _piece_suivantes.pop();

    }
    return  res;

}
