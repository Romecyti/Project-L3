#include "vuetetrismulti.hh"

VueTetrisMulti::VueTetrisMulti(NonAlterableSettings set, QWidget *parent):QStackedWidget (parent),_joueur1(set,parent),_joueur2(set,parent),_resultat(this),_InputPressed(24,false)
{
    _ploop.addMedia(QUrl("qrc:/ressources/music2.mp3"));
    _ploop.setPlaybackMode(QMediaPlaylist::Loop);
    _lecteur.setPlaylist(&_ploop);

    _options=set;

    _lecteur.setVolume(_options.getAudioVolumeValue());


    _lecteur.play();

    _alreadyfinish=false;
    w.setLayout(&_lay);
    _lay.addWidget(&_joueur1);
    _lay.addWidget(&_joueur2);


    this->addWidget(&w);
    this->addWidget(&_resultat);
    setCurrentIndex(0);
    this->setMinimumSize(1610,800);

    connect(&_joueur2,&TetrisClassiqueOpenGl::Fin,this,&VueTetrisMulti::EcranResultat);




}

const TetrisClassiqueOpenGl &VueTetrisMulti::GetJeu1() const
{
    return _joueur1;
}

const TetrisClassiqueOpenGl &VueTetrisMulti::GetJeu2() const
{
    return  _joueur2;
}

const ResultatTetrisMulti &VueTetrisMulti::GetResult() const
{
    return _resultat;
}

void VueTetrisMulti::reset()
{
    setCurrentIndex(0);
    setFocus();
    _alreadyfinish=false;
    _lecteur.play();
}

void VueTetrisMulti::EcranResultat()
{
    _lecteur.stop();
   if(!_alreadyfinish){
    _alreadyfinish=true;
    resetKeys();
    setCurrentIndex(1);
    int pj1;
    int pj2;

    int nej1;
    int nej2;

    emit resultat(pj1,pj2);
    emit nbEtagesDetruit(nej1,nej2);

    bool j1;
    emit Jeu1fini(j1);

if(j1)
    _resultat.Resultat(pj1,nej1,pj2,nej2,Gagnant::J2);
else
    _resultat.Resultat(pj1,nej1,pj2,nej2,Gagnant::J1);

}
}


void VueTetrisMulti::resetKeys()
{
    for(unsigned int i(0);i<_InputPressed.size();i++)
    {
        _InputPressed.at(i)=false;
    }
}

