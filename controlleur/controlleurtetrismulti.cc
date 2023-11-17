#include "controlleurtetrismulti.hh"

ControlleurTetrisMulti::ControlleurTetrisMulti(NIVEAU n, SetDePiece Sp, Position p, NonAlterableSettings set, QWidget *ptr):_vue(set,ptr)
{
    _n=n;
    _taille=p;
    _Setpiece=Sp;

    _modele1=new TetrisMultijoueur(n,Sp,p);
    _modele2=new TetrisMultijoueur(n,Sp,p);

    connect(&_vue,&VueTetrisMulti::Jeu1fini,this,&ControlleurTetrisMulti::jeu1fini);
    connect(_modele1,&TetrisMultijoueur::DeplacementImpossible,&_vue.GetJeu1(),&TetrisClassiqueOpenGl::Bump_sfx);
    connect(_modele1,&TetrisMultijoueur::RotationImpossible,&_vue.GetJeu1(),&TetrisClassiqueOpenGl::Bump_sfx);
    connect(_modele1,&TetrisMultijoueur::PiecePose,&_vue.GetJeu1(),&TetrisClassiqueOpenGl::Pose_sfx);

    connect(_modele2,&TetrisMultijoueur::DeplacementImpossible,&_vue.GetJeu2(),&TetrisClassiqueOpenGl::Bump_sfx);
    connect(_modele2,&TetrisMultijoueur::RotationImpossible,&_vue.GetJeu2(),&TetrisClassiqueOpenGl::Bump_sfx);
    connect(_modele2,&TetrisMultijoueur::PiecePose,&_vue.GetJeu2(),&TetrisClassiqueOpenGl::Pose_sfx);

    connect(_modele1,&TetrisMultijoueur::EnvoieLigne,this,&ControlleurTetrisMulti::EnvoieCarreM1toM2);
    connect(_modele2,&TetrisMultijoueur::EnvoieLigne,this,&ControlleurTetrisMulti::EnvoieCarreM2toM1);

    connect(&_vue.GetJeu1(),&TetrisClassiqueOpenGl::Pause,this,&ControlleurTetrisMulti::Pause);
    connect(&_vue.GetJeu2(),&TetrisClassiqueOpenGl::Pause,this,&ControlleurTetrisMulti::Pause);

    connect(&_vue.GetJeu1(),&TetrisClassiqueOpenGl::JeuFinit,this,&ControlleurTetrisMulti::JeuFinit);
    connect(&_vue.GetJeu2(),&TetrisClassiqueOpenGl::JeuFinit,this,&ControlleurTetrisMulti::JeuFinit);

    connect(&_vue.GetJeu1(),&TetrisClassiqueOpenGl::JeuPause,this,&ControlleurTetrisMulti::JeuPause);
    connect(&_vue.GetJeu2(),&TetrisClassiqueOpenGl::JeuPause,this,&ControlleurTetrisMulti::JeuPause);

    connect(&_vue,&VueTetrisMulti::nbEtagesDetruit,this,&ControlleurTetrisMulti::GetNbEtages);
    connect(&_vue,&VueTetrisMulti::resultat,this,&ControlleurTetrisMulti::GetScores);

    connect(&_vue.GetJeu1(),&TetrisClassiqueOpenGl::UseReserve,this,&ControlleurTetrisMulti::UseReserveM1);
    connect(&_vue.GetJeu2(),&TetrisClassiqueOpenGl::UseReserve,this,&ControlleurTetrisMulti::UseReserveM2);



    connect(&_vue.GetJeu1(),&TetrisClassiqueOpenGl::aboutPLateau,this,&ControlleurTetrisMulti::AboutPlateauM1);
    connect(&_vue.GetJeu1(),&TetrisClassiqueOpenGl::AboutSuivant,this,&ControlleurTetrisMulti::AboutSuivantM1);
    connect(&_vue.GetJeu1(),&TetrisClassiqueOpenGl::AboutReserve,this,&ControlleurTetrisMulti::AboutReserveM1);
    connect(&_vue.GetJeu1(),&TetrisClassiqueOpenGl::ReserveState,this,&ControlleurTetrisMulti::ReserveStateM1);
    connect(&_vue.GetJeu1(),&TetrisClassiqueOpenGl::AboutPieceActuelle,this,&ControlleurTetrisMulti::AboutPieceActuelleM1);
    connect(&_vue.GetJeu1(),&TetrisClassiqueOpenGl::AboutPositionPieceActuelle,this,&ControlleurTetrisMulti::AboutPositionPieceActuelleM1);
    connect(&_vue.GetJeu1(),&TetrisClassiqueOpenGl::AboutScore,this,&ControlleurTetrisMulti::AboutScoreM1);
    connect(&_vue.GetJeu1(),&TetrisClassiqueOpenGl::AboutNiveau,this,&ControlleurTetrisMulti::AboutNiveauM1);
    connect(&_vue.GetJeu1(),&TetrisClassiqueOpenGl::Jouer,this,&ControlleurTetrisMulti::LancerM1);
    connect(&_vue.GetJeu1(),&TetrisClassiqueOpenGl::Deplacement,this,&ControlleurTetrisMulti::DeplacementM1);
    connect(&_vue.GetJeu1(),&TetrisClassiqueOpenGl::Rotation,this,&ControlleurTetrisMulti::RotationM1);



    connect(&_vue.GetJeu2(),&TetrisClassiqueOpenGl::aboutPLateau,this,&ControlleurTetrisMulti::AboutPlateauM2);
    connect(&_vue.GetJeu2(),&TetrisClassiqueOpenGl::AboutSuivant,this,&ControlleurTetrisMulti::AboutSuivantM2);
    connect(&_vue.GetJeu2(),&TetrisClassiqueOpenGl::AboutReserve,this,&ControlleurTetrisMulti::AboutReserveM2);
    connect(&_vue.GetJeu2(),&TetrisClassiqueOpenGl::ReserveState,this,&ControlleurTetrisMulti::ReserveStateM2);
    connect(&_vue.GetJeu2(),&TetrisClassiqueOpenGl::AboutPieceActuelle,this,&ControlleurTetrisMulti::AboutPieceActuelleM2);
    connect(&_vue.GetJeu2(),&TetrisClassiqueOpenGl::AboutPositionPieceActuelle,this,&ControlleurTetrisMulti::AboutPositionPieceActuelleM2);
    connect(&_vue.GetJeu2(),&TetrisClassiqueOpenGl::AboutScore,this,&ControlleurTetrisMulti::AboutScoreM2);
    connect(&_vue.GetJeu2(),&TetrisClassiqueOpenGl::AboutNiveau,this,&ControlleurTetrisMulti::AboutNiveauM2);
    connect(&_vue.GetJeu2(),&TetrisClassiqueOpenGl::Jouer,this,&ControlleurTetrisMulti::LancerM2);
    connect(&_vue.GetJeu2(),&TetrisClassiqueOpenGl::Deplacement,this,&ControlleurTetrisMulti::DeplacementM2);
    connect(&_vue.GetJeu2(),&TetrisClassiqueOpenGl::Rotation,this,&ControlleurTetrisMulti::RotationM2);

    connect(&_vue.GetResult(),&ResultatTetrisMulti::Quitter,this,&ControlleurTetrisMulti::RetourMenu);
   connect(&_vue.GetResult(),&ResultatTetrisMulti::Rejouer,this,&ControlleurTetrisMulti::Reset);

   connect(&_vue.GetJeu2(),&TetrisClassiqueOpenGl::Quitter,this,&ControlleurTetrisMulti::RetourMenu);
   connect(&_vue.GetJeu1(),&TetrisClassiqueOpenGl::Quitter,this,&ControlleurTetrisMulti::RetourMenu);
   connect(&_vue.GetJeu2(),&TetrisClassiqueOpenGl::Recommencer,this,&ControlleurTetrisMulti::Reset);
   connect(&_vue.GetJeu1(),&TetrisClassiqueOpenGl::Recommencer,this,&ControlleurTetrisMulti::Reset);

}

