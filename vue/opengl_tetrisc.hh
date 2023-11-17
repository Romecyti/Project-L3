#pragma once
#include <QtWidgets>
//#include<GL/freeglut.h>
#include "../model/base/plateau.hh"
#include"../model/base/piece.hh"
//#include"base/tetris_opengl.hh"
#include"memory"
#include<QtMultimedia/QMediaPlaylist>
#include<QtMultimedia/QMediaPlayer>
#include<QtMultimedia/QSoundEffect>
#include<cmath>
#include"../model/settings/settings.hh"


class TetrisClassiqueOpenGl : public QOpenGLWidget//,protected QOpenGLFunctions
{
    Q_OBJECT
public:
     TetrisClassiqueOpenGl( NonAlterableSettings set,QWidget *parent = nullptr);
     ~TetrisClassiqueOpenGl();

     //Evenement claviers



private:
    //structure privées
     struct normale{
       float x;
       float y;
       float z;

     };
     struct point{//pas forcement utile mais rend le code plus lisible
         float x;
         float y;
         float z;
     };

     //menbres

     NonAlterableSettings _options;
     float _rotation_plateau_y;
     float _rotation_plateau_x;
     float _vitesse_rotation_y;
     bool _TypeRotationClassique;
     float _vitesse_rotation_x;
     float _hauteurmatrice;
     int _Points;

     QPushButton quit;
     QPushButton retry;
     QPushButton pause;



    std::vector<QOpenGLTexture *> _textures;

     Matrice3D _plato;
     std::vector<std::unique_ptr<Piece>> _suivant;
     bool _EtatReserve;
     std::unique_ptr<Piece> _reserve;
     std::unique_ptr<Piece> _pieceactu;
     double _old_y_pos;
     Position _posPieceActu;



      QSoundEffect _bumpsfx;
      QSoundEffect _posesfx;


    //Primitives
     normale CalculerNormale(point s0, point s1, point s2);
     GLvoid AfficheCube(couleur coul);
     GLvoid AfficheMatrice(const Matrice3D & mat);
     GLvoid AfficheFils(couleur coul);
     GLvoid AfficheMatriceAvecCadrillage(const Matrice3D & mat);
     GLvoid AfficherCadrillagePlateau(const Matrice3D & m);
     GLvoid TranslateCouleurs(couleur c);
     GLvoid TranslateNombre(int i);


    //Fonctions d'affichage du jeu
     GLvoid AfficherPlateau();
     GLvoid AfficherBordPlateau();
     GLvoid AfficherPieceActuelle();
     GLvoid AfficherSuivants();
     GLvoid AfficherReserve();
     GLvoid AfficherCartonPause();
     GLvoid AfficherScore();
     GLvoid AfficherNiveau();


 virtual void keyPressEvent(QKeyEvent *e)override;



protected:
     //Methode de rendu OpenGl
     void initializeGL();
     void resizeGL(int w, int h);
     void paintGL();



signals:

   void JeuFinit( bool & b);
    void JeuPause(bool & b);
    void AboutScore(int & n);
    void AboutNiveau(int & n);


    void Jouer();
    void Quitter();
    void Recommencer();
    void Pause();
    void UseReserve();
    void Fin(int p);


    void aboutPLateau(Matrice3D & m);
    void  AboutSuivant(std::vector<std::unique_ptr<Piece>>& suiv);

     void AboutPieceActuelle(std::unique_ptr<Piece> & pa);
     void AboutPositionPieceActuelle(Position &p);

    void  ReserveState( bool  &b);
    void AboutReserve( std::unique_ptr<Piece> &reserve);
    void AboutTempDescente(long long & td);

    void Deplacement(DIRECTION_MOUVEMENT d);
    void Rotation(DIRECTION_ROT r);



public slots:

    void Bump_sfx();
    void Pose_sfx();


    void OnCamRightPressed();
    void OnCamLeftPressed();
    void OnCamForwardPressed();
    void OnCamBackwardPressed();

    void OnMouvBackwardPressed();
    void OnMouvForwardPressed();
    void OnMouvLeftPressed();
    void OnMouvRightPressed();
    void OnMouvDownPressed();

    void OnRotXRightPressed();
    void OnRotXLeftPressed();
    void OnRotYRightPressed();
    void OnRotYLeftPressed();
    void OnRotZLeftPressed();
    void OnRotZRightPressed();

    void OnReservePressed();
    void OnPausePressed();


};

