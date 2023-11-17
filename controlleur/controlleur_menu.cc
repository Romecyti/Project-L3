#include "controlleur_menu.hh"

ControlleurMenu::ControlleurMenu(NonAlterableSettings usersettings, NonAlterableSettings defaultsettings,QWidget *ptr):
    _UserValidateSettings(usersettings), _defaultSettings(defaultsettings) , _NewUserSettings(), _mainmenu(ptr)
{
    _NewUserSettings = _UserValidateSettings;

    //connects des slots aux signaux de la vue
    connect(&_mainmenu,&MainMenu::JeuTetrisClassique,this,&ControlleurMenu::JeuTetrisClassique);
    connect(&_mainmenu,&MainMenu::Jeu2PlayerVersusTetris,this,&ControlleurMenu::Jeu2PlayerVersusTetris);

    connect(&_mainmenu,&MainMenu::getUserKeySequenceOf,this,&ControlleurMenu::getUserKeySequenceOf);
    connect(&_mainmenu,&MainMenu::getUserSliderValueOf,this,&ControlleurMenu::getUserSliderValueOf);
    connect(&_mainmenu,&MainMenu::isThisRadioUserChecked,this,&ControlleurMenu::isThisRadioUserChecked);
    connect(&_mainmenu,&MainMenu::getDefaultKeySequenceOf,this,&ControlleurMenu::getDefaultKeySequenceOf);
    connect(&_mainmenu,&MainMenu::getDefaultSliderValueOf,this,&ControlleurMenu::getDefaultSliderValueOf);
    connect(&_mainmenu,&MainMenu::isThisRadioDefaultChecked,this,&ControlleurMenu::isThisRadioDefaultChecked);

    connect(&_mainmenu,&MainMenu::ChangeUserKeyBindOf,this,&ControlleurMenu::ChangeUserKeyBindOf);
    connect(&_mainmenu,&MainMenu::ChangeUserSliderOf,this,&ControlleurMenu::ChangeUserSliderOf);
    connect(&_mainmenu,&MainMenu::ChangeUserCheckedBoxOf,this,&ControlleurMenu::ChangeUserCheckedBoxOf);

    connect(&_mainmenu,&MainMenu::Default1PlayerKeyBindSettingsNowUserSettings,this,&ControlleurMenu::Default1PlayerKeyBindSettingsNowUserSettings);
    connect(&_mainmenu,&MainMenu::Default2PlayerKeyBindSettingsNowUserSettings,this,&ControlleurMenu::Default2PlayerKeyBindSettingsNowUserSettings);

    connect(&_mainmenu,&MainMenu::DefaultAudioSettingsNowUserSettings,this,&ControlleurMenu::DefaultAudioSettingsNowUserSettings);

    connect(&_mainmenu,&MainMenu::SettingsKeyBind1PlayerSaveOrder,this,&ControlleurMenu::SettingsKeyBind1PlayerSaveOrder);
    connect(&_mainmenu,&MainMenu::SettingsKeyBind2PlayerSaveOrder,this,&ControlleurMenu::SettingsKeyBind2PlayerSaveOrder);
    connect(&_mainmenu,&MainMenu::SettingsAudioSaveOrder,this,&ControlleurMenu::SettingsAudioSaveOrder);

    _mainmenu.construct();

}


QWidget *ControlleurMenu::getvu()
{
    return &_mainmenu;
}

void ControlleurMenu::ChangeControlleur()
{

}


//slots
void ControlleurMenu::JeuTetrisClassique(TetrisClassicDifficulty difficulty, TetrisClassicGameSet gameset, int size_x, int size_y, int size_z)
{
    emit playTetrisClassique(difficulty,gameset,size_x,size_y,size_z);
}

void ControlleurMenu::Jeu2PlayerVersusTetris(TetrisClassicDifficulty difficulty, TetrisClassicGameSet gameset, int size_x, int size_y, int size_z)
{
    emit Play2PlayerVersusTetris(difficulty, gameset, size_x, size_y, size_z);
}


