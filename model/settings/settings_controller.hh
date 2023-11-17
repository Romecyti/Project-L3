#pragma once

#include "settings.hh"
#include "settings_exceptions.h"
#include <QSettings>

class SettingsController : public QSettings
{
private:
    AlterableSettings _DefaultSettings;
    AlterableSettings _UserSettings;

    void createSettingsFile();

    void modifSettingsFile();

    void loadDefaultSettings();
    void loadUserSettings();



public:
    SettingsController(QObject * Parent);

    //fonctions de modif des settings et keybinds pour 1 joueur
    /*
    void ChangeUserGameKeyOf(GameAction ga, Qt::Key qk);
    void ChangeUserCameraRorationKeyOf(CameraRotation cr, Qt::Key qk);
    void ChangeUserPieceMovementKeyOf(PieceMovement pm, Qt::Key qk);
    void ChangeUserPieceRotationKeyOf(PieceRotation pr, Qt::Key qk);
    void ChangeUserCameraRightAndLeftSensitivity(int sensi);
    void ChangeUserCameraForAndBackWardSensitivity(ForAndBackWardCameraSens fbs);
    */


    NonAlterableSettings getDefaultSettings();
    NonAlterableSettings getUserSettings();

    void ValidateUserKeyBindSettings(AlterableSettings & newUserKeyBind);
    void ValidateUserAudioSettings(AlterableSettings & newUserKeyBind);
    void ValidateUser2PlayerKeyBindSettings(AlterableSettings & newUserKeyBind);

};