QWidget *ControlleurTetrisMulti::GetVue()
{
    return &_vue;
}

ControlleurTetrisMulti::~ControlleurTetrisMulti()
{
    delete _modele1;
    delete _modele2;
}

void ControlleurTetrisMulti::ChangeControlleur()
{

}
//--------------------------------------------------------[envoie de lignes]
void ControlleurTetrisMulti::EnvoieCarreM1toM2(int nbl)
{
    _modele2->ReceptionCarre(nbl);
}

void ControlleurTetrisMulti::EnvoieCarreM2toM1(int nbl)
{
    _modele1->ReceptionCarre(nbl);
}
//------------------------------------------------------[Fonctions  pause,jouer]
void ControlleurTetrisMulti::Pause()
{

    if(_modele1->JeuPause()){
        _modele1->FinPause();
        _modele2->FinPause();
    }
    else{
        _modele1->DebutPause();
        _modele2->DebutPause();
    }
    _vue.setFocus();
}

void ControlleurTetrisMulti::LancerM1()
{
    _modele1->Descente();
}

void ControlleurTetrisMulti::LancerM2()
{
    _modele2->Descente();
}


//-----------------------------------------------------[fonctions de prise d'informations]
//--------[etat du jeu]
void ControlleurTetrisMulti::JeuFinit(bool &b)
{
    b=_modele1->JeuFinit() || _modele2->JeuFinit();
}