//slots pour la page de settings de keybinding
void ControlleurMenu::getUserKeySequenceOf(QString s, QKeySequence &qks)
{
    //partie pour les keybind des settings pour 1 joueur
    if(s == "Reserve"){
        qks = _UserValidateSettings.getGameKeyOf(GameAction::Reserve);
    }
    else if (s == "Pause") {
        qks = _UserValidateSettings.getGameKeyOf(GameAction::Pause);
    }
    else if (s == "KeyCameraRightRotation") {
        qks = _UserValidateSettings.getCameraRotationKeyOf(CameraRotation::Right);
    }
    else if (s == "KeyCameraLeftRotation") {
        qks = _UserValidateSettings.getCameraRotationKeyOf(CameraRotation::Left);
    }
    else if (s == "KeyCameraForwardRotation") {
        qks = _UserValidateSettings.getCameraRotationKeyOf(CameraRotation::Forward);
    }
    else if (s == "KeyCameraBackwardRotation") {
        qks = _UserValidateSettings.getCameraRotationKeyOf(CameraRotation::Backward);
    }
    else if (s == "KeyPieceRightMovement") {
        qks = _UserValidateSettings.getPieceMovementKeyOf(PieceMovement::Right);
    }
    else if (s == "KeyPieceLeftMovement") {
        qks = _UserValidateSettings.getPieceMovementKeyOf(PieceMovement::Left);
    }
    else if (s == "KeyPieceForwardMovement") {
        qks = _UserValidateSettings.getPieceMovementKeyOf(PieceMovement::Forward);
    }
    else if (s == "KeyPieceBackwardMovement") {
        qks = _UserValidateSettings.getPieceMovementKeyOf(PieceMovement::Backward);
    }
    else if (s == "KeyPieceDownMovement") {
        qks = _UserValidateSettings.getPieceMovementKeyOf(PieceMovement::Down);
    }
    else if (s == "KeyPieceRightRotation") {
        qks = _UserValidateSettings.getPieceRotationKeyOf(PieceRotation::Right);
    }
    else if (s == "KeyPieceLeftRotation") {
        qks = _UserValidateSettings.getPieceRotationKeyOf(PieceRotation::Left);
    }
    else if (s == "KeyPieceForwardRotation") {
        qks = _UserValidateSettings.getPieceRotationKeyOf(PieceRotation::Forward);
    }
    else if (s == "KeyPieceBackwardRotation") {
        qks = _UserValidateSettings.getPieceRotationKeyOf(PieceRotation::Backward);
    }
    else if (s == "KeyPieceRightTippingRotation") {
        qks = _UserValidateSettings.getPieceRotationKeyOf(PieceRotation::TippingRight);
    }
    else if (s == "KeyPieceLeftTippingRotation") {
        qks = _UserValidateSettings.getPieceRotationKeyOf(PieceRotation::TippingLeft);
    }

    //partie pour les keybind des settings pour 2 joueurs
    else if (s == "_2Player_Pause") {
        qks = _UserValidateSettings.get2PlayerPauseGameKey();
    }
    else if (s == "_2Player_1_Reserve") {
        qks = _UserValidateSettings.get2PlayerReserveGameKeyForPlayer(Player::P1);
    }
    else if (s == "_2Player_2_Reserve") {
        qks = _UserValidateSettings.get2PlayerReserveGameKeyForPlayer(Player::P2);
    }
    else if (s == "_2Player_1_KeyCameraRightRotation") {
        qks = _UserValidateSettings.get2PlayerCameraRotationKeyBindOfForPlayer(CameraRotation::Right,Player::P1);
    }
    else if (s == "_2Player_2_KeyCameraRightRotation") {
        qks = _UserValidateSettings.get2PlayerCameraRotationKeyBindOfForPlayer(CameraRotation::Right,Player::P2);
    }
    else if (s == "_2Player_1_KeyCameraLeftRotation") {
        qks = _UserValidateSettings.get2PlayerCameraRotationKeyBindOfForPlayer(CameraRotation::Left,Player::P1);
    }
    else if (s == "_2Player_2_KeyCameraLeftRotation") {
        qks = _UserValidateSettings.get2PlayerCameraRotationKeyBindOfForPlayer(CameraRotation::Left,Player::P2);
    }
    else if (s == "_2Player_1_KeyCameraForwardRotation") {
        qks = _UserValidateSettings.get2PlayerCameraRotationKeyBindOfForPlayer(CameraRotation::Forward,Player::P1);
    }
    else if (s == "_2Player_2_KeyCameraForwardRotation") {
        qks = _UserValidateSettings.get2PlayerCameraRotationKeyBindOfForPlayer(CameraRotation::Forward,Player::P2);
    }
    else if (s == "_2Player_1_KeyCameraBackwardRotation") {
        qks = _UserValidateSettings.get2PlayerCameraRotationKeyBindOfForPlayer(CameraRotation::Backward,Player::P1);
    }
    else if (s == "_2Player_2_KeyCameraBackwardRotation") {
        qks = _UserValidateSettings.get2PlayerCameraRotationKeyBindOfForPlayer(CameraRotation::Backward,Player::P2);
    }
    else if (s == "_2Player_1_KeyPieceRightMovement") {
        qks = _UserValidateSettings.get2PlayerPieceMovementKeyBindOfForPlayer(PieceMovement::Right,Player::P1);
    }
    else if (s == "_2Player_2_KeyPieceRightMovement") {
        qks = _UserValidateSettings.get2PlayerPieceMovementKeyBindOfForPlayer(PieceMovement::Right,Player::P2);
    }
    else if (s == "_2Player_1_KeyPieceLeftMovement") {
        qks = _UserValidateSettings.get2PlayerPieceMovementKeyBindOfForPlayer(PieceMovement::Left,Player::P1);
    }
    else if (s == "_2Player_2_KeyPieceLeftMovement") {
        qks = _UserValidateSettings.get2PlayerPieceMovementKeyBindOfForPlayer(PieceMovement::Left,Player::P2);
    }
    else if (s == "_2Player_1_KeyPieceForwardMovement") {
        qks = _UserValidateSettings.get2PlayerPieceMovementKeyBindOfForPlayer(PieceMovement::Forward,Player::P1);
    }
    else if (s == "_2Player_2_KeyPieceForwardMovement") {
        qks = _UserValidateSettings.get2PlayerPieceMovementKeyBindOfForPlayer(PieceMovement::Forward,Player::P2);
    }
    else if (s == "_2Player_1_KeyPieceBackwardMovement") {
        qks = _UserValidateSettings.get2PlayerPieceMovementKeyBindOfForPlayer(PieceMovement::Backward,Player::P1);
    }
    else if (s == "_2Player_2_KeyPieceBackwardMovement") {
        qks = _UserValidateSettings.get2PlayerPieceMovementKeyBindOfForPlayer(PieceMovement::Backward,Player::P2);
    }
    else if (s == "_2Player_1_KeyPieceDownMovement") {
        qks = _UserValidateSettings.get2PlayerPieceMovementKeyBindOfForPlayer(PieceMovement::Down,Player::P1);
    }
    else if (s == "_2Player_2_KeyPieceDownMovement") {
        qks = _UserValidateSettings.get2PlayerPieceMovementKeyBindOfForPlayer(PieceMovement::Down,Player::P2);
    }
    else if (s == "_2Player_1_KeyPieceRightRotation") {
        qks = _UserValidateSettings.get2PlayerPieceRotationKeyBindOfForPlayer(PieceRotation2Player::Right,Player::P1);
    }
    else if (s == "_2Player_2_KeyPieceRightRotation") {
        qks = _UserValidateSettings.get2PlayerPieceRotationKeyBindOfForPlayer(PieceRotation2Player::Right,Player::P2);
    }
    else if (s == "_2Player_1_KeyPieceForwardRotation") {
        qks = _UserValidateSettings.get2PlayerPieceRotationKeyBindOfForPlayer(PieceRotation2Player::Forward,Player::P1);
    }
    else if (s == "_2Player_2_KeyPieceForwardRotation") {
        qks = _UserValidateSettings.get2PlayerPieceRotationKeyBindOfForPlayer(PieceRotation2Player::Forward,Player::P2);
    }
    else if (s == "_2Player_1_KeyPieceRightTippingRotation") {
        qks = _UserValidateSettings.get2PlayerPieceRotationKeyBindOfForPlayer(PieceRotation2Player::TippingRight,Player::P1);
    }
    else if (s == "_2Player_2_KeyPieceRightTippingRotation") {
        qks = _UserValidateSettings.get2PlayerPieceRotationKeyBindOfForPlayer(PieceRotation2Player::TippingRight,Player::P2);
    }



}

