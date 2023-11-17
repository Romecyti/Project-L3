#include "vue_tetris_c.h"

VueTetrisC::VueTetrisC(NonAlterableSettings set, QWidget *parent):QStackedWidget (parent),_jeu(set,parent),_resultat(parent),_InputPressed(15,false),_lecteur(this,QMediaPlayer::StreamPlayback)
{


    _ploop.addMedia(QUrl("qrc:/ressources/music2.mp3"));
    _ploop.setPlaybackMode(QMediaPlaylist::Loop);
    _lecteur.setPlaylist(&_ploop);

    _options=set;

    _lecteur.setVolume(_options.getAudioVolumeValue());


    _lecteur.play();

    this->addWidget(&_jeu);
    this->addWidget(&_resultat);
    this->setCurrentIndex(0);
    this->setMinimumSize(800,800);

    _options=set;

    connect(&_jeu,&TetrisClassiqueOpenGl::Fin,this,&VueTetrisC::Ecranresultat);



}

const TetrisClassiqueOpenGl &VueTetrisC::GetJeu() const
{
    return  _jeu;
}

const TetrisClassiqueResultats  &VueTetrisC::GetResultat() const
{
    return  _resultat;
}

void VueTetrisC::reset()
{

    setCurrentIndex(0);
    this->setFocus();
    _lecteur.play();
}

void VueTetrisC::Ecranresultat(int p)
{
    resetKeys();
    _lecteur.stop();
    int etage=0;
    emit AboutNbEtageDetruit(etage);
    _resultat.Resultat(p,etage);

    this->setCurrentIndex(1);
    _resultat.setFocus();
   // std::cout<<this->currentIndex();

}





void VueTetrisC::resetKeys()
{
    for(unsigned int i(0);i<_InputPressed.size();i++)
    {
        _InputPressed.at(i)=false;
    }
}

void VueTetrisC::keyPressEvent(QKeyEvent *e)
{



        if( e->key()==_options.getCameraRotationKeyOf(CameraRotation::Right) )//0
            _InputPressed.at(0)=true;
        else  if( e->key()==_options.getCameraRotationKeyOf(CameraRotation::Left) )//1
            _InputPressed.at(1)=true;
        else  if( e->key()==_options.getCameraRotationKeyOf(CameraRotation::Forward) )//2
            _InputPressed.at(2)=true;
        else if( e->key()==_options.getCameraRotationKeyOf(CameraRotation::Backward) )//3
            _InputPressed.at(3)=true;

        else if( e->key()==_options.getPieceMovementKeyOf(PieceMovement::Backward) )//4
            _InputPressed.at(4)=true;
        else if( e->key()==_options.getPieceMovementKeyOf(PieceMovement::Forward) )//5
            _InputPressed.at(5)=true;
        else if( e->key()==_options.getPieceMovementKeyOf(PieceMovement::Left))//6
            _InputPressed.at(6)=true;
        else if( e->key()==_options.getPieceMovementKeyOf(PieceMovement::Right) )//7
            _InputPressed.at(7)=true;
        else if( e->key()==_options.getPieceMovementKeyOf(PieceMovement::Down) )//8
            _InputPressed.at(8)=true;

        else if( e->key()==_options.getPieceRotationKeyOf(PieceRotation::Backward) )//9
            _InputPressed.at(9)=true;
        else if( e->key()==_options.getPieceRotationKeyOf(PieceRotation::Forward) )//10
            _InputPressed.at(10)=true;
        else if( e->key()==_options.getPieceRotationKeyOf(PieceRotation::Right) )//11
            _InputPressed.at(11)=true;
        else if( e->key()==_options.getPieceRotationKeyOf(PieceRotation::Left) )//12
            _InputPressed.at(12)=true;
        else if( e->key()==_options.getPieceRotationKeyOf(PieceRotation::TippingLeft) )//13
            _InputPressed.at(13)=true;
        else if( e->key()==_options.getPieceRotationKeyOf(PieceRotation::TippingRight) )//14
            _InputPressed.at(14)=true;

        else if( e->key()==_options.getGameKeyOf(GameAction::Reserve) )//15
            _jeu.OnReservePressed();
        else if( e->key()==_options.getGameKeyOf(GameAction::Pause)  )//16
           _jeu.OnPausePressed();




        if(_InputPressed.at(0)){
           _jeu. OnCamRightPressed();


        }
        if (_InputPressed.at(1)) {
           _jeu.OnCamLeftPressed();
        }
        if (_InputPressed.at(2)) {
            _jeu.OnCamForwardPressed();

        }
        if(_InputPressed.at(3)){
           _jeu. OnCamBackwardPressed();
        }
        if(_InputPressed.at(4)){
            _jeu.OnMouvBackwardPressed();
        }
        if(_InputPressed.at(5)){
           _jeu. OnMouvForwardPressed();
        }
        if(_InputPressed.at(6)){
           _jeu. OnMouvLeftPressed();
        }
        if(_InputPressed.at(7)){
          _jeu. OnMouvRightPressed();
        }
        if(_InputPressed.at(8)){
           _jeu. OnMouvDownPressed();
        }
        if(_InputPressed.at(9)){
           _jeu. OnRotXRightPressed();
        }
        if(_InputPressed.at(10)){
           _jeu. OnRotXLeftPressed();
        }
        if(_InputPressed.at(11)){
           _jeu. OnRotYRightPressed();
        }
        if(_InputPressed.at(12)){
          _jeu. OnRotYLeftPressed();
        }
        if(_InputPressed.at(13)){
            _jeu.OnRotZLeftPressed();
        }
        if(_InputPressed.at(14)){
            _jeu.OnRotZRightPressed();
        }




}


