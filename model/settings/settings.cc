#include "settings.hh"

//non alterable settings Class

NonAlterableSettings::NonAlterableSettings()
{
    //initialisation des keybinds et settings pour 1 joueur
    for (unsigned long i(0); i < _GameKey.size(); i ++) {
        _GameKey[i] = Qt::Key::Key_unknown;
    }
    for (unsigned long i(0); i < _CameraRotation.size(); i ++) {
        _CameraRotation[i] = Qt::Key::Key_unknown;
    }
    for (unsigned long i(0); i < _PieceMovement.size(); i ++) {
        _PieceMovement[i] = Qt::Key::Key_unknown;
    }
    for (unsigned long i(0); i < _PieceRotation.size(); i ++) {
        _PieceRotation[i] = Qt::Key::Key_unknown;
    }
    _CameraRightAndLeftSensitivity = 5;
    _CameraBackAndForwardSensitivity = ForAndBackWardCameraSens::classic;

    //initialisation des settings pour l'audio
    _AudioVolume = 100;

    //initialisation des settings et keybinds pour 2 joueurs
    _2PlayerPause = Qt::Key::Key_unknown;
    _2Player_1_Reserve = Qt::Key::Key_unknown;
    _2Player_2_Reserve = Qt::Key::Key_unknown;

    for (unsigned long i(0); i < _2Player_1_CameraRotation.size(); i ++) {
        _2Player_1_CameraRotation[i] = Qt::Key::Key_unknown;
    }
    for (unsigned long i(0); i < _2Player_2_CameraRotation.size(); i ++) {
        _2Player_2_CameraRotation[i] = Qt::Key::Key_unknown;
    }
    for (unsigned long i(0); i < _2Player_1_PieceMovement.size(); i ++) {
        _2Player_1_PieceMovement[i] = Qt::Key::Key_unknown;
    }
    for (unsigned long i(0); i < _2Player_2_PieceMovement.size(); i ++) {
        _2Player_2_PieceMovement[i] = Qt::Key::Key_unknown;
    }
    for (unsigned long i(0); i < _2Player_1_PieceRotation.size(); i ++) {
        _2Player_1_PieceRotation[i] = Qt::Key::Key_unknown;
    }
    for (unsigned long i(0); i < _2Player_2_PieceRotation.size(); i ++) {
        _2Player_2_PieceRotation[i] = Qt::Key::Key_unknown;
    }

    _2Player_1_CameraRightAndLeftSensitivity = 5;
    _2Player_2_CameraRightAndLeftSensitivity = 5;

    _2Player_1_CameraBackAndForwardSensitivity = ForAndBackWardCameraSens::classic;
    _2Player_2_CameraBackAndForwardSensitivity = ForAndBackWardCameraSens::classic;
}

NonAlterableSettings::NonAlterableSettings(const NonAlterableSettings &s): _GameKey(s._GameKey),
    _CameraRotation(s._CameraRotation), _PieceMovement(s._PieceMovement),
    _PieceRotation(s._PieceRotation),_CameraRightAndLeftSensitivity(s._CameraRightAndLeftSensitivity),
    _CameraBackAndForwardSensitivity(s._CameraBackAndForwardSensitivity), _AudioVolume(s._AudioVolume),
    _2PlayerPause(s._2PlayerPause),_2Player_1_Reserve(s._2Player_1_Reserve),_2Player_2_Reserve(s._2Player_2_Reserve),
    _2Player_1_CameraRotation(s._2Player_1_CameraRotation),_2Player_2_CameraRotation(s._2Player_2_CameraRotation),
    _2Player_1_PieceMovement(s._2Player_1_PieceMovement),_2Player_2_PieceMovement(s._2Player_2_PieceMovement),
    _2Player_1_PieceRotation(s._2Player_1_PieceRotation),_2Player_2_PieceRotation(s._2Player_2_PieceRotation),
    _2Player_1_CameraRightAndLeftSensitivity(s._2Player_1_CameraRightAndLeftSensitivity),_2Player_2_CameraRightAndLeftSensitivity(s._2Player_2_CameraRightAndLeftSensitivity),
    _2Player_1_CameraBackAndForwardSensitivity(s._2Player_1_CameraBackAndForwardSensitivity),_2Player_2_CameraBackAndForwardSensitivity(s._2Player_2_CameraBackAndForwardSensitivity){}