void ControlleurMenu::getUserSliderValueOf(QString s, int &value)
{
    if(s == "SliderCameraRightAndLeftRotationSpeed"){
        value = _UserValidateSettings.getCameraRightAndLeftSensitivity();
    }
    else if (s == "_2Player_1_SliderCameraRightAndLeftRotationSpeed") {
        value = _UserValidateSettings.get2PlayerCameraRightAndLeftSensitivityForPlayer(Player::P1);
    }
    else if (s == "_2Player_2_SliderCameraRightAndLeftRotationSpeed") {
        value = _UserValidateSettings.get2PlayerCameraRightAndLeftSensitivityForPlayer(Player::P2);
    }
    else if (s == "Slider_Audio_Volume") {
        value = _UserValidateSettings.getAudioVolumeValue();
    }
}

void ControlleurMenu::isThisRadioUserChecked(QString s, bool &value)
{
    if(s == "ClassicRotation"){
        if(_UserValidateSettings.getCameraForAndBackWardSensitivity() == ForAndBackWardCameraSens::classic){
            value = true;
        }
        else {
            value = false;
        }
    }
    else if(s == "MasterRotation"){
        if(_UserValidateSettings.getCameraForAndBackWardSensitivity() == ForAndBackWardCameraSens::Master){
            value = true;
        }
        else {
            value = false;
        }
    }
    else if (s == "_2Player_1_ClassicRotation") {
        if(_UserValidateSettings.get2PlayerCameraForAndBackWardSensitivityForPlayer(Player::P1) == ForAndBackWardCameraSens::classic){
            value = true;
        }
        else {
            value = false;
        }
    }
    else if (s == "_2Player_1_MasterRotation") {
        if(_UserValidateSettings.get2PlayerCameraForAndBackWardSensitivityForPlayer(Player::P1) == ForAndBackWardCameraSens::Master){
            value = true;
        }
        else {
            value = false;
        }
    }
    else if (s == "_2Player_2_ClassicRotation") {
        if(_UserValidateSettings.get2PlayerCameraForAndBackWardSensitivityForPlayer(Player::P2) == ForAndBackWardCameraSens::classic){
            value = true;
        }
        else {
            value = false;
        }
    }
    else if (s == "_2Player_2_MasterRotation") {
        if(_UserValidateSettings.get2PlayerCameraForAndBackWardSensitivityForPlayer(Player::P2) == ForAndBackWardCameraSens::Master){
            value = true;
        }
        else {
            value = false;
        }
    }
}