void VueTetrisC::keyReleaseEvent(QKeyEvent *e)
{
    if( e->key()==_options.getCameraRotationKeyOf(CameraRotation::Right) )//0
        _InputPressed.at(0)=false;
    else  if( e->key()==_options.getCameraRotationKeyOf(CameraRotation::Left) )//1
        _InputPressed.at(1)=false;
    else  if( e->key()==_options.getCameraRotationKeyOf(CameraRotation::Forward) )//2
        _InputPressed.at(2)=false;
    else if( e->key()==_options.getCameraRotationKeyOf(CameraRotation::Backward) )//3
        _InputPressed.at(3)=false;

    else if( e->key()==_options.getPieceMovementKeyOf(PieceMovement::Backward) )//4
        _InputPressed.at(4)=false;
    else if( e->key()==_options.getPieceMovementKeyOf(PieceMovement::Forward) )//5
        _InputPressed.at(5)=false;
    else if( e->key()==_options.getPieceMovementKeyOf(PieceMovement::Left))//6
        _InputPressed.at(6)=false;
    else if( e->key()==_options.getPieceMovementKeyOf(PieceMovement::Right) )//7
        _InputPressed.at(7)=false;
    else if( e->key()==_options.getPieceMovementKeyOf(PieceMovement::Down) )//8
        _InputPressed.at(8)=false;

    else if( e->key()==_options.getPieceRotationKeyOf(PieceRotation::Backward) )//9
        _InputPressed.at(9)=false;
    else if( e->key()==_options.getPieceRotationKeyOf(PieceRotation::Forward) )//10
        _InputPressed.at(10)=false;
    else if( e->key()==_options.getPieceRotationKeyOf(PieceRotation::Right) )//11
        _InputPressed.at(11)=false;
    else if( e->key()==_options.getPieceRotationKeyOf(PieceRotation::Left) )//12
        _InputPressed.at(12)=false;
    else if( e->key()==_options.getPieceRotationKeyOf(PieceRotation::TippingLeft) )//13
        _InputPressed.at(13)=false;
    else if( e->key()==_options.getPieceRotationKeyOf(PieceRotation::TippingRight) )//14
        _InputPressed.at(14)=false;
}