void VueTetrisMulti::keyPressEvent(QKeyEvent *e)
{


    //J1
    if( e->key()==_options.get2PlayerCameraRotationKeyBindOfForPlayer(CameraRotation::Right,Player::P1) )//0
        _InputPressed.at(0)=true;
    else  if( e->key()==_options.get2PlayerCameraRotationKeyBindOfForPlayer(CameraRotation::Left,Player::P1) )//1
        _InputPressed.at(1)=true;
    else  if( e->key()==_options.get2PlayerCameraRotationKeyBindOfForPlayer(CameraRotation::Forward,Player::P1) )//2
        _InputPressed.at(2)=true;
    else if( e->key()==_options.get2PlayerCameraRotationKeyBindOfForPlayer(CameraRotation::Backward,Player::P1) )//3
        _InputPressed.at(3)=true;

    else if( e->key()==_options.get2PlayerPieceMovementKeyBindOfForPlayer(PieceMovement::Backward,Player::P1) )//4
        _InputPressed.at(4)=true;
    else if( e->key()==_options.get2PlayerPieceMovementKeyBindOfForPlayer(PieceMovement::Forward,Player::P1) )//5
        _InputPressed.at(5)=true;
    else if( e->key()==_options.get2PlayerPieceMovementKeyBindOfForPlayer(PieceMovement::Left,Player::P1))//6
        _InputPressed.at(6)=true;
    else if( e->key()==_options.get2PlayerPieceMovementKeyBindOfForPlayer(PieceMovement::Right,Player::P1) )//7
        _InputPressed.at(7)=true;
    else if( e->key()==_options.get2PlayerPieceMovementKeyBindOfForPlayer(PieceMovement::Down,Player::P1) )//8
        _InputPressed.at(8)=true;

    else if( e->key()==_options.get2PlayerPieceRotationKeyBindOfForPlayer(PieceRotation2Player::Forward,Player::P1) )//9
        _InputPressed.at(9)=true;
    else if( e->key()==_options.get2PlayerPieceRotationKeyBindOfForPlayer(PieceRotation2Player::Right,Player::P1) )//10
        _InputPressed.at(10)=true;
    else if( e->key()==_options.get2PlayerPieceRotationKeyBindOfForPlayer(PieceRotation2Player::TippingRight,Player::P1) )//11
        _InputPressed.at(11)=true;
    else if( e->key()==_options.get2PlayerReserveGameKeyForPlayer(Player::P1) )//reserve J1
        _joueur1.OnReservePressed();

    //J2
    if( e->key()==_options.get2PlayerCameraRotationKeyBindOfForPlayer(CameraRotation::Right,Player::P2) )//12
        _InputPressed.at(12)=true;
    else  if( e->key()==_options.get2PlayerCameraRotationKeyBindOfForPlayer(CameraRotation::Left,Player::P2) )//13
        _InputPressed.at(13)=true;
    else  if( e->key()==_options.get2PlayerCameraRotationKeyBindOfForPlayer(CameraRotation::Forward,Player::P2) )//14
        _InputPressed.at(14)=true;
    else if( e->key()==_options.get2PlayerCameraRotationKeyBindOfForPlayer(CameraRotation::Backward,Player::P2) )//15
        _InputPressed.at(15)=true;

    else if( e->key()==_options.get2PlayerPieceMovementKeyBindOfForPlayer(PieceMovement::Backward,Player::P2) )//16
        _InputPressed.at(16)=true;
    else if( e->key()==_options.get2PlayerPieceMovementKeyBindOfForPlayer(PieceMovement::Forward,Player::P2) )//17
        _InputPressed.at(17)=true;
    else if( e->key()==_options.get2PlayerPieceMovementKeyBindOfForPlayer(PieceMovement::Left,Player::P2))//18
        _InputPressed.at(18)=true;
    else if( e->key()==_options.get2PlayerPieceMovementKeyBindOfForPlayer(PieceMovement::Right,Player::P2) )//19
        _InputPressed.at(19)=true;
    else if( e->key()==_options.get2PlayerPieceMovementKeyBindOfForPlayer(PieceMovement::Down,Player::P2) )//20
        _InputPressed.at(20)=true;

    else if( e->key()==_options.get2PlayerPieceRotationKeyBindOfForPlayer(PieceRotation2Player::Forward,Player::P2) )//21
        _InputPressed.at(21)=true;
    else if( e->key()==_options.get2PlayerPieceRotationKeyBindOfForPlayer(PieceRotation2Player::Right,Player::P2) )//22
        _InputPressed.at(22)=true;
    else if( e->key()==_options.get2PlayerPieceRotationKeyBindOfForPlayer(PieceRotation2Player::TippingRight,Player::P2) )//23
        _InputPressed.at(23)=true;
       else if( e->key()==_options.get2PlayerReserveGameKeyForPlayer(Player::P2) )//reserve J2
        _joueur2.OnReservePressed();




    else if( e->key()==_options.getGameKeyOf(GameAction::Pause)  )//pause
       _joueur1.OnPausePressed();



//------------------------------J1
    if(_InputPressed.at(0)){
       _joueur1. OnCamRightPressed();

    }
    if (_InputPressed.at(1)) {
       _joueur1.OnCamLeftPressed();
    }
    if (_InputPressed.at(2)) {
        _joueur1.OnCamForwardPressed();

    }
    if(_InputPressed.at(3)){
       _joueur1. OnCamBackwardPressed();
    }
    if(_InputPressed.at(4)){
        _joueur1.OnMouvBackwardPressed();
    }
    if(_InputPressed.at(5)){
       _joueur1. OnMouvForwardPressed();
    }
    if(_InputPressed.at(6)){
       _joueur1. OnMouvLeftPressed();
    }
    if(_InputPressed.at(7)){
      _joueur1. OnMouvRightPressed();
    }
    if(_InputPressed.at(8)){
       _joueur1. OnMouvDownPressed();
    }
    if(_InputPressed.at(9)){
       _joueur1. OnRotXRightPressed();
    }
    if(_InputPressed.at(10)){
       _joueur1. OnRotYRightPressed();
    }
    if(_InputPressed.at(11)){
        _joueur1.OnRotZRightPressed();
    }
//------------------------------J2
    if(_InputPressed.at(12)){
       _joueur2. OnCamRightPressed();

    }
    if (_InputPressed.at(13)) {
       _joueur2.OnCamLeftPressed();
    }
    if (_InputPressed.at(14)) {
        _joueur2.OnCamForwardPressed();

    }
    if(_InputPressed.at(15)){
       _joueur2. OnCamBackwardPressed();
    }
    if(_InputPressed.at(16)){
        _joueur2.OnMouvBackwardPressed();
    }
    if(_InputPressed.at(17)){
       _joueur2. OnMouvForwardPressed();
    }
    if(_InputPressed.at(18)){
       _joueur2. OnMouvLeftPressed();
    }
    if(_InputPressed.at(19)){
      _joueur2. OnMouvRightPressed();
    }
    if(_InputPressed.at(20)){
       _joueur2. OnMouvDownPressed();
    }
    if(_InputPressed.at(21)){
       _joueur2. OnRotXRightPressed();
    }
    if(_InputPressed.at(22)){
       _joueur2. OnRotYRightPressed();
    }
    if(_InputPressed.at(23)){
        _joueur2.OnRotZRightPressed();
    }
}