void ControlleurMenu::getDefaultKeySequenceOf(QString s, QKeySequence &qks)
{
    //partie pour les keybind des settings pour 1 joueur
    if(s == "Reserve"){
        qks = _defaultSettings.getGameKeyOf(GameAction::Reserve);
    }
    else if (s == "Pause") {
        qks = _defaultSettings.getGameKeyOf(GameAction::Pause);
    }
    else if (s == "KeyCameraRightRotation") {
        qks = _defaultSettings.getCameraRotationKeyOf(CameraRotation::Right);
    }
    else if (s == "KeyCameraLeftRotation") {
        qks = _defaultSettings.getCameraRotationKeyOf(CameraRotation::Left);
    }
    else if (s == "KeyCameraForwardRotation") {
        qks = _defaultSettings.getCameraRotationKeyOf(CameraRotation::Forward);
    }
    else if (s == "KeyCameraBackwardRotation") {
        qks = _defaultSettings.getCameraRotationKeyOf(CameraRotation::Backward);
    }
    else if (s == "KeyPieceRightMovement") {
        qks = _defaultSettings.getPieceMovementKeyOf(PieceMovement::Right);
    }
    else if (s == "KeyPieceLeftMovement") {
        qks = _defaultSettings.getPieceMovementKeyOf(PieceMovement::Left);
    }
    else if (s == "KeyPieceForwardMovement") {
        qks = _defaultSettings.getPieceMovementKeyOf(PieceMovement::Forward);
    }
    else if (s == "KeyPieceBackwardMovement") {
        qks = _defaultSettings.getPieceMovementKeyOf(PieceMovement::Backward);
    }
    else if (s == "KeyPieceDownMovement") {
        qks = _defaultSettings.getPieceMovementKeyOf(PieceMovement::Down);
    }
    else if (s == "KeyPieceRightRotation") {
        qks = _defaultSettings.getPieceRotationKeyOf(PieceRotation::Right);
    }
    else if (s == "KeyPieceLeftRotation") {
        qks = _defaultSettings.getPieceRotationKeyOf(PieceRotation::Left);
    }
    else if (s == "KeyPieceForwardRotation") {
        qks = _defaultSettings.getPieceRotationKeyOf(PieceRotation::Forward);
    }
    else if (s == "KeyPieceBackwardRotation") {
        qks = _defaultSettings.getPieceRotationKeyOf(PieceRotation::Backward);
    }
    else if (s == "KeyPieceRightTippingRotation") {
        qks = _defaultSettings.getPieceRotationKeyOf(PieceRotation::TippingRight);
    }
    else if (s == "KeyPieceLeftTippingRotation") {
        qks = _defaultSettings.getPieceRotationKeyOf(PieceRotation::TippingLeft);
    }

    //partie pour les keybind des settings pour 2 joueurs
    else if (s == "_2Player_Pause") {
        qks = _defaultSettings.get2PlayerPauseGameKey();
    }
    else if (s == "_2Player_1_Reserve") {
        qks = _defaultSettings.get2PlayerReserveGameKeyForPlayer(Player::P1);
    }
    else if (s == "_2Player_2_Reserve") {
        qks = _defaultSettings.get2PlayerReserveGameKeyForPlayer(Player::P2);
    }
    else if (s == "_2Player_1_KeyCameraRightRotation") {
        qks = _defaultSettings.get2PlayerCameraRotationKeyBindOfForPlayer(CameraRotation::Right,Player::P1);
    }
    else if (s == "_2Player_2_KeyCameraRightRotation") {
        qks = _defaultSettings.get2PlayerCameraRotationKeyBindOfForPlayer(CameraRotation::Right,Player::P2);
    }
    else if (s == "_2Player_1_KeyCameraLeftRotation") {
        qks = _defaultSettings.get2PlayerCameraRotationKeyBindOfForPlayer(CameraRotation::Left,Player::P1);
    }
    else if (s == "_2Player_2_KeyCameraLeftRotation") {
        qks = _defaultSettings.get2PlayerCameraRotationKeyBindOfForPlayer(CameraRotation::Left,Player::P2);
    }
    else if (s == "_2Player_1_KeyCameraForwardRotation") {
        qks = _defaultSettings.get2PlayerCameraRotationKeyBindOfForPlayer(CameraRotation::Forward,Player::P1);
    }
    else if (s == "_2Player_2_KeyCameraForwardRotation") {
        qks = _defaultSettings.get2PlayerCameraRotationKeyBindOfForPlayer(CameraRotation::Forward,Player::P2);
    }
    else if (s == "_2Player_1_KeyCameraBackwardRotation") {
        qks = _defaultSettings.get2PlayerCameraRotationKeyBindOfForPlayer(CameraRotation::Backward,Player::P1);
    }
    else if (s == "_2Player_2_KeyCameraBackwardRotation") {
        qks = _defaultSettings.get2PlayerCameraRotationKeyBindOfForPlayer(CameraRotation::Backward,Player::P2);
    }
    else if (s == "_2Player_1_KeyPieceRightMovement") {
        qks = _defaultSettings.get2PlayerPieceMovementKeyBindOfForPlayer(PieceMovement::Right,Player::P1);
    }
    else if (s == "_2Player_2_KeyPieceRightMovement") {
        qks = _defaultSettings.get2PlayerPieceMovementKeyBindOfForPlayer(PieceMovement::Right,Player::P2);
    }
    else if (s == "_2Player_1_KeyPieceLeftMovement") {
        qks = _defaultSettings.get2PlayerPieceMovementKeyBindOfForPlayer(PieceMovement::Left,Player::P1);
    }
    else if (s == "_2Player_2_KeyPieceLeftMovement") {
        qks = _defaultSettings.get2PlayerPieceMovementKeyBindOfForPlayer(PieceMovement::Left,Player::P2);
    }
    else if (s == "_2Player_1_KeyPieceForwardMovement") {
        qks = _defaultSettings.get2PlayerPieceMovementKeyBindOfForPlayer(PieceMovement::Forward,Player::P1);
    }
    else if (s == "_2Player_2_KeyPieceForwardMovement") {
        qks = _defaultSettings.get2PlayerPieceMovementKeyBindOfForPlayer(PieceMovement::Forward,Player::P2);
    }
    else if (s == "_2Player_1_KeyPieceBackwardMovement") {
        qks = _defaultSettings.get2PlayerPieceMovementKeyBindOfForPlayer(PieceMovement::Backward,Player::P1);
    }
    else if (s == "_2Player_2_KeyPieceBackwardMovement") {
        qks = _defaultSettings.get2PlayerPieceMovementKeyBindOfForPlayer(PieceMovement::Backward,Player::P2);
    }
    else if (s == "_2Player_1_KeyPieceDownMovement") {
        qks = _defaultSettings.get2PlayerPieceMovementKeyBindOfForPlayer(PieceMovement::Down,Player::P1);
    }
    else if (s == "_2Player_2_KeyPieceDownMovement") {
        qks = _defaultSettings.get2PlayerPieceMovementKeyBindOfForPlayer(PieceMovement::Down,Player::P2);
    }
    else if (s == "_2Player_1_KeyPieceRightRotation") {
        qks = _defaultSettings.get2PlayerPieceRotationKeyBindOfForPlayer(PieceRotation2Player::Right,Player::P1);
    }
    else if (s == "_2Player_2_KeyPieceRightRotation") {
        qks = _defaultSettings.get2PlayerPieceRotationKeyBindOfForPlayer(PieceRotation2Player::Right,Player::P2);
    }
    else if (s == "_2Player_1_KeyPieceForwardRotation") {
        qks = _defaultSettings.get2PlayerPieceRotationKeyBindOfForPlayer(PieceRotation2Player::Forward,Player::P1);
    }
    else if (s == "_2Player_2_KeyPieceForwardRotation") {
        qks = _defaultSettings.get2PlayerPieceRotationKeyBindOfForPlayer(PieceRotation2Player::Forward,Player::P2);
    }
    else if (s == "_2Player_1_KeyPieceRightTippingRotation") {
        qks = _defaultSettings.get2PlayerPieceRotationKeyBindOfForPlayer(PieceRotation2Player::TippingRight,Player::P1);
    }
    else if (s == "_2Player_2_KeyPieceRightTippingRotation") {
        qks = _defaultSettings.get2PlayerPieceRotationKeyBindOfForPlayer(PieceRotation2Player::TippingRight,Player::P2);
    }

}

