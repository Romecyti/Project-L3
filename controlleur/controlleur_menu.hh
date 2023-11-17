#pragma once
#include"controlleur.hh"

#include "../model/settings/settings.hh"
#include "../vue/vue_mainmenu.hh"


class ControlleurMenu:public Controlleur
{
    Q_OBJECT
private:
    NonAlterableSettings _UserValidateSettings;
    NonAlterableSettings _defaultSettings;

    AlterableSettings _NewUserSettings;

    MainMenu _mainmenu;

public:
   ControlleurMenu(NonAlterableSettings usersettings, NonAlterableSettings defaultsettings, QWidget * ptr=nullptr);

    QWidget * getvu();

public slots:
   virtual void ChangeControlleur() override;

   void JeuTetrisClassique(TetrisClassicDifficulty difficulty, TetrisClassicGameSet gameset, int size_x, int size_y, int size_z);
   void Jeu2PlayerVersusTetris(TetrisClassicDifficulty difficulty, TetrisClassicGameSet gameset, int size_x, int size_y, int size_z);
   //slots pour la page de settings de keybinding
   void getUserKeySequenceOf(QString s, QKeySequence & qks);
   void getUserSliderValueOf(QString s, int & value);
   void isThisRadioUserChecked(QString s, bool & value);
   void getDefaultKeySequenceOf(QString s, QKeySequence & qks);
   void getDefaultSliderValueOf(QString s, int & value);
   void isThisRadioDefaultChecked(QString s, bool & value);

   void Default1PlayerKeyBindSettingsNowUserSettings();
   void ChangeUserKeyBindOf(QString s, QKeySequence k);
   void ChangeUserSliderOf(QString s, int i);
   void ChangeUserCheckedBoxOf(QString s);

   void Default2PlayerKeyBindSettingsNowUserSettings();

   void DefaultAudioSettingsNowUserSettings();

   //slots de validation des settings
   void SettingsKeyBind1PlayerSaveOrder();
   void SettingsKeyBind2PlayerSaveOrder();
   void SettingsAudioSaveOrder();


signals:
   void GetUserSettings(NonAlterableSettings & userSettings);
   void GetDefaultSettings(NonAlterableSettings & defaultSettings);

   void playTetrisClassique(TetrisClassicDifficulty difficulty, TetrisClassicGameSet gameset, int size_x, int size_y, int size_z);
   void Play2PlayerVersusTetris(TetrisClassicDifficulty difficulty, TetrisClassicGameSet gameset, int size_x, int size_y, int size_z);
   void ChangeUser1PlayerKeybindSettingsValidationOrder(AlterableSettings NewUserSettings);
   void ChangeUser2PlayerKeybindSettingsValidationOrder(AlterableSettings NewUserSettings);
   void ChangeUserAudioSettingsValidationOrder(AlterableSettings NewUserSettings);


};

