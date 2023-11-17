#pragma once

#include <QStackedWidget>


enum class TetrisClassicDifficulty{Facile, Normal, Difficile, Master};
enum class TetrisClassicGameSet{OldSchool, OldSchoolPlus, Classic, AllStars};
enum class PlayerNumber {P1, P2};

namespace Ui {
class MainMenu;
}


class MainMenu : public QStackedWidget
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = nullptr);
    ~MainMenu();

    void construct();


private:
    Ui::MainMenu *ui;

    void LoadUserKeybind1PlayerSettings();
    void LoadUserKeybind2PlayerSettings();
    void LoadUserAudioSettings();
    void LoadDefaultKeybind1PlayerSettings();
    void LoadDefaultKeybind2PlayerSettings();
    void LoadDefaultAudioSettings();


signals:

    void JeuTetrisClassique(TetrisClassicDifficulty difficulty, TetrisClassicGameSet gameset, int size_x, int size_y, int size_z);
    void Jeu2PlayerVersusTetris(TetrisClassicDifficulty difficulty, TetrisClassicGameSet gameset, int size_x, int size_y, int size_z);

    void getUserKeySequenceOf(QString s, QKeySequence & qks);
    void getUserSliderValueOf(QString s, int & value);
    void isThisRadioUserChecked(QString s, bool & value);
    void getDefaultKeySequenceOf(QString s, QKeySequence & qks);
    void getDefaultSliderValueOf(QString s, int & value);
    void isThisRadioDefaultChecked(QString s, bool & value);

    void ChangeUserKeyBindOf(QString s, QKeySequence k);
    void ChangeUserSliderOf(QString s, int i);
    void ChangeUserCheckedBoxOf(QString s);

    void Default1PlayerKeyBindSettingsNowUserSettings();
    void Default2PlayerKeyBindSettingsNowUserSettings();
    void DefaultAudioSettingsNowUserSettings();

    void SettingsKeyBind1PlayerSaveOrder(); // signal envoyé pour demander la sauvegarder des settings et Keybind pour 1 joueur
    void SettingsKeyBind2PlayerSaveOrder(); // signal envoyé pour demander la sauvegarder des settings et Keybind pour 2 joueurs

    void SettingsAudioSaveOrder(); // signal envoyé pour demander la sauvegarder des settings Audio


private slots:
    //slots associés à la page du menu principale
    void onclickJeu_MainMenuPage();
    void onclickSettings_MainMenuPage();
    void onclickQuit_MainMenu();

    //slots associés à la page de paramètrage du jeu classic
    void onclickCancel_ClassicGamePage();
    void onclickDefault_ClassicGamePage();
    void onclickPlay_ClassicGamePage();

    //slots associés à la page des options
    void onclickGoToMenu_SettingsPage();
    void onclickCancel_SettingsPage();
    void onclickDefault_SettingsPage();
    void onclickApply_SettingsPage();

};