void ControlleurMenu::getDefaultSliderValueOf(QString s, int &value)
{
    if(s == "SliderCameraRightAndLeftRotationSpeed"){
        value = _defaultSettings.getCameraRightAndLeftSensitivity();
    }
    else if (s == "_2Player_1_SliderCameraRightAndLeftRotationSpeed") {
        value = _defaultSettings.get2PlayerCameraRightAndLeftSensitivityForPlayer(Player::P1);
    }
    else if (s == "_2Player_2_SliderCameraRightAndLeftRotationSpeed") {
        value = _defaultSettings.get2PlayerCameraRightAndLeftSensitivityForPlayer(Player::P2);
    }
    else if (s == "Slider_Audio_Volume") {
        value = _defaultSettings.getAudioVolumeValue();
    }
}

void ControlleurMenu::isThisRadioDefaultChecked(QString s, bool &value)
{
    if(s == "ClassicRotation"){
        if(_defaultSettings.getCameraForAndBackWardSensitivity() == ForAndBackWardCameraSens::classic){
            value = true;
        }
        else {
            value = false;
        }
    }
    else if(s == "MasterRotation"){
        if(_defaultSettings.getCameraForAndBackWardSensitivity() == ForAndBackWardCameraSens::Master){
            value = true;
        }
        else {
            value = false;
        }
    }
    else if (s == "_2Player_1_ClassicRotation") {
        if(_defaultSettings.get2PlayerCameraForAndBackWardSensitivityForPlayer(Player::P1) == ForAndBackWardCameraSens::classic){
            value = true;
        }
        else {
            value = false;
        }
    }
    else if (s == "_2Player_1_MasterRotation") {
        if(_defaultSettings.get2PlayerCameraForAndBackWardSensitivityForPlayer(Player::P1) == ForAndBackWardCameraSens::Master){
            value = true;
        }
        else {
            value = false;
        }
    }
    else if (s == "_2Player_2_ClassicRotation") {
        if(_defaultSettings.get2PlayerCameraForAndBackWardSensitivityForPlayer(Player::P2) == ForAndBackWardCameraSens::classic){
            value = true;
        }
        else {
            value = false;
        }
    }
    else if (s == "_2Player_2_MasterRotation") {
        if(_defaultSettings.get2PlayerCameraForAndBackWardSensitivityForPlayer(Player::P2) == ForAndBackWardCameraSens::Master){
            value = true;
        }
        else {
            value = false;
        }
    }
}