void ControlleurTetrisMulti::jeu1fini(bool &b)
{
     b=_modele1->JeuFinit();
}

void ControlleurTetrisMulti::jeu2finit(bool &b)
{
    b=_modele2->JeuFinit();
}

void ControlleurTetrisMulti::JeuPause(bool &b)
{
    b=_modele1->JeuPause();//seul le modele1 car les 2 modeles sont toujours en pause au meme moment
}
//--------[plateau]
void ControlleurTetrisMulti::AboutPlateauM1(Matrice3D &m)
{
    m=_modele1->GetPlateau().GetMatrice() ;
}

void ControlleurTetrisMulti::AboutPlateauM2(Matrice3D &m)
{
    m=_modele2->GetPlateau().GetMatrice() ;
}
//--------[reserve]
void ControlleurTetrisMulti::AboutReserveM1(std::unique_ptr<Piece> &res)
{
    auto i=_modele1->GetReserve();
    res=std::move(i);
}

void ControlleurTetrisMulti::ReserveStateM1(bool &b)
{
    b= _modele1->GetReserve()!=nullptr;
}

void ControlleurTetrisMulti::AboutReserveM2(std::unique_ptr<Piece> &res)
{
    auto i=_modele2->GetReserve();
    res=std::move(i);
}

void ControlleurTetrisMulti::ReserveStateM2(bool &b)
{
    b= _modele2->GetReserve()!=nullptr;
}
//--------[pieces suivantes]
void ControlleurTetrisMulti::AboutSuivantM1(std::vector<std::unique_ptr<Piece> > &suiv)
{
    suiv.clear();
    auto a=_modele1->GetListePieceSuivantes();
    unsigned long s=a.size();
    for (int i=0;i<static_cast<int>(s);i++) {
        suiv.push_back(a.front()->clone());
        a.pop();
    }

}

void ControlleurTetrisMulti::AboutSuivantM2(std::vector<std::unique_ptr<Piece> > &suiv)
{
    suiv.clear();
    auto a=_modele2->GetListePieceSuivantes();
    unsigned long s=a.size();
    for (int i=0;i<static_cast<int>(s);i++) {
        suiv.push_back(a.front()->clone());
        a.pop();
    }

}
//--------[pieces actuellement jouer]
void ControlleurTetrisMulti::AboutPieceActuelleM1(std::unique_ptr<Piece> &p)
{
    auto i=_modele1->GetPieceActuelle();
    p=std::move(i->piece);
}

void ControlleurTetrisMulti::AboutPositionPieceActuelleM1(Position &p)
{
    p= _modele1->GetPieceActuelle()->pos;
}

void ControlleurTetrisMulti::AboutPieceActuelleM2(std::unique_ptr<Piece> &p)
{
    auto i=_modele2->GetPieceActuelle();
    p=std::move(i->piece);
}

