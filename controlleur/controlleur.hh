#pragma once
#include<QtWidgets>


enum class controlleurs{
    tet_class,
    menu


};

class Controlleur:public QObject
{
public:

    Controlleur();
    virtual ~Controlleur()=default;
Q_OBJECT
public slots:
    virtual void ChangeControlleur()=0;
signals:
     void ChangerControlleur(controlleurs c);

};