void ControlleurMenu::ChangeUserKeyBindOf(QString s, QKeySequence k)
{
    Qt::Key qk(static_cast<Qt::Key>(k[0]));

    //partie pour la page des settings pour 1 joueur
    if(s == "Reserve"){
        _NewUserSettings.setGameKeyOf(GameAction::Reserve, qk);
    }
    else if (s == "Pause") {
        _NewUserSettings.setGameKeyOf(GameAction::Pause, qk);
    }
    else if (s == "KeyCameraRightRotation") {
        _NewUserSettings.setCameraRotationKeyOf(CameraRotation::Right, qk);
    }
    else if (s == "KeyCameraLeftRotation") {
        _NewUserSettings.setCameraRotationKeyOf(CameraRotation::Left, qk);
    }
    else if (s == "KeyCameraForwardRotation") {
        _NewUserSettings.setCameraRotationKeyOf(CameraRotation::Forward, qk);
    }
    else if (s == "KeyCameraBackwardRotation") {
        _NewUserSettings.setCameraRotationKeyOf(CameraRotation::Backward, qk);
    }
    else if (s == "KeyPieceRightMovement") {
        _NewUserSettings.setPieceMovementKeyOf(PieceMovement::Right, qk);
    }
    else if (s == "KeyPieceLeftMovement") {
        _NewUserSettings.setPieceMovementKeyOf(PieceMovement::Left, qk);
    }
    else if (s == "KeyPieceForwardMovement") {
        _NewUserSettings.setPieceMovementKeyOf(PieceMovement::Forward, qk);
    }
    else if (s == "KeyPieceBackwardMovement") {
        _NewUserSettings.setPieceMovementKeyOf(PieceMovement::Backward, qk);
    }
    else if (s == "KeyPieceDownMovement") {
        _NewUserSettings.setPieceMovementKeyOf(PieceMovement::Down, qk);
    }
    else if (s == "KeyPieceRightRotation") {
        _NewUserSettings.setPieceRotationKeyOf(PieceRotation::Right, qk);
    }
    else if (s == "KeyPieceLefttRotation") {
        _NewUserSettings.setPieceRotationKeyOf(PieceRotation::Left, qk);
    }
    else if (s == "KeyPieceForwardRotation") {
        _NewUserSettings.setPieceRotationKeyOf(PieceRotation::Forward, qk);
    }
    else if (s == "KeyPieceBackwardRotation") {
        _NewUserSettings.setPieceRotationKeyOf(PieceRotation::Backward, qk);
    }
    else if (s == "KeyPieceTippingRightRotation") {
        _NewUserSettings.setPieceRotationKeyOf(PieceRotation::TippingRight, qk);
    }
    else if (s == "KeyPieceTippingLeftRotation") {
        _NewUserSettings.setPieceRotationKeyOf(PieceRotation::TippingLeft, qk);
    }


    //partie pour les keybind des settings pour 2 joueurs
    else if (s == "_2Player_Pause") {
        _NewUserSettings.set2PlayerPauseKey(qk);
    }
    else if (s == "_2Player_1_Reserve") {
        _NewUserSettings.set2PlayerReserveKeyForPlayer(qk,Player::P1);
    }
    else if (s == "_2Player_2_Reserve") {
        _NewUserSettings.set2PlayerReserveKeyForPlayer(qk,Player::P2);
    }
    else if (s == "_2Player_1_KeyCameraRightRotation") {
        _NewUserSettings.set2PlayerCameraRotationKeyOfForPlayer(CameraRotation::Right,qk,Player::P1);
    }
    else if (s == "_2Player_2_KeyCameraRightRotation") {
        _NewUserSettings.set2PlayerCameraRotationKeyOfForPlayer(CameraRotation::Right,qk,Player::P2);
    }
    else if (s == "_2Player_1_KeyCameraLeftRotation") {
        _NewUserSettings.set2PlayerCameraRotationKeyOfForPlayer(CameraRotation::Left,qk,Player::P1);
    }
    else if (s == "_2Player_2_KeyCameraLeftRotation") {
        _NewUserSettings.set2PlayerCameraRotationKeyOfForPlayer(CameraRotation::Left,qk,Player::P2);
    }
    else if (s == "_2Player_1_KeyCameraForwardRotation") {
        _NewUserSettings.set2PlayerCameraRotationKeyOfForPlayer(CameraRotation::Forward,qk,Player::P1);
    }
    else if (s == "_2Player_2_KeyCameraForwardRotation") {
        _NewUserSettings.set2PlayerCameraRotationKeyOfForPlayer(CameraRotation::Forward,qk,Player::P2);
    }
    else if (s == "_2Player_1_KeyCameraBackwardRotation") {
        _NewUserSettings.set2PlayerCameraRotationKeyOfForPlayer(CameraRotation::Backward,qk,Player::P1);
    }
    else if (s == "_2Player_2_KeyCameraBackwardRotation") {
        _NewUserSettings.set2PlayerCameraRotationKeyOfForPlayer(CameraRotation::Backward,qk,Player::P2);
    }
    else if (s == "_2Player_1_KeyPieceRightMovement") {
        _NewUserSettings.set2PlayerPieceMovementKeyOfForPlayer(PieceMovement::Right,qk,Player::P1);
    }
    else if (s == "_2Player_2_KeyPieceRightMovement") {
        _NewUserSettings.set2PlayerPieceMovementKeyOfForPlayer(PieceMovement::Right,qk,Player::P2);
    }
    else if (s == "_2Player_1_KeyPieceLeftMovement") {
        _NewUserSettings.set2PlayerPieceMovementKeyOfForPlayer(PieceMovement::Left,qk,Player::P1);
    }
    else if (s == "_2Player_2_KeyPieceLeftMovement") {
        _NewUserSettings.set2PlayerPieceMovementKeyOfForPlayer(PieceMovement::Left,qk,Player::P2);
    }
    else if (s == "_2Player_1_KeyPieceForwardMovement") {
        _NewUserSettings.set2PlayerPieceMovementKeyOfForPlayer(PieceMovement::Forward,qk,Player::P1);
    }
    else if (s == "_2Player_2_KeyPieceForwardMovement") {
        _NewUserSettings.set2PlayerPieceMovementKeyOfForPlayer(PieceMovement::Forward,qk,Player::P2);
    }
    else if (s == "_2Player_1_KeyPieceBackwardMovement") {
        _NewUserSettings.set2PlayerPieceMovementKeyOfForPlayer(PieceMovement::Backward,qk,Player::P1);
    }
    else if (s == "_2Player_2_KeyPieceBackwardMovement") {
        _NewUserSettings.set2PlayerPieceMovementKeyOfForPlayer(PieceMovement::Backward,qk,Player::P2);
    }
    else if (s == "_2Player_1_KeyPieceDownMovement") {
        _NewUserSettings.set2PlayerPieceMovementKeyOfForPlayer(PieceMovement::Down,qk,Player::P1);
    }
    else if (s == "_2Player_2_KeyPieceDownMovement") {
        _NewUserSettings.set2PlayerPieceMovementKeyOfForPlayer(PieceMovement::Down,qk,Player::P2);
    }
    else if (s == "_2Player_1_KeyPieceRightRotation") {
        _NewUserSettings.set2PlayerPieceRotationKeyOfForPlayer(PieceRotation2Player::Right,qk,Player::P1);
    }
    else if (s == "_2Player_2_KeyPieceRightRotation") {
        _NewUserSettings.set2PlayerPieceRotationKeyOfForPlayer(PieceRotation2Player::Right,qk,Player::P2);
    }
    else if (s == "_2Player_1_KeyPieceForwardRotation") {
        _NewUserSettings.set2PlayerPieceRotationKeyOfForPlayer(PieceRotation2Player::Forward,qk,Player::P1);
    }
    else if (s == "_2Player_2_KeyPieceForwardRotation") {
        _NewUserSettings.set2PlayerPieceRotationKeyOfForPlayer(PieceRotation2Player::Forward,qk,Player::P2);
    }
    else if (s == "_2Player_1_KeyPieceRightTippingRotation") {
        _NewUserSettings.set2PlayerPieceRotationKeyOfForPlayer(PieceRotation2Player::TippingRight,qk,Player::P1);
    }
    else if (s == "_2Player_2_KeyPieceRightTippingRotation") {
        _NewUserSettings.set2PlayerPieceRotationKeyOfForPlayer(PieceRotation2Player::TippingRight,qk,Player::P2);
    }
}

