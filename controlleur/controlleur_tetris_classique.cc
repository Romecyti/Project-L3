#include "controlleur_tetris_classique.hh"



ControlleurTetrisClassique::ControlleurTetrisClassique(NIVEAU n,SetDePiece Sp, Position p, NonAlterableSettings set, QWidget *ptr):Controlleur(),_vue(set,ptr)
{

    _modele=new TetrisClassique(n,Sp,p);


    _n=n;
    _Setpiece=Sp;
    _taille=p;
    connect(&_vue.GetJeu(),&TetrisClassiqueOpenGl::aboutPLateau,this,&ControlleurTetrisClassique::AboutPlateau);
    connect(&_vue.GetJeu(),&TetrisClassiqueOpenGl::AboutSuivant,this,&ControlleurTetrisClassique::AboutSuivant);
    connect(&_vue.GetJeu(),&TetrisClassiqueOpenGl::AboutReserve,this,&ControlleurTetrisClassique::AboutReserve);
    connect(&_vue.GetJeu(),&TetrisClassiqueOpenGl::ReserveState,this,&ControlleurTetrisClassique::ReserveState);
    connect(&_vue.GetJeu(),&TetrisClassiqueOpenGl::AboutPieceActuelle,this,&ControlleurTetrisClassique::AboutPieceActuelle);
    connect(&_vue.GetJeu(),&TetrisClassiqueOpenGl::AboutPositionPieceActuelle,this,&ControlleurTetrisClassique::AboutPositionPieceActuelle);

    connect(&_vue.GetJeu(),&TetrisClassiqueOpenGl::AboutScore,this,&ControlleurTetrisClassique::AboutScore);
    connect(&_vue.GetJeu(),&TetrisClassiqueOpenGl::AboutNiveau,this,&ControlleurTetrisClassique::AboutNiveau);
    connect(&_vue.GetJeu(),&TetrisClassiqueOpenGl::JeuFinit,this,&ControlleurTetrisClassique::JeuFinit);
    connect(&_vue.GetJeu(),&TetrisClassiqueOpenGl::JeuPause,this,&ControlleurTetrisClassique::JeuPause);

    connect(&_vue.GetJeu(),&TetrisClassiqueOpenGl::Jouer,this,&ControlleurTetrisClassique::Lancer);
    connect(&_vue.GetJeu(),&TetrisClassiqueOpenGl::Deplacement,this,&ControlleurTetrisClassique::Deplacement);
    connect(&_vue.GetJeu(),&TetrisClassiqueOpenGl::Rotation,this,&ControlleurTetrisClassique::Rotation);
    connect(&_vue.GetJeu(),&TetrisClassiqueOpenGl::Pause,this,&ControlleurTetrisClassique::Pause);
     connect(&_vue.GetJeu(),&TetrisClassiqueOpenGl::Quitter,this,&ControlleurTetrisClassique::RetourMenu);

     connect(&_vue.GetJeu(),&TetrisClassiqueOpenGl::Recommencer,this,&ControlleurTetrisClassique::Reset);

    connect(&_vue.GetJeu(),&TetrisClassiqueOpenGl::UseReserve,this,&ControlleurTetrisClassique::UseReserve);
    connect(&_vue,&VueTetrisC::AboutNbEtageDetruit,this,&ControlleurTetrisClassique::AboutNbEtageDetruits);
    connect(&_vue.GetResultat(),&TetrisClassiqueResultats::Rejouer,this,&ControlleurTetrisClassique::Reset);
    connect(&_vue.GetResultat(),&TetrisClassiqueResultats::Quitter,this,&ControlleurTetrisClassique::RetourMenu);

    connect(_modele,&TetrisClassique::DeplacementImpossible,&_vue.GetJeu(),&TetrisClassiqueOpenGl::Bump_sfx);
    connect(_modele,&TetrisClassique::RotationImpossible,&_vue.GetJeu(),&TetrisClassiqueOpenGl::Bump_sfx);
    connect(_modele,&TetrisClassique::PiecePose,&_vue.GetJeu(),&TetrisClassiqueOpenGl::Pose_sfx);
}