void ControlleurTetrisMulti::AboutPositionPieceActuelleM2(Position &p)
{
    p= _modele2->GetPieceActuelle()->pos;
}
//--------[autres informations]
void ControlleurTetrisMulti::AboutScoreM1(int &n)
{
    n=_modele1->GetNbPoint();
}

void ControlleurTetrisMulti::AboutNiveauM1(int &n)
{
    n=_modele1->GetNiveau();
}

void ControlleurTetrisMulti::AboutNbEtageDetruitsM1(int &n)
{
    n=_modele1->GetNbEtageDetruits();
}

void ControlleurTetrisMulti::AboutScoreM2(int &n)
{
    n=_modele2->GetNbPoint();
}

void ControlleurTetrisMulti::AboutNiveauM2(int &n)
{
    n=_modele2->GetNiveau();
}

void ControlleurTetrisMulti::AboutNbEtageDetruitsM2(int &n)
{
    n=_modele2->GetNbEtageDetruits();
}
//-----------------------------------------------------[fonctions manipulation piece actuelle ]
//--_modele1
void ControlleurTetrisMulti::UseReserveM1()
{
    bool b;
    ReserveStateM1(b);

    if(b)
        _modele1->PriseReserve();
    else
        _modele1->MiseEnReserve();
}

void ControlleurTetrisMulti::RotationM1(DIRECTION_ROT d)
{
    _modele1->RotatationPiece(d);
}

void ControlleurTetrisMulti::DeplacementM1(DIRECTION_MOUVEMENT d)
{
    _modele1->Deplacement(d);
}
//--_modele2

void ControlleurTetrisMulti::UseReserveM2()
{
    bool b;
    ReserveStateM2(b);

    if(b)
        _modele2->PriseReserve();
    else
        _modele2->MiseEnReserve();



}

void ControlleurTetrisMulti::RotationM2(DIRECTION_ROT d)
{
    _modele2->RotatationPiece(d);
}

void ControlleurTetrisMulti::DeplacementM2(DIRECTION_MOUVEMENT d)
{
    _modele2->Deplacement(d);
}

void ControlleurTetrisMulti::GetScores(int &j1, int &j2)
{
    j1=_modele1->GetNbPoint();
    j2=_modele2->GetNbPoint();
}

void ControlleurTetrisMulti::GetNbEtages(int &j1, int &j2)
{
    j1=_modele1->GetNbEtageDetruits();
    j2=_modele2->GetNbEtageDetruits();
}

void ControlleurTetrisMulti::RetourMenu()
{
    emit RetourAuMenu();
}

void ControlleurTetrisMulti::Reset()
{
    delete _modele1;
    delete _modele2;


    _modele1=new TetrisMultijoueur(_n,_Setpiece,_taille);
    _modele2=new TetrisMultijoueur(_n,_Setpiece,_taille);

    connect(_modele1,&TetrisMultijoueur::EnvoieLigne,this,&ControlleurTetrisMulti::EnvoieCarreM1toM2);
    connect(_modele2,&TetrisMultijoueur::EnvoieLigne,this,&ControlleurTetrisMulti::EnvoieCarreM2toM1);


    connect(_modele1,&TetrisMultijoueur::DeplacementImpossible,&_vue.GetJeu1(),&TetrisClassiqueOpenGl::Bump_sfx);
    connect(_modele1,&TetrisMultijoueur::RotationImpossible,&_vue.GetJeu1(),&TetrisClassiqueOpenGl::Bump_sfx);
    connect(_modele1,&TetrisMultijoueur::PiecePose,&_vue.GetJeu1(),&TetrisClassiqueOpenGl::Pose_sfx);

    connect(_modele2,&TetrisMultijoueur::DeplacementImpossible,&_vue.GetJeu2(),&TetrisClassiqueOpenGl::Bump_sfx);
    connect(_modele2,&TetrisMultijoueur::RotationImpossible,&_vue.GetJeu2(),&TetrisClassiqueOpenGl::Bump_sfx);
    connect(_modele2,&TetrisMultijoueur::PiecePose,&_vue.GetJeu2(),&TetrisClassiqueOpenGl::Pose_sfx);


    _vue.reset();

}