void ControlleurMenu::ChangeUserSliderOf(QString s, int i)
{
    if(s == "SliderCameraRightAndLeftRotationSpeed"){
        _NewUserSettings.setCameraRightAndLeftSensitivity(i);
    }
    else if (s == "_2Player_1_SliderCameraRightAndLeftRotationSpeed") {
        _NewUserSettings.set2PlayerCameraRightAndLeftSensitivityForPlayer(i,Player::P1);
    }
    else if (s == "_2Player_2_SliderCameraRightAndLeftRotationSpeed") {
        _NewUserSettings.set2PlayerCameraRightAndLeftSensitivityForPlayer(i,Player::P2);
    }
    else if (s == "Slider_Audio_Volume") {
        _NewUserSettings.setAudioVolume(i);
    }

}

void ControlleurMenu::ChangeUserCheckedBoxOf(QString s)
{
    if(s == "ClassicRotation"){
        _NewUserSettings.setCameraForAndBackWardSensitivity(ForAndBackWardCameraSens::classic);
    }
    else if (s == "MasterRotation") {
        _NewUserSettings.setCameraForAndBackWardSensitivity(ForAndBackWardCameraSens::Master);
    }
    else if (s == "_2Player_1_ClassicRotation") {
        _NewUserSettings.set2PlayerCameraForAndBackWardSensitivityForPlayer(ForAndBackWardCameraSens::classic,Player::P1);
    }
    else if (s == "_2Player_1_MasterRotation") {
        _NewUserSettings.set2PlayerCameraForAndBackWardSensitivityForPlayer(ForAndBackWardCameraSens::Master,Player::P1);
    }
    else if (s == "_2Player_2_ClassicRotation") {
        _NewUserSettings.set2PlayerCameraForAndBackWardSensitivityForPlayer(ForAndBackWardCameraSens::classic,Player::P2);
    }
    else if (s == "_2Player_2_MasterRotation") {
        _NewUserSettings.set2PlayerCameraForAndBackWardSensitivityForPlayer(ForAndBackWardCameraSens::Master,Player::P2);
    }
}