void VueTetrisMulti::keyReleaseEvent(QKeyEvent *e)
{
    //J1
    if( e->key()==_options.get2PlayerCameraRotationKeyBindOfForPlayer(CameraRotation::Right,Player::P1) )//0
        _InputPressed.at(0)=false;
    else  if( e->key()==_options.get2PlayerCameraRotationKeyBindOfForPlayer(CameraRotation::Left,Player::P1) )//1
        _InputPressed.at(1)=false;
    else  if( e->key()==_options.get2PlayerCameraRotationKeyBindOfForPlayer(CameraRotation::Forward,Player::P1) )//2
        _InputPressed.at(2)=false;
    else if( e->key()==_options.get2PlayerCameraRotationKeyBindOfForPlayer(CameraRotation::Backward,Player::P1) )//3
        _InputPressed.at(3)=false;

    else if( e->key()==_options.get2PlayerPieceMovementKeyBindOfForPlayer(PieceMovement::Backward,Player::P1) )//4
        _InputPressed.at(4)=false;
    else if( e->key()==_options.get2PlayerPieceMovementKeyBindOfForPlayer(PieceMovement::Forward,Player::P1) )//5
        _InputPressed.at(5)=false;
    else if( e->key()==_options.get2PlayerPieceMovementKeyBindOfForPlayer(PieceMovement::Left,Player::P1))//6
        _InputPressed.at(6)=false;
    else if( e->key()==_options.get2PlayerPieceMovementKeyBindOfForPlayer(PieceMovement::Right,Player::P1) )//7
        _InputPressed.at(7)=false;
    else if( e->key()==_options.get2PlayerPieceMovementKeyBindOfForPlayer(PieceMovement::Down,Player::P1) )//8
        _InputPressed.at(8)=false;

    else if( e->key()==_options.get2PlayerPieceRotationKeyBindOfForPlayer(PieceRotation2Player::Forward,Player::P1) )//9
        _InputPressed.at(9)=false;
    else if( e->key()==_options.get2PlayerPieceRotationKeyBindOfForPlayer(PieceRotation2Player::Right,Player::P1) )//10
        _InputPressed.at(10)=false;
    else if( e->key()==_options.get2PlayerPieceRotationKeyBindOfForPlayer(PieceRotation2Player::TippingRight,Player::P1) )//11
        _InputPressed.at(11)=false;

    //J2
    else if( e->key()==_options.get2PlayerCameraRotationKeyBindOfForPlayer(CameraRotation::Right,Player::P2) )//12
        _InputPressed.at(12)=false;
    else  if( e->key()==_options.get2PlayerCameraRotationKeyBindOfForPlayer(CameraRotation::Left,Player::P2) )//13
        _InputPressed.at(13)=false;
    else  if( e->key()==_options.get2PlayerCameraRotationKeyBindOfForPlayer(CameraRotation::Forward,Player::P2) )//14
        _InputPressed.at(14)=false;
    else if( e->key()==_options.get2PlayerCameraRotationKeyBindOfForPlayer(CameraRotation::Backward,Player::P2) )//15
        _InputPressed.at(15)=false;

    else if( e->key()==_options.get2PlayerPieceMovementKeyBindOfForPlayer(PieceMovement::Backward,Player::P2) )//16
        _InputPressed.at(16)=false;
    else if( e->key()==_options.get2PlayerPieceMovementKeyBindOfForPlayer(PieceMovement::Forward,Player::P2) )//17
        _InputPressed.at(17)=false;
    else if( e->key()==_options.get2PlayerPieceMovementKeyBindOfForPlayer(PieceMovement::Left,Player::P2))//18
        _InputPressed.at(18)=false;
    else if( e->key()==_options.get2PlayerPieceMovementKeyBindOfForPlayer(PieceMovement::Right,Player::P2) )//19
        _InputPressed.at(19)=false;
    else if( e->key()==_options.get2PlayerPieceMovementKeyBindOfForPlayer(PieceMovement::Down,Player::P2) )//20
        _InputPressed.at(20)=false;

    else if( e->key()==_options.get2PlayerPieceRotationKeyBindOfForPlayer(PieceRotation2Player::Forward,Player::P2) )//21
        _InputPressed.at(21)=false;
    else if( e->key()==_options.get2PlayerPieceRotationKeyBindOfForPlayer(PieceRotation2Player::Right,Player::P2) )//22
        _InputPressed.at(22)=false;
    else if( e->key()==_options.get2PlayerPieceRotationKeyBindOfForPlayer(PieceRotation2Player::TippingRight,Player::P2) )//23
        _InputPressed.at(23)=false;


}
