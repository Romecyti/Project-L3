#include "supercontrolleur.hh"



SuperControlleur::SuperControlleur(QWidget *parent) : QWidget(parent), _settingsControle(this),_lay()
{
    _controlleur=nullptr;
    this->setWindowTitle("Tetrabloc!?");
    this->setWindowIcon(QIcon(":/ressources/logo.png"));

    LoadMenuControlleur();
    connect(_controlleur,&Controlleur::ChangerControlleur,this,&SuperControlleur::ChangeControlleur);
    this->setLayout(&_lay);


}

SuperControlleur::~SuperControlleur()
{
    delete _controlleur;
}

void SuperControlleur::ChangeControlleur(controlleurs c)
{

}

void SuperControlleur::LoadMenuControlleur()
{

    delete _controlleur;
    ControlleurMenu * contro = new ControlleurMenu(_settingsControle.getUserSettings(),_settingsControle.getDefaultSettings(),this);

    //connect des signaux du menu aux slots du controlleur
    connect(contro,&ControlleurMenu::playTetrisClassique,this,&SuperControlleur::playTetrisClassique);
    connect(contro, &ControlleurMenu::Play2PlayerVersusTetris, this, & SuperControlleur::Play2PlayerVersusTetris);

    connect(contro,&ControlleurMenu::GetUserSettings,this,&SuperControlleur::GetUserSettings);
    connect(contro, &ControlleurMenu::GetDefaultSettings, this, & SuperControlleur::GetDefaultSettings);
    connect(contro, &ControlleurMenu::ChangeUser1PlayerKeybindSettingsValidationOrder, this, & SuperControlleur::ChangeUser1PlayerKeybindSettingsValidationOrder);
    connect(contro, &ControlleurMenu::ChangeUser2PlayerKeybindSettingsValidationOrder, this, & SuperControlleur::ChangeUser2PlayerKeybindSettingsValidationOrder);
    connect(contro, &ControlleurMenu::ChangeUserAudioSettingsValidationOrder, this, & SuperControlleur::ChangeUserAudioSettingsValidationOrder);
    _lay.addWidget(contro->getvu(),0,0);

    _controlleur = contro;

    this->update();


}




// slots associés aux signaux du menu
void SuperControlleur::playTetrisClassique(TetrisClassicDifficulty difficulty, TetrisClassicGameSet gameset, int size_x, int size_y, int size_z)
{

    delete _controlleur;
    //this->setFocus();
    ControlleurTetrisClassique *contro=new ControlleurTetrisClassique(static_cast<NIVEAU>(difficulty), static_cast<SetDePiece>(gameset) ,Position{size_x,size_y,size_z}, _settingsControle.getUserSettings());
    connect(contro,&ControlleurTetrisClassique::RetourAuMenu,this,&SuperControlleur::LoadMenuControlleur);

    //contro->GetVue()->setFocus();
    _lay.addWidget(contro->GetVue(),0,0);
    _controlleur=contro;


}

void SuperControlleur::Play2PlayerVersusTetris(TetrisClassicDifficulty difficulty, TetrisClassicGameSet gameset, int size_x, int size_y, int size_z)
{
    delete _controlleur;

    ControlleurTetrisMulti *contro=new ControlleurTetrisMulti(static_cast<NIVEAU>(difficulty), static_cast<SetDePiece>(gameset) ,Position{size_x,size_y,size_z}, _settingsControle.getUserSettings());
    connect(contro,&ControlleurTetrisMulti::RetourAuMenu,this,&SuperControlleur::LoadMenuControlleur);


    _lay.addWidget(contro->GetVue(),0,0);
    _controlleur=contro;
}

void SuperControlleur::GetUserSettings(NonAlterableSettings &userSettings)
{
    userSettings = _settingsControle.getUserSettings();
}

void SuperControlleur::GetDefaultSettings(NonAlterableSettings &defaultSettings)
{
    defaultSettings = _settingsControle.getDefaultSettings();
}

void SuperControlleur::ChangeUser1PlayerKeybindSettingsValidationOrder(AlterableSettings NewUserSettings)
{
    _settingsControle.ValidateUserKeyBindSettings(NewUserSettings);
}

void SuperControlleur::ChangeUser2PlayerKeybindSettingsValidationOrder(AlterableSettings NewUserSettings)
{
    _settingsControle.ValidateUser2PlayerKeyBindSettings(NewUserSettings);
}

void SuperControlleur::ChangeUserAudioSettingsValidationOrder(AlterableSettings NewUserSettings)
{
    _settingsControle.ValidateUserAudioSettings(NewUserSettings);
}
