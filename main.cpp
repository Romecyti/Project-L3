#include <iostream>
#include<QApplication>
#include<QtWidgets>
#include<QtMultimedia/QMediaPlaylist>
#include<QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QAudioOutput>
//#include"./controlleur/lescontrolleurs.hh"
#include"controlleur/supercontrolleur.hh"
#include"controlleur/controlleurtetrismulti.hh"

int main(int argc ,char *argv[])
{
    QApplication app(argc,argv);

    std::srand(time(nullptr));



  SuperControlleur sc;

  sc.show();


    //VueTetrisMulti m(NonAlterableSettings (),nullptr);
    //m.show();

    /*
    SettingsController sc(nullptr);

    ControlleurTetrisMulti m(NIVEAU::facile,SetDePiece::old_school,Position{6,15,6},sc.getDefaultSettings(),nullptr);
    m.GetVue()->show();
    m.GetVue()->setFocus();*/

return app.exec();
}


