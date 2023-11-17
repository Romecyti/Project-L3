#include "vue_mainmenu.hh"
#include "ui_vue_mainmenu.h"

MainMenu::MainMenu(QWidget *parent) :
    QStackedWidget(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    this->setCurrentIndex(this->indexOf(ui->Main_Menu_Page));
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::construct()
{
    this->LoadUserKeybind1PlayerSettings();
    this->LoadUserKeybind2PlayerSettings();
    this->LoadUserAudioSettings();
}


//private methods

void MainMenu::LoadUserKeybind1PlayerSettings()
{
    QKeySequence KS;

    emit getUserKeySequenceOf(ui->Pause->objectName(), KS);
    ui->Pause->setKeySequence(KS);
    emit getUserKeySequenceOf(ui->Reserve->objectName(), KS);
    ui->Reserve->setKeySequence(KS);

    emit getUserKeySequenceOf(ui->KeyCameraRightRotation->objectName(), KS);
    ui->KeyCameraRightRotation->setKeySequence(KS);
    emit getUserKeySequenceOf(ui->KeyCameraLeftRotation->objectName(), KS);
    ui->KeyCameraLeftRotation->setKeySequence(KS);
    emit getUserKeySequenceOf(ui->KeyCameraForwardRotation->objectName(), KS);
    ui->KeyCameraForwardRotation->setKeySequence(KS);
    emit getUserKeySequenceOf(ui->KeyCameraBackwardRotation->objectName(), KS);
    ui->KeyCameraBackwardRotation->setKeySequence(KS);

    int slidevalue = ui->SliderCameraRightAndLeftRotationSpeed->minimum();
    emit getUserSliderValueOf(ui->SliderCameraRightAndLeftRotationSpeed->objectName(),slidevalue);
    ui->SliderCameraRightAndLeftRotationSpeed->setValue(slidevalue);

    bool classicVerticalRotation;
    emit isThisRadioUserChecked(ui->ClassicRotation->objectName(), classicVerticalRotation);
    if(classicVerticalRotation){
        ui->ClassicRotation->setChecked(true);
    }
    else {
        ui->MasterRotation->setChecked(true);
    }

    emit getUserKeySequenceOf(ui->KeyPieceRightMovement->objectName(), KS);
    ui->KeyPieceRightMovement->setKeySequence(KS);
    emit getUserKeySequenceOf(ui->KeyPieceLeftMovement->objectName(), KS);
    ui->KeyPieceLeftMovement->setKeySequence(KS);
    emit getUserKeySequenceOf(ui->KeyPieceForwardMovement->objectName(), KS);
    ui->KeyPieceForwardMovement->setKeySequence(KS);
    emit getUserKeySequenceOf(ui->KeyPieceBackwardMovement->objectName(), KS);
    ui->KeyPieceBackwardMovement->setKeySequence(KS);
    emit getUserKeySequenceOf(ui->KeyPieceDownMovement->objectName(), KS);
    ui->KeyPieceDownMovement->setKeySequence(KS);

    emit getUserKeySequenceOf(ui->KeyPieceRightRotation->objectName(), KS);
    ui->KeyPieceRightRotation->setKeySequence(KS);
    emit getUserKeySequenceOf(ui->KeyPieceLeftRotation->objectName(), KS);
    ui->KeyPieceLeftRotation->setKeySequence(KS);
    emit getUserKeySequenceOf(ui->KeyPieceForwardRotation->objectName(), KS);
    ui->KeyPieceForwardRotation->setKeySequence(KS);
    emit getUserKeySequenceOf(ui->KeyPieceBackwardRotation->objectName(), KS);
    ui->KeyPieceBackwardRotation->setKeySequence(KS);
    emit getUserKeySequenceOf(ui->KeyPieceRightTippingRotation->objectName(), KS);
    ui->KeyPieceRightTippingRotation->setKeySequence(KS);
    emit getUserKeySequenceOf(ui->KeyPieceLeftTippingRotation->objectName(), KS);
    ui->KeyPieceLeftTippingRotation->setKeySequence(KS);

}

void MainMenu::LoadUserKeybind2PlayerSettings()
{
    QKeySequence KS;
    emit getUserKeySequenceOf(ui->_2Player_Pause->objectName(),KS);
    ui->_2Player_Pause->setKeySequence(KS);

    emit getUserKeySequenceOf(ui->_2Player_1_Reserve->objectName(),KS);
    ui->_2Player_1_Reserve->setKeySequence(KS);
    emit getUserKeySequenceOf(ui->_2Player_2_Reserve->objectName(),KS);
    ui->_2Player_2_Reserve->setKeySequence(KS);

    emit getUserKeySequenceOf(ui->_2Player_1_KeyCameraRightRotation->objectName(),KS);
    ui->_2Player_1_KeyCameraRightRotation->setKeySequence(KS);
    emit getUserKeySequenceOf(ui->_2Player_2_KeyCameraRightRotation->objectName(),KS);
    ui->_2Player_2_KeyCameraRightRotation->setKeySequence(KS);
    emit getUserKeySequenceOf(ui->_2Player_1_KeyCameraLeftRotation->objectName(),KS);
    ui->_2Player_1_KeyCameraLeftRotation->setKeySequence(KS);
    emit getUserKeySequenceOf(ui->_2Player_2_KeyCameraLeftRotation->objectName(),KS);
    ui->_2Player_2_KeyCameraLeftRotation->setKeySequence(KS);
    emit getUserKeySequenceOf(ui->_2Player_1_KeyCameraForwardRotation->objectName(),KS);
    ui->_2Player_1_KeyCameraForwardRotation->setKeySequence(KS);
    emit getUserKeySequenceOf(ui->_2Player_2_KeyCameraForwardRotation->objectName(),KS);
    ui->_2Player_2_KeyCameraForwardRotation->setKeySequence(KS);
    emit getUserKeySequenceOf(ui->_2Player_1_KeyCameraBackwardRotation->objectName(),KS);
    ui->_2Player_1_KeyCameraBackwardRotation->setKeySequence(KS);
    emit getUserKeySequenceOf(ui->_2Player_2_KeyCameraBackwardRotation->objectName(),KS);
    ui->_2Player_2_KeyCameraBackwardRotation->setKeySequence(KS);

    int slidevalue = ui->_2Player_1_SliderCameraRightAndLeftRotationSpeed->minimum();
    emit getUserSliderValueOf(ui->_2Player_1_SliderCameraRightAndLeftRotationSpeed->objectName(),slidevalue);
    ui->_2Player_1_SliderCameraRightAndLeftRotationSpeed->setValue(slidevalue);
    emit getUserSliderValueOf(ui->_2Player_2_SliderCameraRightAndLeftRotationSpeed->objectName(),slidevalue);
    ui->_2Player_2_SliderCameraRightAndLeftRotationSpeed->setValue(slidevalue);

    bool classicVerticalRotation;
    emit isThisRadioUserChecked(ui->_2Player_1_ClassicRotation->objectName(), classicVerticalRotation);
    if(classicVerticalRotation){
        ui->_2Player_1_ClassicRotation->setChecked(true);
    }
    else {
        ui->_2Player_1_MasterRotation->setChecked(true);
    }
    emit isThisRadioUserChecked(ui->_2Player_2_ClassicRotation->objectName(), classicVerticalRotation);
    if(classicVerticalRotation){
        ui->_2Player_2_ClassicRotation->setChecked(true);
    }
    else {
        ui->_2Player_2_MasterRotation->setChecked(true);
    }


    emit getUserKeySequenceOf(ui->_2Player_1_KeyPieceRightMovement->objectName(), KS);
    ui->_2Player_1_KeyPieceRightMovement->setKeySequence(KS);
    emit getUserKeySequenceOf(ui->_2Player_2_KeyPieceRightMovement->objectName(), KS);
    ui->_2Player_2_KeyPieceRightMovement->setKeySequence(KS);
    emit getUserKeySequenceOf(ui->_2Player_1_KeyPieceLeftMovement->objectName(), KS);
    ui->_2Player_1_KeyPieceLeftMovement->setKeySequence(KS);
    emit getUserKeySequenceOf(ui->_2Player_2_KeyPieceLeftMovement->objectName(), KS);
    ui->_2Player_2_KeyPieceLeftMovement->setKeySequence(KS);
    emit getUserKeySequenceOf(ui->_2Player_1_KeyPieceForwardMovement->objectName(), KS);
    ui->_2Player_1_KeyPieceForwardMovement->setKeySequence(KS);
    emit getUserKeySequenceOf(ui->_2Player_2_KeyPieceForwardMovement->objectName(), KS);
    ui->_2Player_2_KeyPieceForwardMovement->setKeySequence(KS);
    emit getUserKeySequenceOf(ui->_2Player_1_KeyPieceBackwardMovement->objectName(), KS);
    ui->_2Player_1_KeyPieceBackwardMovement->setKeySequence(KS);
    emit getUserKeySequenceOf(ui->_2Player_2_KeyPieceBackwardMovement->objectName(), KS);
    ui->_2Player_2_KeyPieceBackwardMovement->setKeySequence(KS);
    emit getUserKeySequenceOf(ui->_2Player_1_KeyPieceDownMovement->objectName(), KS);
    ui->_2Player_1_KeyPieceDownMovement->setKeySequence(KS);
    emit getUserKeySequenceOf(ui->_2Player_2_KeyPieceDownMovement->objectName(), KS);
    ui->_2Player_2_KeyPieceDownMovement->setKeySequence(KS);


    emit getUserKeySequenceOf(ui->_2Player_1_KeyPieceRightRotation->objectName(), KS);
    ui->_2Player_1_KeyPieceRightRotation->setKeySequence(KS);
    emit getUserKeySequenceOf(ui->_2Player_2_KeyPieceRightRotation->objectName(), KS);
    ui->_2Player_2_KeyPieceRightRotation->setKeySequence(KS);
    emit getUserKeySequenceOf(ui->_2Player_1_KeyPieceForwardRotation->objectName(), KS);
    ui->_2Player_1_KeyPieceForwardRotation->setKeySequence(KS);
    emit getUserKeySequenceOf(ui->_2Player_2_KeyPieceForwardRotation->objectName(), KS);
    ui->_2Player_2_KeyPieceForwardRotation->setKeySequence(KS);
    emit getUserKeySequenceOf(ui->_2Player_1_KeyPieceRightTippingRotation->objectName(), KS);
    ui->_2Player_1_KeyPieceRightTippingRotation->setKeySequence(KS);
    emit getUserKeySequenceOf(ui->_2Player_2_KeyPieceRightTippingRotation->objectName(), KS);
    ui->_2Player_2_KeyPieceRightTippingRotation->setKeySequence(KS);
}

void MainMenu::LoadUserAudioSettings()
{
    int slidevalue = 100;
    emit getUserSliderValueOf(ui->Slider_Audio_Volume->objectName(),slidevalue);
    ui->Slider_Audio_Volume->setValue(slidevalue);
}

void MainMenu::LoadDefaultKeybind1PlayerSettings()
{
    QKeySequence KS;

    emit getDefaultKeySequenceOf(ui->Pause->objectName(), KS);
    ui->Pause->setKeySequence(KS);
    emit getDefaultKeySequenceOf(ui->Reserve->objectName(), KS);
    ui->Reserve->setKeySequence(KS);

    emit getDefaultKeySequenceOf(ui->KeyCameraRightRotation->objectName(), KS);
    ui->KeyCameraRightRotation->setKeySequence(KS);
    emit getDefaultKeySequenceOf(ui->KeyCameraLeftRotation->objectName(), KS);
    ui->KeyCameraLeftRotation->setKeySequence(KS);
    emit getDefaultKeySequenceOf(ui->KeyCameraForwardRotation->objectName(), KS);
    ui->KeyCameraForwardRotation->setKeySequence(KS);
    emit getDefaultKeySequenceOf(ui->KeyCameraBackwardRotation->objectName(), KS);
    ui->KeyCameraBackwardRotation->setKeySequence(KS);

    int slidevalue = ui->SliderCameraRightAndLeftRotationSpeed->minimum();
    emit getDefaultSliderValueOf(ui->SliderCameraRightAndLeftRotationSpeed->objectName(),slidevalue);
    ui->SliderCameraRightAndLeftRotationSpeed->setValue(slidevalue);

    bool classicVerticalRotation;
    emit isThisRadioDefaultChecked(ui->ClassicRotation->objectName(), classicVerticalRotation);
    if(classicVerticalRotation){
        ui->ClassicRotation->setChecked(true);
    }
    else {
        ui->MasterRotation->setChecked(true);
    }

    emit getDefaultKeySequenceOf(ui->KeyPieceRightMovement->objectName(), KS);
    ui->KeyPieceRightMovement->setKeySequence(KS);
    emit getDefaultKeySequenceOf(ui->KeyPieceLeftMovement->objectName(), KS);
    ui->KeyPieceLeftMovement->setKeySequence(KS);
    emit getDefaultKeySequenceOf(ui->KeyPieceForwardMovement->objectName(), KS);
    ui->KeyPieceForwardMovement->setKeySequence(KS);
    emit getDefaultKeySequenceOf(ui->KeyPieceBackwardMovement->objectName(), KS);
    ui->KeyPieceBackwardMovement->setKeySequence(KS);
    emit getDefaultKeySequenceOf(ui->KeyPieceDownMovement->objectName(), KS);
    ui->KeyPieceDownMovement->setKeySequence(KS);

    emit getDefaultKeySequenceOf(ui->KeyPieceRightRotation->objectName(), KS);
    ui->KeyPieceRightRotation->setKeySequence(KS);
    emit getDefaultKeySequenceOf(ui->KeyPieceLeftRotation->objectName(), KS);
    ui->KeyPieceLeftRotation->setKeySequence(KS);
    emit getDefaultKeySequenceOf(ui->KeyPieceForwardRotation->objectName(), KS);
    ui->KeyPieceForwardRotation->setKeySequence(KS);
    emit getDefaultKeySequenceOf(ui->KeyPieceBackwardRotation->objectName(), KS);
    ui->KeyPieceBackwardRotation->setKeySequence(KS);
    emit getDefaultKeySequenceOf(ui->KeyPieceRightTippingRotation->objectName(), KS);
    ui->KeyPieceRightTippingRotation->setKeySequence(KS);
    emit getDefaultKeySequenceOf(ui->KeyPieceLeftTippingRotation->objectName(), KS);
    ui->KeyPieceLeftTippingRotation->setKeySequence(KS);

}

void MainMenu::LoadDefaultKeybind2PlayerSettings()
{
    QKeySequence KS;
    emit getDefaultKeySequenceOf(ui->_2Player_Pause->objectName(),KS);
    ui->_2Player_Pause->setKeySequence(KS);

    emit getDefaultKeySequenceOf(ui->_2Player_1_Reserve->objectName(),KS);
    ui->_2Player_1_Reserve->setKeySequence(KS);
    emit getDefaultKeySequenceOf(ui->_2Player_2_Reserve->objectName(),KS);
    ui->_2Player_2_Reserve->setKeySequence(KS);

    emit getDefaultKeySequenceOf(ui->_2Player_1_KeyCameraRightRotation->objectName(),KS);
    ui->_2Player_1_KeyCameraRightRotation->setKeySequence(KS);
    emit getDefaultKeySequenceOf(ui->_2Player_2_KeyCameraRightRotation->objectName(),KS);
    ui->_2Player_2_KeyCameraRightRotation->setKeySequence(KS);
    emit getDefaultKeySequenceOf(ui->_2Player_1_KeyCameraLeftRotation->objectName(),KS);
    ui->_2Player_1_KeyCameraLeftRotation->setKeySequence(KS);
    emit getDefaultKeySequenceOf(ui->_2Player_2_KeyCameraLeftRotation->objectName(),KS);
    ui->_2Player_2_KeyCameraLeftRotation->setKeySequence(KS);
    emit getDefaultKeySequenceOf(ui->_2Player_1_KeyCameraForwardRotation->objectName(),KS);
    ui->_2Player_1_KeyCameraForwardRotation->setKeySequence(KS);
    emit getDefaultKeySequenceOf(ui->_2Player_2_KeyCameraForwardRotation->objectName(),KS);
    ui->_2Player_2_KeyCameraForwardRotation->setKeySequence(KS);
    emit getDefaultKeySequenceOf(ui->_2Player_1_KeyCameraBackwardRotation->objectName(),KS);
    ui->_2Player_1_KeyCameraBackwardRotation->setKeySequence(KS);
    emit getDefaultKeySequenceOf(ui->_2Player_2_KeyCameraBackwardRotation->objectName(),KS);
    ui->_2Player_2_KeyCameraBackwardRotation->setKeySequence(KS);

    int slidevalue = ui->_2Player_1_SliderCameraRightAndLeftRotationSpeed->minimum();
    emit getDefaultSliderValueOf(ui->_2Player_1_SliderCameraRightAndLeftRotationSpeed->objectName(),slidevalue);
    ui->_2Player_1_SliderCameraRightAndLeftRotationSpeed->setValue(slidevalue);
    emit getDefaultSliderValueOf(ui->_2Player_2_SliderCameraRightAndLeftRotationSpeed->objectName(),slidevalue);
    ui->_2Player_2_SliderCameraRightAndLeftRotationSpeed->setValue(slidevalue);

    bool classicVerticalRotation;
    emit isThisRadioDefaultChecked(ui->_2Player_1_ClassicRotation->objectName(), classicVerticalRotation);
    if(classicVerticalRotation){
        ui->_2Player_1_ClassicRotation->setChecked(true);
    }
    else {
        ui->_2Player_1_MasterRotation->setChecked(true);
    }
    emit isThisRadioDefaultChecked(ui->_2Player_2_ClassicRotation->objectName(), classicVerticalRotation);
    if(classicVerticalRotation){
        ui->_2Player_2_ClassicRotation->setChecked(true);
    }
    else {
        ui->_2Player_2_MasterRotation->setChecked(true);
    }


    emit getDefaultKeySequenceOf(ui->_2Player_1_KeyPieceRightMovement->objectName(), KS);
    ui->_2Player_1_KeyPieceRightMovement->setKeySequence(KS);
    emit getDefaultKeySequenceOf(ui->_2Player_2_KeyPieceRightMovement->objectName(), KS);
    ui->_2Player_2_KeyPieceRightMovement->setKeySequence(KS);
    emit getDefaultKeySequenceOf(ui->_2Player_1_KeyPieceLeftMovement->objectName(), KS);
    ui->_2Player_1_KeyPieceLeftMovement->setKeySequence(KS);
    emit getDefaultKeySequenceOf(ui->_2Player_2_KeyPieceLeftMovement->objectName(), KS);
    ui->_2Player_2_KeyPieceLeftMovement->setKeySequence(KS);
    emit getDefaultKeySequenceOf(ui->_2Player_1_KeyPieceForwardMovement->objectName(), KS);
    ui->_2Player_1_KeyPieceForwardMovement->setKeySequence(KS);
    emit getDefaultKeySequenceOf(ui->_2Player_2_KeyPieceForwardMovement->objectName(), KS);
    ui->_2Player_2_KeyPieceForwardMovement->setKeySequence(KS);
    emit getDefaultKeySequenceOf(ui->_2Player_1_KeyPieceBackwardMovement->objectName(), KS);
    ui->_2Player_1_KeyPieceBackwardMovement->setKeySequence(KS);
    emit getDefaultKeySequenceOf(ui->_2Player_2_KeyPieceBackwardMovement->objectName(), KS);
    ui->_2Player_2_KeyPieceBackwardMovement->setKeySequence(KS);
    emit getDefaultKeySequenceOf(ui->_2Player_1_KeyPieceDownMovement->objectName(), KS);
    ui->_2Player_1_KeyPieceDownMovement->setKeySequence(KS);
    emit getDefaultKeySequenceOf(ui->_2Player_2_KeyPieceDownMovement->objectName(), KS);
    ui->_2Player_2_KeyPieceDownMovement->setKeySequence(KS);


    emit getDefaultKeySequenceOf(ui->_2Player_1_KeyPieceRightRotation->objectName(), KS);
    ui->_2Player_1_KeyPieceRightRotation->setKeySequence(KS);
    emit getDefaultKeySequenceOf(ui->_2Player_2_KeyPieceRightRotation->objectName(), KS);
    ui->_2Player_2_KeyPieceRightRotation->setKeySequence(KS);
    emit getDefaultKeySequenceOf(ui->_2Player_1_KeyPieceForwardRotation->objectName(), KS);
    ui->_2Player_1_KeyPieceForwardRotation->setKeySequence(KS);
    emit getDefaultKeySequenceOf(ui->_2Player_2_KeyPieceForwardRotation->objectName(), KS);
    ui->_2Player_2_KeyPieceForwardRotation->setKeySequence(KS);
    emit getDefaultKeySequenceOf(ui->_2Player_1_KeyPieceRightTippingRotation->objectName(), KS);
    ui->_2Player_1_KeyPieceRightTippingRotation->setKeySequence(KS);
    emit getDefaultKeySequenceOf(ui->_2Player_2_KeyPieceRightTippingRotation->objectName(), KS);
    ui->_2Player_2_KeyPieceRightTippingRotation->setKeySequence(KS);
}

void MainMenu::LoadDefaultAudioSettings()
{
    int slidevalue = 100;
    emit getDefaultSliderValueOf(ui->Slider_Audio_Volume->objectName(),slidevalue);
    ui->Slider_Audio_Volume->setValue(slidevalue);
}


//slots associés à la page du menu principale
void MainMenu::onclickJeu_MainMenuPage()
{
    this->setCurrentIndex(this->indexOf(ui->Classic_Game_Page));

    ui->X_SpinBox->setFocus();
}

void MainMenu::onclickSettings_MainMenuPage()
{
    this->setCurrentIndex(this->indexOf(ui->Settings_Page));
    this->ui->Settings_Tab->setCurrentIndex(ui->Settings_Tab->indexOf(ui->_1Player_Shortcut));
}

void MainMenu::onclickQuit_MainMenu()
{
    emit QApplication::quit();
}


//slots associés à la page de paramètrage du jeu classic
void MainMenu::onclickCancel_ClassicGamePage()
{
    onclickDefault_ClassicGamePage();

    this->setCurrentIndex(this->indexOf(ui->Main_Menu_Page));
}

void MainMenu::onclickDefault_ClassicGamePage()
{
    ui->SoloMode->setChecked(true);

    ui->NormalMode->setChecked(true);

    ui->Classic_Set->setChecked(true);

    ui->X_SpinBox->setValue(ui->X_SpinBox->minimum());
    ui->Y_SpinBox->setValue(ui->Y_SpinBox->minimum());
    ui->Z_SpinBox->setValue(ui->Z_SpinBox->minimum());


    ui->X_SpinBox->setFocus();
}

void MainMenu::onclickPlay_ClassicGamePage()
{
    TetrisClassicDifficulty diff((ui->EasyMode->isChecked())?
                                     TetrisClassicDifficulty::Facile :
                                     (ui->NormalMode->isChecked())?
                                         TetrisClassicDifficulty::Normal :
                                         (ui->HardMode->isChecked())?
                                             TetrisClassicDifficulty::Difficile :
                                             TetrisClassicDifficulty::Master);

    TetrisClassicGameSet gameset((ui->Old_School_Set->isChecked())?
                                     TetrisClassicGameSet::OldSchool :
                                     (ui->Old_School_Plus_Set->isChecked())?
                                         TetrisClassicGameSet::OldSchoolPlus :
                                         (ui->Classic_Set->isChecked())?
                                             TetrisClassicGameSet::Classic :
                                             TetrisClassicGameSet::AllStars);

    if(ui->SoloMode->isChecked()){
        emit JeuTetrisClassique(diff,gameset,ui->X_SpinBox->value(),ui->Y_SpinBox->value(),ui->Z_SpinBox->value());
    }
    else if (ui->_1vs1Mode->isChecked()) {
        emit Jeu2PlayerVersusTetris(diff,gameset,ui->X_SpinBox->value(),ui->Y_SpinBox->value(),ui->Z_SpinBox->value());
    }
}


//slots associés à la page des options
void MainMenu::onclickGoToMenu_SettingsPage()
{
    this->setCurrentIndex(this->indexOf(ui->Main_Menu_Page));
    LoadUserKeybind1PlayerSettings();
    LoadUserKeybind2PlayerSettings();
    LoadUserAudioSettings();
}

void MainMenu::onclickCancel_SettingsPage()
{
    if(ui->Settings_Tab->currentIndex() == ui->Settings_Tab->indexOf(ui->_1Player_Shortcut)){
        LoadUserKeybind1PlayerSettings();
    }
    else if (ui->Settings_Tab->currentIndex() == ui->Settings_Tab->indexOf(ui->_2Player_Shortcut)) {
        LoadUserKeybind2PlayerSettings();
    }
    else if (ui->Settings_Tab->currentIndex() == ui->Settings_Tab->indexOf(ui->Audio)) {
        LoadUserAudioSettings();
    }
}

void MainMenu::onclickDefault_SettingsPage()
{
    if(ui->Settings_Tab->currentIndex() == ui->Settings_Tab->indexOf(ui->_1Player_Shortcut)){
        LoadDefaultKeybind1PlayerSettings();
        emit Default1PlayerKeyBindSettingsNowUserSettings();
    }
    else if (ui->Settings_Tab->currentIndex() == ui->Settings_Tab->indexOf(ui->_2Player_Shortcut)) {
        LoadDefaultKeybind2PlayerSettings();
        emit Default2PlayerKeyBindSettingsNowUserSettings();
    }
    else if (ui->Settings_Tab->currentIndex() == ui->Settings_Tab->indexOf(ui->Audio)) {
        LoadDefaultAudioSettings();
        emit DefaultAudioSettingsNowUserSettings();
    }

}

void MainMenu::onclickApply_SettingsPage()
{
    if(ui->Settings_Tab->currentIndex() == ui->Settings_Tab->indexOf(ui->_1Player_Shortcut)){
        emit ChangeUserKeyBindOf(ui->Pause->objectName(), ui->Pause->keySequence());
        emit ChangeUserKeyBindOf(ui->Reserve->objectName(), ui->Reserve->keySequence());
        emit ChangeUserKeyBindOf(ui->KeyCameraRightRotation->objectName(), ui->KeyCameraRightRotation->keySequence());
        emit ChangeUserKeyBindOf(ui->KeyCameraLeftRotation->objectName(), ui->KeyCameraLeftRotation->keySequence());
        emit ChangeUserKeyBindOf(ui->KeyCameraForwardRotation->objectName(), ui->KeyCameraForwardRotation->keySequence());
        emit ChangeUserKeyBindOf(ui->KeyCameraBackwardRotation->objectName(), ui->KeyCameraBackwardRotation->keySequence());

        emit ChangeUserSliderOf(ui->SliderCameraRightAndLeftRotationSpeed->objectName(), ui->SliderCameraRightAndLeftRotationSpeed->value());
        if(ui->ClassicRotation->isChecked()){
            emit ChangeUserCheckedBoxOf(ui->ClassicRotation->objectName());
        }
        else {
            emit ChangeUserCheckedBoxOf(ui->MasterRotation->objectName());
        }
        emit ChangeUserKeyBindOf(ui->KeyPieceRightMovement->objectName(), ui->KeyPieceRightMovement->keySequence());
        emit ChangeUserKeyBindOf(ui->KeyPieceLeftMovement->objectName(), ui->KeyPieceLeftMovement->keySequence());
        emit ChangeUserKeyBindOf(ui->KeyPieceForwardMovement->objectName(), ui->KeyPieceForwardMovement->keySequence());
        emit ChangeUserKeyBindOf(ui->KeyPieceBackwardMovement->objectName(), ui->KeyPieceBackwardMovement->keySequence());
        emit ChangeUserKeyBindOf(ui->KeyPieceDownMovement->objectName(), ui->KeyPieceDownMovement->keySequence());

        emit ChangeUserKeyBindOf(ui->KeyPieceRightRotation->objectName(), ui->KeyPieceRightRotation->keySequence());
        emit ChangeUserKeyBindOf(ui->KeyPieceLeftRotation->objectName(), ui->KeyPieceLeftRotation->keySequence());
        emit ChangeUserKeyBindOf(ui->KeyPieceForwardRotation->objectName(), ui->KeyPieceForwardRotation->keySequence());
        emit ChangeUserKeyBindOf(ui->KeyPieceBackwardRotation->objectName(), ui->KeyPieceBackwardRotation->keySequence());
        emit ChangeUserKeyBindOf(ui->KeyPieceLeftTippingRotation->objectName(), ui->KeyPieceLeftTippingRotation->keySequence());
        emit ChangeUserKeyBindOf(ui->KeyPieceRightTippingRotation->objectName(), ui->KeyPieceRightTippingRotation->keySequence());

        emit SettingsKeyBind1PlayerSaveOrder();

        LoadUserKeybind1PlayerSettings();
    }
    else if(ui->Settings_Tab->currentIndex() == ui->Settings_Tab->indexOf(ui->Audio)){
        emit ChangeUserSliderOf(ui->Slider_Audio_Volume->objectName(), ui->Slider_Audio_Volume->value());

        emit SettingsAudioSaveOrder();

        LoadUserAudioSettings();
    }
    else if(ui->Settings_Tab->currentIndex() == ui->Settings_Tab->indexOf(ui->_2Player_Shortcut)){
        emit ChangeUserKeyBindOf(ui->_2Player_Pause->objectName(), ui->_2Player_Pause->keySequence());
        emit ChangeUserKeyBindOf(ui->_2Player_1_Reserve->objectName(), ui->_2Player_1_Reserve->keySequence());
        emit ChangeUserKeyBindOf(ui->_2Player_2_Reserve->objectName(), ui->_2Player_2_Reserve->keySequence());

        emit ChangeUserKeyBindOf(ui->_2Player_1_KeyCameraRightRotation->objectName(), ui->_2Player_1_KeyCameraRightRotation->keySequence());
        emit ChangeUserKeyBindOf(ui->_2Player_2_KeyCameraRightRotation->objectName(), ui->_2Player_2_KeyCameraRightRotation->keySequence());
        emit ChangeUserKeyBindOf(ui->_2Player_1_KeyCameraLeftRotation->objectName(), ui->_2Player_1_KeyCameraLeftRotation->keySequence());
        emit ChangeUserKeyBindOf(ui->_2Player_2_KeyCameraLeftRotation->objectName(), ui->_2Player_2_KeyCameraLeftRotation->keySequence());
        emit ChangeUserKeyBindOf(ui->_2Player_1_KeyCameraForwardRotation->objectName(), ui->_2Player_1_KeyCameraForwardRotation->keySequence());
        emit ChangeUserKeyBindOf(ui->_2Player_2_KeyCameraForwardRotation->objectName(), ui->_2Player_2_KeyCameraForwardRotation->keySequence());
        emit ChangeUserKeyBindOf(ui->_2Player_1_KeyCameraBackwardRotation->objectName(), ui->_2Player_1_KeyCameraBackwardRotation->keySequence());
        emit ChangeUserKeyBindOf(ui->_2Player_2_KeyCameraBackwardRotation->objectName(), ui->_2Player_2_KeyCameraBackwardRotation->keySequence());



        emit ChangeUserSliderOf(ui->_2Player_1_SliderCameraRightAndLeftRotationSpeed->objectName(), ui->_2Player_1_SliderCameraRightAndLeftRotationSpeed->value());
        emit ChangeUserSliderOf(ui->_2Player_2_SliderCameraRightAndLeftRotationSpeed->objectName(), ui->_2Player_2_SliderCameraRightAndLeftRotationSpeed->value());
        if(ui->_2Player_1_ClassicRotation->isChecked()){
            emit ChangeUserCheckedBoxOf(ui->_2Player_1_ClassicRotation->objectName());
        }
        else {
            emit ChangeUserCheckedBoxOf(ui->_2Player_1_MasterRotation->objectName());
        }
        if(ui->_2Player_2_ClassicRotation->isChecked()){
            emit ChangeUserCheckedBoxOf(ui->_2Player_2_ClassicRotation->objectName());
        }
        else {
            emit ChangeUserCheckedBoxOf(ui->_2Player_2_MasterRotation->objectName());
        }

        emit ChangeUserKeyBindOf(ui->_2Player_1_KeyPieceRightMovement->objectName(), ui->_2Player_1_KeyPieceRightMovement->keySequence());
        emit ChangeUserKeyBindOf(ui->_2Player_1_KeyPieceLeftMovement->objectName(), ui->_2Player_1_KeyPieceLeftMovement->keySequence());
        emit ChangeUserKeyBindOf(ui->_2Player_1_KeyPieceForwardMovement->objectName(), ui->_2Player_1_KeyPieceForwardMovement->keySequence());
        emit ChangeUserKeyBindOf(ui->_2Player_1_KeyPieceBackwardMovement->objectName(), ui->_2Player_1_KeyPieceBackwardMovement->keySequence());
        emit ChangeUserKeyBindOf(ui->_2Player_1_KeyPieceDownMovement->objectName(), ui->_2Player_1_KeyPieceDownMovement->keySequence());
        emit ChangeUserKeyBindOf(ui->_2Player_2_KeyPieceRightMovement->objectName(), ui->_2Player_2_KeyPieceRightMovement->keySequence());
        emit ChangeUserKeyBindOf(ui->_2Player_2_KeyPieceLeftMovement->objectName(), ui->_2Player_2_KeyPieceLeftMovement->keySequence());
        emit ChangeUserKeyBindOf(ui->_2Player_2_KeyPieceForwardMovement->objectName(), ui->_2Player_2_KeyPieceForwardMovement->keySequence());
        emit ChangeUserKeyBindOf(ui->_2Player_2_KeyPieceBackwardMovement->objectName(), ui->_2Player_2_KeyPieceBackwardMovement->keySequence());
        emit ChangeUserKeyBindOf(ui->_2Player_2_KeyPieceDownMovement->objectName(), ui->_2Player_2_KeyPieceDownMovement->keySequence());


        emit ChangeUserKeyBindOf(ui->_2Player_1_KeyPieceRightRotation->objectName(), ui->_2Player_1_KeyPieceRightRotation->keySequence());
        emit ChangeUserKeyBindOf(ui->_2Player_2_KeyPieceRightRotation->objectName(), ui->_2Player_2_KeyPieceRightRotation->keySequence());
        emit ChangeUserKeyBindOf(ui->_2Player_1_KeyPieceForwardRotation->objectName(), ui->_2Player_1_KeyPieceForwardRotation->keySequence());
        emit ChangeUserKeyBindOf(ui->_2Player_2_KeyPieceForwardRotation->objectName(), ui->_2Player_2_KeyPieceForwardRotation->keySequence());
        emit ChangeUserKeyBindOf(ui->_2Player_1_KeyPieceRightTippingRotation->objectName(), ui->_2Player_1_KeyPieceRightTippingRotation->keySequence());
        emit ChangeUserKeyBindOf(ui->_2Player_2_KeyPieceRightTippingRotation->objectName(), ui->_2Player_2_KeyPieceRightTippingRotation->keySequence());

        emit SettingsKeyBind2PlayerSaveOrder();

        LoadUserKeybind2PlayerSettings();
    }



}