NonAlterableSettings::NonAlterableSettings(const AlterableSettings &s): _GameKey(s._GameKey),
    _CameraRotation(s._CameraRotation), _PieceMovement(s._PieceMovement),
    _PieceRotation(s._PieceRotation),_CameraRightAndLeftSensitivity(s._CameraRightAndLeftSensitivity),
    _CameraBackAndForwardSensitivity(s._CameraBackAndForwardSensitivity), _AudioVolume(s._AudioVolume),
    _2PlayerPause(s._2PlayerPause),_2Player_1_Reserve(s._2Player_1_Reserve),_2Player_2_Reserve(s._2Player_2_Reserve),
    _2Player_1_CameraRotation(s._2Player_1_CameraRotation),_2Player_2_CameraRotation(s._2Player_2_CameraRotation),
    _2Player_1_PieceMovement(s._2Player_1_PieceMovement),_2Player_2_PieceMovement(s._2Player_2_PieceMovement),
    _2Player_1_PieceRotation(s._2Player_1_PieceRotation),_2Player_2_PieceRotation(s._2Player_2_PieceRotation),
    _2Player_1_CameraRightAndLeftSensitivity(s._2Player_1_CameraRightAndLeftSensitivity),_2Player_2_CameraRightAndLeftSensitivity(s._2Player_2_CameraRightAndLeftSensitivity),
    _2Player_1_CameraBackAndForwardSensitivity(s._2Player_1_CameraBackAndForwardSensitivity),_2Player_2_CameraBackAndForwardSensitivity(s._2Player_2_CameraBackAndForwardSensitivity){}


//fonctions d'accès aux settings et keybinds pour 1 joueur

Qt::Key NonAlterableSettings::getGameKeyOf(GameAction ga) const
{
    switch (ga) {
    case GameAction::Reserve :
        return _GameKey[0];
    case GameAction::Pause :
        return _GameKey[1];
    }
    return Qt::Key::Key_unknown;
}

Qt::Key NonAlterableSettings::getCameraRotationKeyOf(CameraRotation cr) const
{
    switch (cr) {
    case CameraRotation::Right :
        return _CameraRotation[0];
    case CameraRotation::Left :
        return _CameraRotation[1];
    case CameraRotation::Forward :
        return _CameraRotation[2];
    case CameraRotation::Backward :
        return _CameraRotation[3];
    }
    return Qt::Key::Key_unknown;

}

Qt::Key NonAlterableSettings::getPieceMovementKeyOf(PieceMovement pm) const
{
    switch (pm) {
    case PieceMovement::Right :
        return _PieceMovement[0];
    case PieceMovement::Left :
        return _PieceMovement[1];
    case PieceMovement::Forward :
        return _PieceMovement[2];
    case PieceMovement::Backward :
        return _PieceMovement[3];
    case PieceMovement::Down :
        return _PieceMovement[4];
    }
    return Qt::Key::Key_unknown;
}

Qt::Key NonAlterableSettings::getPieceRotationKeyOf(PieceRotation pr) const
{
    switch (pr) {
    case PieceRotation::Right :
        return _PieceRotation[0];
    case PieceRotation::Left :
        return _PieceRotation[1];
    case PieceRotation::Forward :
        return _PieceRotation[2];
    case PieceRotation::Backward :
        return _PieceRotation[3];
    case PieceRotation::TippingRight :
        return _PieceRotation[4];
    case PieceRotation::TippingLeft :
        return _PieceRotation[5];
    }
    return Qt::Key::Key_unknown;
}

int NonAlterableSettings::getCameraRightAndLeftSensitivity() const
{
    return _CameraRightAndLeftSensitivity;
}

ForAndBackWardCameraSens NonAlterableSettings::getCameraForAndBackWardSensitivity() const
{
    return _CameraBackAndForwardSensitivity;
}

std::array<Qt::Key,2> NonAlterableSettings::getGameKeyArray() const
{
    return _GameKey;
}

std::array<Qt::Key,4> NonAlterableSettings::getCameraRotationKeyArray() const
{
    return _CameraRotation;
}

std::array<Qt::Key,5> NonAlterableSettings::getPieceMovementKeyArray() const
{
    return _PieceMovement;
}

std::array<Qt::Key,6> NonAlterableSettings::getPieceRotationKeyArray() const
{
    return _PieceRotation;
}

//fonctions d'accès aux settings audio
int NonAlterableSettings::getAudioVolumeValue()
{
    return _AudioVolume;
}

//fonctions d'accès aux settings et keybinds pour 2 joueurs
Qt::Key NonAlterableSettings::get2PlayerPauseGameKey() const
{
    return _2PlayerPause;
}

