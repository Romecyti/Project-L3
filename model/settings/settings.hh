#pragma once

#include <array>
#include <QtGui/QKeyEvent> // include pour l'enum class des "Key"

enum class GameAction { Reserve, Pause};
enum class CameraRotation { Right, Left, Forward, Backward};
enum class PieceMovement { Right, Left, Forward, Backward, Down};
enum class PieceRotation { Right, Left, Forward, Backward, TippingRight, TippingLeft};
enum class ForAndBackWardCameraSens { classic, Master};

enum class PieceRotation2Player {Right, Forward, TippingRight };
enum class Player {P1, P2};


class AlterableSettings;

class NonAlterableSettings
{
protected:
    //settings et keybinds pour 1 joueur
    std::array<Qt::Key,2> _GameKey;
    std::array<Qt::Key,4> _CameraRotation;
    std::array<Qt::Key,5> _PieceMovement;
    std::array<Qt::Key,6> _PieceRotation;

    int _CameraRightAndLeftSensitivity;
    ForAndBackWardCameraSens _CameraBackAndForwardSensitivity;

    //settings de l'audio
    int _AudioVolume;


    //settings et keybinds pour 2 joueurs
    Qt::Key _2PlayerPause;
    Qt::Key _2Player_1_Reserve;
    Qt::Key _2Player_2_Reserve;
    std::array<Qt::Key,4> _2Player_1_CameraRotation;
    std::array<Qt::Key,4> _2Player_2_CameraRotation;
    std::array<Qt::Key,5> _2Player_1_PieceMovement;
    std::array<Qt::Key,5> _2Player_2_PieceMovement;
    std::array<Qt::Key,3> _2Player_1_PieceRotation;
    std::array<Qt::Key,3> _2Player_2_PieceRotation;
    int _2Player_1_CameraRightAndLeftSensitivity;
    int _2Player_2_CameraRightAndLeftSensitivity;
    ForAndBackWardCameraSens _2Player_1_CameraBackAndForwardSensitivity;
    ForAndBackWardCameraSens _2Player_2_CameraBackAndForwardSensitivity;



public:
    NonAlterableSettings();
    NonAlterableSettings(NonAlterableSettings const & s);
    NonAlterableSettings(AlterableSettings const & s);

    //fonctions d'accès aux settings et keybinds pour 1 joueur
    Qt::Key getGameKeyOf(GameAction ga) const ;
    Qt::Key getCameraRotationKeyOf(CameraRotation cr) const;
    Qt::Key getPieceMovementKeyOf(PieceMovement pm) const;
    Qt::Key getPieceRotationKeyOf(PieceRotation pr) const;
    std::array<Qt::Key,2> getGameKeyArray() const;
    std::array<Qt::Key,4> getCameraRotationKeyArray() const;
    std::array<Qt::Key,5> getPieceMovementKeyArray() const;
    std::array<Qt::Key,6> getPieceRotationKeyArray() const;
    int getCameraRightAndLeftSensitivity() const;
    ForAndBackWardCameraSens getCameraForAndBackWardSensitivity() const;

    //fonctions d'accès aux settings audio
    int getAudioVolumeValue();

    //fonctions d'accès aux settings et keybinds pour 2 joueurs
    Qt::Key get2PlayerPauseGameKey()const;
    Qt::Key get2PlayerReserveGameKeyForPlayer(Player p);
    Qt::Key get2PlayerCameraRotationKeyBindOfForPlayer(CameraRotation cr, Player p);
    Qt::Key get2PlayerPieceMovementKeyBindOfForPlayer(PieceMovement pm, Player p);
    Qt::Key get2PlayerPieceRotationKeyBindOfForPlayer(PieceRotation2Player pr, Player p);
    std::array<Qt::Key,4> get2PlayerCameraRotationKeyArrayForPlayer(Player p) const;
    std::array<Qt::Key,5> get2PlayerPieceMovementKeyArrayForPlayer(Player p) const;
    std::array<Qt::Key,3> get2PlayerPieceRotationKeyArrayForPlayer(Player p) const;
    int get2PlayerCameraRightAndLeftSensitivityForPlayer(Player p) const;
    ForAndBackWardCameraSens get2PlayerCameraForAndBackWardSensitivityForPlayer(Player p) const;

};

class AlterableSettings : public NonAlterableSettings
{
public:
    AlterableSettings();
    AlterableSettings(NonAlterableSettings const & nas);
    AlterableSettings(AlterableSettings const & as);

    //fonctions de modifications des settings et keybinds pour 1 joueur
    void setGameKeyOf(GameAction ga, Qt::Key qk);
    void setCameraRotationKeyOf(CameraRotation cr, Qt::Key qk);
    void setPieceMovementKeyOf(PieceMovement pm, Qt::Key qk);
    void setPieceRotationKeyOf(PieceRotation pr, Qt::Key qk);
    void setGameKeyArray(std::array<Qt::Key,2> newarray);
    void setCameraRotationKeyArray(std::array<Qt::Key,4> newarray);
    void setPieceMovementKeyArray(std::array<Qt::Key,5> newarray);
    void setPieceRotationKeyArray(std::array<Qt::Key,6> newarray);
    void setCameraRightAndLeftSensitivity(int sensi);
    void setCameraForAndBackWardSensitivity(ForAndBackWardCameraSens sensi);

    //fonction de modification des settings pour l'audio
    void setAudioVolume(int volume);

    //fonctions de modifications des settings et keybinds pour 2 joueurs
    void set2PlayerPauseKey(Qt::Key qk);
    void set2PlayerReserveKeyForPlayer(Qt::Key qk, Player p);
    void set2PlayerCameraRotationKeyOfForPlayer(CameraRotation cr, Qt::Key qk, Player p);
    void set2PlayerPieceMovementKeyOfForPlayer(PieceMovement pm, Qt::Key qk, Player p);
    void set2PlayerPieceRotationKeyOfForPlayer(PieceRotation2Player pr, Qt::Key qk, Player p);
    void set2PlayerCameraRotationKeyArrayForPlayer(std::array<Qt::Key,4> newarray, Player p);
    void set2PlayerPieceMovementKeyArrayForPlayer(std::array<Qt::Key,5> newarray, Player p);
    void set2PlayerPieceRotationKeyArrayForPlayer(std::array<Qt::Key,3> newarray, Player p);
    void set2PlayerCameraRightAndLeftSensitivityForPlayer(int sensi, Player p);
    void set2PlayerCameraForAndBackWardSensitivityForPlayer(ForAndBackWardCameraSens sensi, Player p);

};













