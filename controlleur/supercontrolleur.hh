#pragma once
#include <QtWidgets>
#include "lescontrolleurs.hh"
#include "../model/settings/settings_controller.hh"

class SuperControlleur : public QWidget
{
    Q_OBJECT
private:
    Controlleur* _controlleur;

    SettingsController _settingsControle;


    QGridLayout _lay;

   // virtual void keyPressEvent(QKeyEvent *e)override{std::cout<<"Bad Focus \n";};

public:
    SuperControlleur(QWidget *parent = nullptr);
    ~SuperControlleur();

signals:

public slots:
    void ChangeControlleur(controlleurs c);

    void LoadMenuControlleur();

    // slots associés aux signaux du menu

    void playTetrisClassique(TetrisClassicDifficulty difficulty, TetrisClassicGameSet gameset, int size_x, int size_y, int size_z);
    void Play2PlayerVersusTetris(TetrisClassicDifficulty difficulty, TetrisClassicGameSet gameset, int size_x, int size_y, int size_z);

    void GetUserSettings(NonAlterableSettings & userSettings);
    void GetDefaultSettings(NonAlterableSettings & defaultSettings);
    void ChangeUser1PlayerKeybindSettingsValidationOrder(AlterableSettings NewUserSettings);
    void ChangeUser2PlayerKeybindSettingsValidationOrder(AlterableSettings NewUserSettings);
    void ChangeUserAudioSettingsValidationOrder(AlterableSettings NewUserSettings);

};