Qt::Key NonAlterableSettings::get2PlayerReserveGameKeyForPlayer(Player p)
{
    switch (p) {
    case Player::P1 :
        return _2Player_1_Reserve;
    case Player::P2 :
        return _2Player_2_Reserve;
    }
    return Qt::Key::Key_unknown;
}

Qt::Key NonAlterableSettings::get2PlayerCameraRotationKeyBindOfForPlayer(CameraRotation cr, Player p)
{
    switch (p) {
    case Player::P1 :
        switch (cr) {
        case CameraRotation::Right :
            return _2Player_1_CameraRotation[0];
        case CameraRotation::Left :
            return _2Player_1_CameraRotation[1];
        case CameraRotation::Forward :
            return _2Player_1_CameraRotation[2];
        case CameraRotation::Backward :
            return _2Player_1_CameraRotation[3];
        }
    case Player::P2 :
        switch (cr) {
        case CameraRotation::Right :
            return _2Player_2_CameraRotation[0];
        case CameraRotation::Left :
            return _2Player_2_CameraRotation[1];
        case CameraRotation::Forward :
            return _2Player_2_CameraRotation[2];
        case CameraRotation::Backward :
            return _2Player_2_CameraRotation[3];
        }
    }
    return Qt::Key::Key_unknown;
}

Qt::Key NonAlterableSettings::get2PlayerPieceMovementKeyBindOfForPlayer(PieceMovement pm, Player p)
{
    switch (p) {
    case Player::P1 :
        switch (pm) {
        case PieceMovement::Right :
            return _2Player_1_PieceMovement[0];
        case PieceMovement::Left :
            return _2Player_1_PieceMovement[1];
        case PieceMovement::Forward :
            return _2Player_1_PieceMovement[2];
        case PieceMovement::Backward :
            return _2Player_1_PieceMovement[3];
        case PieceMovement::Down :
            return _2Player_1_PieceMovement[4];
        }
    case Player::P2 :
        switch (pm) {
        case PieceMovement::Right :
            return _2Player_2_PieceMovement[0];
        case PieceMovement::Left :
            return _2Player_2_PieceMovement[1];
        case PieceMovement::Forward :
            return _2Player_2_PieceMovement[2];
        case PieceMovement::Backward :
            return _2Player_2_PieceMovement[3];
        case PieceMovement::Down :
            return _2Player_2_PieceMovement[4];
        }
    }
    return Qt::Key::Key_unknown;
}

Qt::Key NonAlterableSettings::get2PlayerPieceRotationKeyBindOfForPlayer(PieceRotation2Player pr, Player p)
{
    switch (p) {
    case Player::P1 :
        switch (pr) {
        case PieceRotation2Player::Right:
            return _2Player_1_PieceRotation[0];
        case PieceRotation2Player::Forward:
            return _2Player_1_PieceRotation[1];
        case PieceRotation2Player::TippingRight:
            return _2Player_1_PieceRotation[2];
        }
    case Player::P2 :
        switch (pr) {
        case PieceRotation2Player::Right:
            return _2Player_2_PieceRotation[0];
        case PieceRotation2Player::Forward:
            return _2Player_2_PieceRotation[1];
        case PieceRotation2Player::TippingRight:
            return _2Player_2_PieceRotation[2];
        }
    }
    return Qt::Key::Key_unknown;
}

std::array<Qt::Key, 4> NonAlterableSettings::get2PlayerCameraRotationKeyArrayForPlayer(Player p) const
{
    if(p == Player::P2){
        return _2Player_2_CameraRotation;
    }

    return _2Player_1_CameraRotation;

}

std::array<Qt::Key, 5> NonAlterableSettings::get2PlayerPieceMovementKeyArrayForPlayer(Player p) const
{
    if(p == Player::P2){
        return _2Player_2_PieceMovement;
    }

    return _2Player_1_PieceMovement;
}

std::array<Qt::Key, 3> NonAlterableSettings::get2PlayerPieceRotationKeyArrayForPlayer(Player p) const
{
    if(p == Player::P2){
        return _2Player_2_PieceRotation;
    }
    return _2Player_1_PieceRotation;
}

int NonAlterableSettings::get2PlayerCameraRightAndLeftSensitivityForPlayer(Player p) const
{
    if(p == Player::P2){
        return _2Player_2_CameraRightAndLeftSensitivity;
    }
    return _2Player_1_CameraRightAndLeftSensitivity;
}

ForAndBackWardCameraSens NonAlterableSettings::get2PlayerCameraForAndBackWardSensitivityForPlayer(Player p) const
{
    if(p == Player::P2){
        return _2Player_2_CameraBackAndForwardSensitivity;
    }
    return _2Player_1_CameraBackAndForwardSensitivity;
}

