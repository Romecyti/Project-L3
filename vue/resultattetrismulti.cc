#include "resultattetrismulti.hh"

ResultatTetrisMulti::ResultatTetrisMulti(QWidget *parent) : QWidget(parent)
{

    _Main_Vlay=new QVBoxLayout();


    _titre=new QLabel(tr("Résultat"),this);
    _titre->setAlignment(Qt::AlignCenter);

    _joueurscore_Hlay = new QHBoxLayout();

    _J1_Vlay=new QVBoxLayout();
    _J1=new QLabel(tr("Joueur 1"),this);
    _J1->setAlignment(Qt::AlignCenter);
    _pointJ1=new QLabel(this);
    _pointJ1->setAlignment(Qt::AlignCenter);
    _NbetageJ1=new QLabel(this);
    _NbetageJ1->setAlignment(Qt::AlignCenter);

    _J1_Vlay->addWidget(_J1);
    _J1_Vlay->addWidget(_pointJ1);
    _J1_Vlay->addWidget(_NbetageJ1);


    _J2_Vlay=new QVBoxLayout();
    _J2=new QLabel(tr("Joueur 2"),this);
    _J2->setAlignment(Qt::AlignCenter);

    _pointJ2=new QLabel(this);
    _pointJ2->setAlignment(Qt::AlignCenter);
    _NbetageJ2=new QLabel(this);
    _NbetageJ2->setAlignment(Qt::AlignCenter);

    _J2_Vlay->addWidget(_J2);
    _J2_Vlay->addWidget(_pointJ2);
    _J2_Vlay->addWidget(_NbetageJ2);

    _joueurscore_Hlay->addLayout(_J1_Vlay);
    _joueurscore_Hlay->addLayout(_J2_Vlay);

    _gagnant=new QLabel(this);
    _gagnant->setAlignment(Qt::AlignCenter);

    _Hbuttonlay = new QHBoxLayout();
    _reset=new QPushButton(tr("Rejouer"),this);
    _Quit=new QPushButton(tr("quitter"),this);
    _Hbuttonlay->addWidget(_reset);
    _Hbuttonlay->addWidget(_Quit);

    _Main_Vlay->addWidget(_titre);
    _Main_Vlay->addLayout(_joueurscore_Hlay);
    _Main_Vlay->addWidget(_gagnant);
    _Main_Vlay->addLayout(_Hbuttonlay);







    this->setLayout(_Main_Vlay);
    connect(_reset,&QPushButton::clicked,this,[=](){emit Rejouer();});
    connect(_Quit,&QPushButton::clicked,this,[=](){emit Quitter();});
}

ResultatTetrisMulti::~ResultatTetrisMulti()
{


    delete _titre;

    delete   _J1;
    delete   _pointJ1;
    delete  _NbetageJ1;

    delete   _J2;
    delete   _pointJ2;
    delete   _NbetageJ2;

    delete   _gagnant;

    delete   _reset;
    delete   _Quit;
    delete   _J1_Vlay;
    delete   _J2_Vlay;
    delete   _Hbuttonlay;
    delete  _joueurscore_Hlay;
      delete _Main_Vlay;


}

void ResultatTetrisMulti::Resultat(int points1, int etage1, int points2, int etage2, Gagnant g)
{
    _pointJ1->setText(tr("Score : ") + QString::number(points1));
    _NbetageJ1->setText(tr("Nombre d'étages complétés : ")+ QString::number(etage1));
    _pointJ2->setText(tr("Score : ") + QString::number(points2));
    _NbetageJ2->setText(tr("Nombre d'étages complétés : ")+ QString::number(etage2));


        if(g==Gagnant::J1)
            _gagnant->setText(tr("le gagnant est le Joueur 1"));
        else
            _gagnant->setText(tr("le gagnant est le Joueur 2"));



}