QWidget *ControlleurTetrisClassique::GetVue()
{
    return &_vue;
}

ControlleurTetrisClassique::~ControlleurTetrisClassique()
{
    delete _modele;
}

void ControlleurTetrisClassique::Lancer()
{
    this->_modele->Descente();
}

void ControlleurTetrisClassique::Rotation(DIRECTION_ROT d)
{
    this->_modele->RotatationPiece(d);
}

void ControlleurTetrisClassique::Pause()
{


    if(_modele->JeuPause())
        _modele->FinPause();
    else
        _modele->DebutPause();

    _vue.setFocus();

}

void ControlleurTetrisClassique::Reset()
{


    delete _modele;
    _modele=new TetrisClassique(_n,_Setpiece,_taille);
    connect(_modele,&TetrisClassique::DeplacementImpossible,&_vue.GetJeu(),&TetrisClassiqueOpenGl::Bump_sfx);
    connect(_modele,&TetrisClassique::RotationImpossible,&_vue.GetJeu(),&TetrisClassiqueOpenGl::Bump_sfx);
    connect(_modele,&TetrisClassique::PiecePose,&_vue.GetJeu(),&TetrisClassiqueOpenGl::Pose_sfx);
    _vue.reset();

}

void ControlleurTetrisClassique::RetourMenu()
{
    _vue.setFocus();
    emit RetourAuMenu();
}

void ControlleurTetrisClassique::UseReserve()
{
    bool b;
    ReserveState(b);

    if(b)
        _modele->PriseReserve();
    else
        _modele->MiseEnReserve();

}

void ControlleurTetrisClassique::ChangeControlleur()
{

}
/*
void ControlleurTetrisClassique::ChangeDifficulté(NIVEAU n, Position p)
{

}
*/
void ControlleurTetrisClassique::Deplacement(DIRECTION_MOUVEMENT d)
{
    this->_modele->Deplacement(d);
}

void ControlleurTetrisClassique::AboutPlateau(Matrice3D &m)
{
    m=_modele->GetPlateau().GetMatrice() ;
}

void ControlleurTetrisClassique::AboutReserve(std::unique_ptr<Piece> &res)
{
    auto i=_modele->GetReserve();
    res=std::move(i);

}

void ControlleurTetrisClassique::AboutSuivant(std::vector<std::unique_ptr<Piece>>& suiv)
{
    suiv.clear();
    auto a=_modele->GetListePieceSuivantes();
    unsigned long s=a.size();
    for (int i=0;i<static_cast<int>(s);i++) {
        suiv.push_back(a.front()->clone());
        a.pop();
    }



}

void ControlleurTetrisClassique::AboutPieceActuelle( std::unique_ptr<Piece> &p)
{
    auto i=_modele->GetPieceActuelle();
    p=std::move(i->piece);
}

void ControlleurTetrisClassique::AboutPositionPieceActuelle(Position &p)
{
    p= _modele->GetPieceActuelle()->pos;
}

void ControlleurTetrisClassique::AboutScore(int &n)
{
    n=_modele->GetNbPoint();
}

void ControlleurTetrisClassique::AboutNiveau(int &n)
{
    n=_modele->GetNiveau();
}

void ControlleurTetrisClassique::AboutNbEtageDetruits(int &n)
{
    n=_modele->GetNbEtageDetruits();
}

void ControlleurTetrisClassique::JeuPause(bool &b)
{
    b=_modele->JeuPause();
}

void ControlleurTetrisClassique::JeuFinit(bool &b)
{
    b=_modele->JeuFinit();
}


void ControlleurTetrisClassique::ReserveState(bool& b)
{
    b= _modele->GetReserve()!=nullptr;
}