//fonctions d'accès aux settings et keybinds pour 2 joueurs




//alterable settings Class

AlterableSettings::AlterableSettings():NonAlterableSettings(){}

AlterableSettings::AlterableSettings(const NonAlterableSettings &nas):NonAlterableSettings(nas){}

AlterableSettings::AlterableSettings(const AlterableSettings &as):NonAlterableSettings(as){}

//fonctions de modifications des settings et keybinds pour 1 joueur
void AlterableSettings::setGameKeyOf(GameAction ga, Qt::Key qk)
{
    switch (ga) {
    case GameAction::Reserve :
        _GameKey[0] = qk;
        break;
    case GameAction::Pause :
        _GameKey[1] = qk;
        break;
    }
}

void AlterableSettings::setCameraRotationKeyOf(CameraRotation cr, Qt::Key qk)
{
    switch (cr) {
    case CameraRotation::Right :
        _CameraRotation[0] = qk;
        break;
    case CameraRotation::Left :
        _CameraRotation[1] = qk;
        break;
    case CameraRotation::Forward :
        _CameraRotation[2] = qk;
        break;
    case CameraRotation::Backward :
        _CameraRotation[3] = qk;
        break;
    }
}

void AlterableSettings::setPieceMovementKeyOf(PieceMovement pm, Qt::Key qk)
{
    switch (pm) {
    case PieceMovement::Right :
        _PieceMovement[0] = qk;
        break;
    case PieceMovement::Left :
        _PieceMovement[1] = qk;
        break;
    case PieceMovement::Forward :
        _PieceMovement[2] = qk;
        break;
    case PieceMovement::Backward :
        _PieceMovement[3] = qk;
        break;
    case PieceMovement::Down :
        _PieceMovement[4] = qk;
        break;
    }
}

void AlterableSettings::setPieceRotationKeyOf(PieceRotation pr, Qt::Key qk)
{
    switch (pr) {
    case PieceRotation::Right :
        _PieceRotation[0] = qk;
        break;
    case PieceRotation::Left :
        _PieceRotation[1] = qk;
        break;
    case PieceRotation::Forward :
        _PieceRotation[2] = qk;
        break;
    case PieceRotation::Backward :
        _PieceRotation[3] = qk;
        break;
    case PieceRotation::TippingRight :
        _PieceRotation[4] = qk;
        break;
    case PieceRotation::TippingLeft :
        _PieceRotation[5] = qk;
        break;
    }
}

void AlterableSettings::setGameKeyArray(std::array<Qt::Key, 2> newarray)
{
    _GameKey = newarray;
}

void AlterableSettings::setCameraRotationKeyArray(std::array<Qt::Key, 4> newarray)
{
    _CameraRotation = newarray;
}

void AlterableSettings::setPieceMovementKeyArray(std::array<Qt::Key, 5> newarray)
{
    _PieceMovement = newarray;
}

void AlterableSettings::setPieceRotationKeyArray(std::array<Qt::Key, 6> newarray)
{
    _PieceRotation = newarray;
}

void AlterableSettings::setCameraRightAndLeftSensitivity(int sensi)
{
    _CameraRightAndLeftSensitivity = sensi;
}

void AlterableSettings::setCameraForAndBackWardSensitivity(ForAndBackWardCameraSens sensi)
{
    _CameraBackAndForwardSensitivity = sensi;
}

//fonction de modification des settings pour l'audio
void AlterableSettings::setAudioVolume(int volume)
{
    _AudioVolume = volume;
}

//fonctions de modifications des settings et keybinds pour 2 joueurs
void AlterableSettings::set2PlayerPauseKey(Qt::Key qk)
{
    _2PlayerPause = qk;
}

void AlterableSettings::set2PlayerReserveKeyForPlayer(Qt::Key qk, Player p)
{
    switch (p) {
    case Player::P1 :
        _2Player_1_Reserve = qk;
        break;
    case Player::P2 :
        _2Player_2_Reserve = qk;
        break;
    }
}

void AlterableSettings::set2PlayerCameraRotationKeyOfForPlayer(CameraRotation cr, Qt::Key qk, Player p)
{
    switch (p) {
    case Player::P1:
        switch (cr) {
        case CameraRotation::Right :
            _2Player_1_CameraRotation[0] = qk;
            break;
        case CameraRotation::Left :
            _2Player_1_CameraRotation[1] = qk;
            break;
        case CameraRotation::Forward :
            _2Player_1_CameraRotation[2] = qk;
            break;
        case CameraRotation::Backward :
            _2Player_1_CameraRotation[3] = qk;
            break;
        }
        break;
    case Player::P2:
        switch (cr) {
        case CameraRotation::Right :
            _2Player_2_CameraRotation[0] = qk;
            break;
        case CameraRotation::Left :
            _2Player_2_CameraRotation[1] = qk;
            break;
        case CameraRotation::Forward :
            _2Player_2_CameraRotation[2] = qk;
            break;
        case CameraRotation::Backward :
            _2Player_2_CameraRotation[3] = qk;
            break;
        }
        break;
    }
}

