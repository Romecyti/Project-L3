#pragma once

#include "../base/plateau.hh"
#include "../model.hh"
#include<memory>
#include <queue>
#include <chrono> //include utilisé pour calculer les timing de pose et autre
#include<QtWidgets>
#include "../base/pieces/repertoire_piece.hh" //include de toutes les pièces



enum class NIVEAU{
    facile,
    normal,
    difficile,
    master
};
enum class SetDePiece
{
    old_school,
    old_schoolp,
    classique,
    all_star

};


//définition d'une structure permettant d'enregistrer la pièce actuellement utilisée et sa position dans le plateau
struct piece_actuelle{
    std::unique_ptr<Piece> piece;
    Position pos;
    piece_actuelle():piece(nullptr), pos({0,0,0}){}

    piece_actuelle(piece_actuelle const & p): pos(p.pos){piece=p.piece->clone();}
};

//classe modèle permettant de représenter un jeu de tetris classique
class TetrisClassique: public QObject
{
private:
    //définit de la taille classique d'un tetris
    static Position TetrisPlateauDefaultSize;

    std::vector<Piece*> _pieces_possibles; //tableau qui contiendra une liste des pièces possibles lors du jeu  (initialisé à la création d'un tetris)

    //définition des membres privée d'un tetris classique
    piece_actuelle _piece_actuelle;
    //int _niveau;
    //int _nbPoint;
    //int _nbEtagesDetruits;
    std::unique_ptr<Piece> _reserve;
    std::queue<std::unique_ptr<Piece>> _piece_suivantes;
    bool _verrouReserve;
    bool _jeufinit;
    bool _pause;

    long long _tempDescente; //en millisecondes
    long long _tempDerniereDescente;
    long long _tempsecouler;

    Plateau _plateau;

    //fonctions et méthodes privées
    bool Colision(DIRECTION_MOUVEMENT d)const;
    void GenererPiece();
   virtual  void Pose();
    virtual void SupprimerCarrePlein();
    void PrendPieceSuivante();
protected:
    Plateau &getplateau();
    void Setfinit(bool state);
    void SetPositionPieceActuelle(Position p);
    Position const &GetPositionPieceActuelle()const;
    int _niveau;
    int _nbPoint;
    int _nbEtagesDetruits;

public:
    

    //fonctions et méthodes publiques
    TetrisClassique(NIVEAU n,SetDePiece Sp, Position p = TetrisPlateauDefaultSize,QObject * ptr=nullptr);
    virtual ~TetrisClassique();
    TetrisClassique(const TetrisClassique & t) = delete ;

    void RotatationPiece(DIRECTION_ROT d); //permet la rotation de la pièce actuellement utilisée
    void Deplacement(DIRECTION_MOUVEMENT d); // permet le déplacement de la pièce actuellement utilisée
    void Descente(); //fait un déplacement de la pièce actuellement utilisée de une case vers le bas
    void IncrementeNiveau(); //incrémente le niveau actuel de 1 (permet ensuite la modification de la vitesse de descente)
    void MiseEnReserve(); //met en réserve la pièce actuellement utilisé et la remplace par celle de la réserve si elle existe sinon prend la première de la liste
    void PriseReserve(); //prend la pièce en réserve si elle existe et la met en tant que pièce utilisée actuellement et inversement pour la pièce utilisée actuellement 

    void DebutPause();
    void FinPause();
    //getters 
    int GetNbEtageDetruits()const;
    int GetNiveau()const; //retourne le niveau actuel
    const std::unique_ptr<Piece> GetReserve()const; //retourne la pièce actuellement en réserve
    const Plateau & GetPlateau()const; //retourne la matrice du plateau
    int GetNbPoint()const; //retourne le nombre de points attribués à la partie en cours
    const std::unique_ptr<piece_actuelle> GetPieceActuelle()const; //retourne la pièce actuelle
    bool JeuFinit() const; //retourne la valeur du booleen associé à la fin du jeu
    bool JeuPause()const;
    long long GetTempDescente()const;
    std::queue<std::unique_ptr<Piece>> GetListePieceSuivantes();
    Q_OBJECT

signals:
    void DeplacementImpossible();
    void RotationImpossible();
    void PiecePose();
};