void ControlleurMenu::Default1PlayerKeyBindSettingsNowUserSettings()
{
    _NewUserSettings.setGameKeyArray(_defaultSettings.getGameKeyArray());
    _NewUserSettings.setCameraRotationKeyArray(_defaultSettings.getCameraRotationKeyArray());
    _NewUserSettings.setPieceMovementKeyArray(_defaultSettings.getPieceMovementKeyArray());
    _NewUserSettings.setPieceRotationKeyArray(_defaultSettings.getPieceRotationKeyArray());
    _NewUserSettings.setCameraRightAndLeftSensitivity(_defaultSettings.getCameraRightAndLeftSensitivity());
    _NewUserSettings.setCameraForAndBackWardSensitivity(_defaultSettings.getCameraForAndBackWardSensitivity());

    emit ChangeUser1PlayerKeybindSettingsValidationOrder(_NewUserSettings);
    emit GetUserSettings(_UserValidateSettings);
}

void ControlleurMenu::Default2PlayerKeyBindSettingsNowUserSettings()
{
    _NewUserSettings.set2PlayerPauseKey(_defaultSettings.get2PlayerPauseGameKey());
    _NewUserSettings.set2PlayerReserveKeyForPlayer(_defaultSettings.get2PlayerReserveGameKeyForPlayer(Player::P1),Player::P1);
    _NewUserSettings.set2PlayerReserveKeyForPlayer(_defaultSettings.get2PlayerReserveGameKeyForPlayer(Player::P2),Player::P2);

    _NewUserSettings.set2PlayerCameraRotationKeyArrayForPlayer(_defaultSettings.get2PlayerCameraRotationKeyArrayForPlayer(Player::P1), Player::P1);
    _NewUserSettings.set2PlayerCameraRotationKeyArrayForPlayer(_defaultSettings.get2PlayerCameraRotationKeyArrayForPlayer(Player::P2), Player::P2);
    _NewUserSettings.set2PlayerPieceMovementKeyArrayForPlayer(_defaultSettings.get2PlayerPieceMovementKeyArrayForPlayer(Player::P1), Player::P1);
    _NewUserSettings.set2PlayerPieceMovementKeyArrayForPlayer(_defaultSettings.get2PlayerPieceMovementKeyArrayForPlayer(Player::P2), Player::P2);
    _NewUserSettings.set2PlayerPieceRotationKeyArrayForPlayer(_defaultSettings.get2PlayerPieceRotationKeyArrayForPlayer(Player::P1), Player::P1);
    _NewUserSettings.set2PlayerPieceRotationKeyArrayForPlayer(_defaultSettings.get2PlayerPieceRotationKeyArrayForPlayer(Player::P2), Player::P2);
    _NewUserSettings.set2PlayerCameraRightAndLeftSensitivityForPlayer(_defaultSettings.get2PlayerCameraRightAndLeftSensitivityForPlayer(Player::P1), Player::P1);
    _NewUserSettings.set2PlayerCameraRightAndLeftSensitivityForPlayer(_defaultSettings.get2PlayerCameraRightAndLeftSensitivityForPlayer(Player::P2), Player::P2);
    _NewUserSettings.set2PlayerCameraForAndBackWardSensitivityForPlayer(_defaultSettings.get2PlayerCameraForAndBackWardSensitivityForPlayer(Player::P1), Player::P1);
    _NewUserSettings.set2PlayerCameraForAndBackWardSensitivityForPlayer(_defaultSettings.get2PlayerCameraForAndBackWardSensitivityForPlayer(Player::P2), Player::P2);

    emit ChangeUser2PlayerKeybindSettingsValidationOrder(_NewUserSettings);
    emit GetUserSettings(_UserValidateSettings);
}

void ControlleurMenu::DefaultAudioSettingsNowUserSettings()
{
    _NewUserSettings.setAudioVolume(_defaultSettings.getAudioVolumeValue());
    emit ChangeUserAudioSettingsValidationOrder(_NewUserSettings);
    emit GetUserSettings(_UserValidateSettings);
}

//slots de validation des settings
void ControlleurMenu::SettingsKeyBind1PlayerSaveOrder()
{
    emit ChangeUser1PlayerKeybindSettingsValidationOrder(_NewUserSettings);
    emit GetUserSettings(_UserValidateSettings);

}

void ControlleurMenu::SettingsKeyBind2PlayerSaveOrder()
{
    emit ChangeUser2PlayerKeybindSettingsValidationOrder(_NewUserSettings);
    emit GetUserSettings(_UserValidateSettings);
}

void ControlleurMenu::SettingsAudioSaveOrder()
{
    emit ChangeUserAudioSettingsValidationOrder(_NewUserSettings);
    emit GetUserSettings(_UserValidateSettings);
}