void AlterableSettings::set2PlayerPieceMovementKeyOfForPlayer(PieceMovement pm, Qt::Key qk, Player p)
{
    switch (p) {
    case Player::P1:
        switch (pm) {
        case PieceMovement::Right :
            _2Player_1_PieceMovement[0] = qk;
            break;
        case PieceMovement::Left :
            _2Player_1_PieceMovement[1] = qk;
            break;
        case PieceMovement::Forward :
            _2Player_1_PieceMovement[2] = qk;
            break;
        case PieceMovement::Backward :
            _2Player_1_PieceMovement[3] = qk;
            break;
        case PieceMovement::Down :
            _2Player_1_PieceMovement[4] = qk;
            break;
        }
        break;
    case Player::P2:
        switch (pm) {
        case PieceMovement::Right :
            _2Player_2_PieceMovement[0] = qk;
            break;
        case PieceMovement::Left :
            _2Player_2_PieceMovement[1] = qk;
            break;
        case PieceMovement::Forward :
            _2Player_2_PieceMovement[2] = qk;
            break;
        case PieceMovement::Backward :
            _2Player_2_PieceMovement[3] = qk;
            break;
        case PieceMovement::Down :
            _2Player_2_PieceMovement[4] = qk;
            break;
        }
        break;
    }
}

void AlterableSettings::set2PlayerPieceRotationKeyOfForPlayer(PieceRotation2Player pr, Qt::Key qk, Player p)
{
    switch (p) {
    case Player::P1:
        switch (pr) {
        case PieceRotation2Player::Right:
            _2Player_1_PieceRotation[0]=qk;
            break;
        case PieceRotation2Player::Forward:
            _2Player_1_PieceRotation[1]=qk;
            break;
        case PieceRotation2Player::TippingRight:
            _2Player_1_PieceRotation[2]=qk;
            break;
        }
        break;
    case Player::P2:
        switch (pr) {
        case PieceRotation2Player::Right:
            _2Player_2_PieceRotation[0]=qk;
            break;
        case PieceRotation2Player::Forward:
            _2Player_2_PieceRotation[1]=qk;
            break;
        case PieceRotation2Player::TippingRight:
            _2Player_2_PieceRotation[2]=qk;
            break;
        }
        break;
    }
}

void AlterableSettings::set2PlayerCameraRotationKeyArrayForPlayer(std::array<Qt::Key, 4> newarray, Player p)
{
    switch (p) {
    case Player::P1:
        _2Player_1_CameraRotation = newarray;
        break;
    case Player::P2:
        _2Player_2_CameraRotation = newarray;
        break;
    }
}

void AlterableSettings::set2PlayerPieceMovementKeyArrayForPlayer(std::array<Qt::Key, 5> newarray, Player p)
{
    switch (p) {
    case Player::P1:
        _2Player_1_PieceMovement = newarray;
        break;
    case Player::P2:
        _2Player_2_PieceMovement = newarray;
        break;
    }
}

void AlterableSettings::set2PlayerPieceRotationKeyArrayForPlayer(std::array<Qt::Key, 3> newarray, Player p)
{
    switch (p) {
    case Player::P1:
        _2Player_1_PieceRotation = newarray;
        break;
    case Player::P2:
        _2Player_2_PieceRotation = newarray;
        break;
    }
}

void AlterableSettings::set2PlayerCameraRightAndLeftSensitivityForPlayer(int sensi, Player p)
{
    switch (p) {
    case Player::P1:
        _2Player_1_CameraRightAndLeftSensitivity = sensi;
        break;
    case Player::P2:
        _2Player_2_CameraRightAndLeftSensitivity = sensi;
        break;
    }
}

void AlterableSettings::set2PlayerCameraForAndBackWardSensitivityForPlayer(ForAndBackWardCameraSens sensi, Player p)
{
    switch (p) {
    case Player::P1:
        _2Player_1_CameraBackAndForwardSensitivity = sensi;
        break;
    case Player::P2:
        _2Player_2_CameraBackAndForwardSensitivity = sensi;
        break;
    }
}
