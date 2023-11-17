#include "tetris_classique_resultats.hh"

TetrisClassiqueResultats::TetrisClassiqueResultats(QWidget *parent) : QWidget(parent)
{

    _Vlay = new QVBoxLayout();

    _titre=new QLabel(tr("Perdu !"),this);
    _titre->setAlignment(Qt::AlignCenter);

    _points=new QLabel(this);
    _points->setAlignment(Qt::AlignCenter);
    _etages=new QLabel(this);
    _etages->setAlignment(Qt::AlignCenter);

    _reset=new QPushButton(tr("Rejouer"),this);
    _Quit=new QPushButton(tr("Quitter"),this);

    _Hlay=new QHBoxLayout();
    _Hlay->addWidget(_reset);
    _Hlay->addWidget(_Quit);

    //_Vlay2= new QVBoxLayout();



    _Vlay->addWidget(_titre);
   // _Vlay->addLayout(_Vlay2);
    _Vlay->addStretch(0);
    _Vlay->addWidget(_points);
    _Vlay->addWidget(_etages);
    _Vlay->addStretch(0);
    _Vlay->addLayout(_Hlay);
    this->setLayout(_Vlay);

    connect(_reset,&QPushButton::clicked,this,[=](){emit Rejouer();});
    connect(_Quit,&QPushButton::clicked,this,[=](){emit Quitter();});
}

TetrisClassiqueResultats::~TetrisClassiqueResultats()
{
    delete _titre;
    delete _points;
    delete _etages;
    delete _reset;
    delete _Quit;
    delete _Hlay;
    //delete _Vlay2;
    delete _Vlay;

    //QWidget::~QWidget();
}

void TetrisClassiqueResultats::Resultat(int points, int etages)
{
    _points->setText(tr("Score : ") + QString::number(points));
    _etages->setText(tr("Nombre d'étages complétés : ")+ QString::number(etages));
}

