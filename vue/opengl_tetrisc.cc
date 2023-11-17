#include "opengl_tetrisc.hh"

TetrisClassiqueOpenGl::TetrisClassiqueOpenGl(NonAlterableSettings set, QWidget *parent) : QOpenGLWidget(parent),quit(tr("Quitter"),this),retry(tr("Recommencer"),this),pause(tr("Pause"),this)
{

    _posesfx.setSource(QUrl("qrc:/ressources/init_sfx.wav"));
    _bumpsfx.setSource(QUrl("qrc:/ressources/bump_sfx.wav"));



    _options=set;




    setMinimumSize(800,800);
    _vitesse_rotation_x=5;
    _TypeRotationClassique=_options.getCameraForAndBackWardSensitivity()==ForAndBackWardCameraSens::classic;
    _vitesse_rotation_y=_options.getCameraRightAndLeftSensitivity();

    _rotation_plateau_y=0;
    _rotation_plateau_x=0;
    _hauteurmatrice=0;
    _Points=0;

    _reserve=nullptr;



    connect(&retry,&QPushButton::clicked,this,[=](){emit Recommencer();});
    connect(&quit,&QPushButton::clicked,this,[=](){emit Quitter();});
    connect(&pause,&QPushButton::clicked,this,[=](){emit Pause();});

   pause.setFocusPolicy(Qt::ClickFocus);

}

TetrisClassiqueOpenGl::~TetrisClassiqueOpenGl()
{
    makeCurrent();
    for(unsigned int i=0;i<_textures.size();i++)
    {
        delete _textures[i];
    }
}

TetrisClassiqueOpenGl::normale TetrisClassiqueOpenGl::CalculerNormale(point s0, point s1, point s2)
{
    normale n;

    float v0x = s2.x - s1.x;

    float v0y = s2.y - s1.y;
    float v0z = s2.z - s1.z;
    float v1x = s0.x - s1.x;
    float v1y = s0.y - s1.y;
    float v1z = s0.z - s1.z;

    n.x=(v0y * v1z) - (v0z *v1y);
    n.y=(v0z * v1x) - (v0x *v1z);
    n.z=(v0x * v1y) - (v0y *v1x);

    float norme = sqrtf(n.x*n.x + n.y*n.y + n.z*n.z);

    n.x=n.x/norme;
    n.y=n.y/norme;
    n.z=n.z/norme;
    return n;
}

GLvoid TetrisClassiqueOpenGl::AfficheCube( couleur coul)
{
    glPushMatrix();
    {
        glEnable(GL_POLYGON_SMOOTH);
        glHint(GL_POLYGON_SMOOTH,GL_NICEST);


        TranslateCouleurs(coul);
        glCallList(5);


        glDisable(GL_POLYGON_SMOOTH);
    }
    glPopMatrix();
}

GLvoid TetrisClassiqueOpenGl::AfficheMatrice(const Matrice3D &mat)
{
    GLfloat halfsize = 0.5;

    glPushMatrix();
    {

        glTranslatef(-static_cast<float>(mat.Width())/2,-static_cast<float>(mat.Height())/2,-static_cast<float>(mat.Depth())/2);

        for (auto i(0); i <mat.Height(); i++) {
            for (auto j(0); j < mat.Width(); j++) {
                for (auto k(0); k < mat.Depth(); k++) {

                    if(mat.Exist({j,i,k})){
                        glPushMatrix();
                        {
                            glTranslatef(j+halfsize,i+halfsize,k+halfsize);
                            AfficheCube( mat.GetAt({j,i,k}).GetCouleur());
                        }
                        glPopMatrix();
                    }

                }
            }
        }
    }
    glPopMatrix();
}

GLvoid TetrisClassiqueOpenGl::AfficheFils( couleur coul)
{
    TranslateCouleurs(coul);

    //glLineWidth(0.5);
    glEnable(GL_LINE_SMOOTH);
    glHint(GL_LINE_SMOOTH,GL_NICEST);
    glCallList(6);
    glDisable(GL_LINE_SMOOTH);

}

GLvoid TetrisClassiqueOpenGl::AfficheMatriceAvecCadrillage(const Matrice3D &mat)
{
    GLfloat halfsize = 0.5;
    glLineWidth(2);
    glPushMatrix();
    {

        glTranslatef(-static_cast<float>(mat.Width())/2,-static_cast<float>(mat.Height())/2,-static_cast<float>(mat.Depth())/2);

        for (auto i(0); i <mat.Height(); i++) {
            for (auto j(0); j < mat.Width(); j++) {
                for (auto k(0); k < mat.Depth(); k++) {

                    if(mat.Exist({j,i,k})){
                        glPushMatrix();
                        {
                            glTranslatef(j+halfsize,i+halfsize,k+halfsize);
                            AfficheCube( mat.GetAt({j,i,k}).GetCouleur());
                        }
                        glPopMatrix();

                        glPushMatrix();
                        {
                            glTranslatef(j+halfsize,i+halfsize,k+halfsize);
                            AfficheFils(couleur::orange);
                        }
                        glPopMatrix();

                    }


                }
            }
        }
    }
    glPopMatrix();
    glLineWidth(1);
    //AfficherCadrillagePlateau(mat);
}

GLvoid TetrisClassiqueOpenGl::AfficherCadrillagePlateau(const Matrice3D & m )
{
    glCallList(2);
    float halfsize=0.5;
    glPushMatrix();
    TranslateCouleurs(couleur::gris);
    glTranslatef(halfsize-static_cast<float>(m.Width())/2,halfsize - static_cast<float>(m.Height())/2,halfsize - static_cast<float>(m.Depth())/2);





    for(float h(-1);h<m.HauteurMax()+1;h+=1){

        for(float w(-1);w<m.Width();w+=1){

            glPushMatrix();
            {
                glTranslatef(w+0.5,h+0.5,-0.5);
                glBegin(GL_LINES);
                glVertex3f(0,0,0);
                glVertex3f(0,0,m.Depth());
                glEnd();

            }
            glPopMatrix();
        }
    }



    for(float h(-1);h<m.HauteurMax()+1;h+=1){
        for(float d(-1);d<m.Depth();d+=1){
            glPushMatrix();
            {
                glTranslatef(-0.5,h+0.5,d+0.5);
                glBegin(GL_LINES);
                glVertex3f(0,0,0);
                glVertex3f(m.Width(),0,0);
                glEnd();

            }
            glPopMatrix();
        }
    }
    for(float w(-1);w<m.Width();w+=1){
        for(float d(-1);d<m.Depth();d+=1){

            glPushMatrix();
            {
                glTranslatef(w+0.5,-0.5,d+0.5);
                glBegin(GL_LINES);
                glVertex3f(0,0,0);
                glVertex3f(0,m.HauteurMax()+1,0);
                glEnd();

            }
            glPopMatrix();
        }
    }

    glPopMatrix();
}

GLvoid TetrisClassiqueOpenGl::AfficherPlateau()
{
    glPushMatrix();
    {




        glRotatef(_rotation_plateau_x,1,0,0);
        glRotatef(_rotation_plateau_y,0,1,0);

        emit aboutPLateau(_plato);
        //AfficheMatrice(_plato);
        AfficheMatriceAvecCadrillage(_plato);
        //AfficherCadrillagePlateau(_plato);



    }
    glPopMatrix();
}

GLvoid TetrisClassiqueOpenGl::AfficherBordPlateau()
{
    glPushMatrix();
    {
        glRotatef(_rotation_plateau_x,1,0,0);
        glRotatef(_rotation_plateau_y,0,1,0);

        glEnable(GL_LINE_SMOOTH);
        glHint(GL_LINE_SMOOTH,GL_NICEST);


        glCallList(2);
        glCallList(3);
        glCallList(4);

        glDisable(GL_LINE_SMOOTH);
    }
    glPopMatrix();
}

GLvoid TetrisClassiqueOpenGl::AfficherPieceActuelle()
{

    glPushMatrix();
    {
        emit AboutPieceActuelle(_pieceactu);
        emit AboutPositionPieceActuelle(_posPieceActu);


        if(_old_y_pos > _posPieceActu._y)
            _old_y_pos-=0.1;
        else if(_old_y_pos <_posPieceActu._y)
            _old_y_pos=_posPieceActu._y;


        float halfsizex=static_cast<float>(_pieceactu->GetMatrice().Width())/2;
        float halfsizey=static_cast<float>(_pieceactu->GetMatrice().Height())/2;
        float halfsizez=static_cast<float>(_pieceactu->GetMatrice().Depth())/2;

        glRotatef(_rotation_plateau_x,1,0,0);
        glRotatef(_rotation_plateau_y,0,1,0);

        glTranslatef(_posPieceActu._x,_old_y_pos,_posPieceActu._z);
        glTranslatef(halfsizex-static_cast<float>(_plato.Width())/2,halfsizey-static_cast<float>(_plato.Height())/2,halfsizez-static_cast<float>(_plato.Depth())/2);
        AfficheMatriceAvecCadrillage(_pieceactu->GetMatrice());


    }
    glPopMatrix();
}

GLvoid TetrisClassiqueOpenGl::AfficherSuivants()
{

    float ratio = static_cast<float>(width())/static_cast<float>(height());
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    {
        glLoadIdentity();
        glOrtho(-10*ratio,10*ratio,-10,10,-1.5,15);
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        {
            glLoadIdentity();

            glTranslatef(0.75*(10*ratio),6.5,0);
            glPushMatrix();
            {
                int pos_y=1;
                glScalef(0.5,0.5,0.5);
                emit AboutSuivant(_suivant);
                for(auto &i : _suivant)
                {
                    glPushMatrix();
                    {
                        glTranslatef(0,pos_y,0);
                        glRotatef(30,0,1,0);
                        glRotatef(20,1,0,0);
                        AfficheMatriceAvecCadrillage(i->GetMatrice());
                    }
                    glPopMatrix();
                    pos_y=pos_y-5;
                }


            }
            glPopMatrix();

            glEnable(GL_TEXTURE_2D);
            glTranslatef(-1,2,0);
            _textures.at(13)->bind();
            glScalef(1.5,0.75,1);
            glCallList(7);
            glDisable(GL_TEXTURE_2D);
            glMatrixMode(GL_PROJECTION);
        }
        glPopMatrix();
        glMatrixMode(GL_MODELVIEW);
    }
    glPopMatrix();
}

GLvoid TetrisClassiqueOpenGl::AfficherReserve()
{
    emit ReserveState(_EtatReserve);
    float ratio = static_cast<float>(width())/static_cast<float>(height());
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    {
        glLoadIdentity();
        glOrtho(-10*ratio,10*ratio,-10,10,-1,5);
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        {
            glLoadIdentity();

            glTranslatef(0.75*(10*ratio),-6.5,0);

            if(_EtatReserve)
            {


                emit AboutReserve(_reserve);
                glPushMatrix();
                {

                    glTranslatef(0,0,-1);
                    glScalef(0.8,0.8,0.8);
                    glRotatef(30,0,1,0);
                    glRotatef(25,1,0,0);
                    AfficheMatriceAvecCadrillage(_reserve->GetMatrice());

                }
                glPopMatrix();
            }

            glBegin(GL_LINE_LOOP);
            {

                glVertex3f(-2,2,0);//1
                glVertex3f(2,2,0);//2

                glVertex3f(2,-2,0);//3
                glVertex3f(-2,-2,0);//4

            }
            glEnd();

            glEnable(GL_TEXTURE_2D);
            glTranslatef(-1,2,0.1);
            _textures.at(12)->bind();
            glScalef(1.5,0.75,1);
            glCallList(7);
            glDisable(GL_TEXTURE_2D);

            glMatrixMode(GL_PROJECTION);
        }
        glPopMatrix();
        glMatrixMode(GL_MODELVIEW);
    }
    glPopMatrix();
}

GLvoid TetrisClassiqueOpenGl::AfficherCartonPause()
{
    glPushMatrix();
    {

        glScalef(5,2.5,1);
        TranslateCouleurs(couleur::orange);
        _textures.at(10)->bind();
        glEnable(GL_TEXTURE_2D);
        glCallList(7);
        glDisable(GL_TEXTURE_2D);
    }
    glPopMatrix();
}

GLvoid TetrisClassiqueOpenGl::AfficherScore()
{
    emit AboutScore(_Points);

    float ratio = static_cast<float>(width())/static_cast<float>(height());
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    {
        glLoadIdentity();
        glOrtho(-10*ratio,10*ratio,-10,10,-1,1);
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        {
            glLoadIdentity();

            glTranslatef(-0.8*(10*ratio),8,0);
            TranslateNombre(_Points);
            glTranslatef(-1,0,0);
            _textures.at(14)->bind();
            glEnable(GL_TEXTURE_2D);
            glScalef(1.5,0.75,1);
            glCallList(7);
            glDisable(GL_TEXTURE_2D);




            glMatrixMode(GL_PROJECTION);
        }
        glPopMatrix();
        glMatrixMode(GL_MODELVIEW);
    }
    glPopMatrix();



}

GLvoid TetrisClassiqueOpenGl::AfficherNiveau()
{
    int nivo=0;
    emit AboutNiveau(nivo);
    float ratio = static_cast<float>(width())/static_cast<float>(height());
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    {
        glLoadIdentity();
        glOrtho(-10*ratio,10*ratio,-10,10,-1,1);
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        {
            glLoadIdentity();


            glTranslatef(-0.8*(10*ratio),6,0);
            TranslateNombre(nivo);

            glTranslatef(-1,0,0);
            _textures.at(11)->bind();
            glEnable(GL_TEXTURE_2D);
            glScalef(1.5,0.75,1);
            glCallList(7);
            glDisable(GL_TEXTURE_2D);


            glMatrixMode(GL_PROJECTION);
        }
        glPopMatrix();
        glMatrixMode(GL_MODELVIEW);
    }
    glPopMatrix();


}

void TetrisClassiqueOpenGl::keyPressEvent(QKeyEvent *e)
{

    this->parentWidget()->setFocus();

}


GLvoid TetrisClassiqueOpenGl::TranslateCouleurs(couleur c)
{
    switch (c) {
    case couleur::bleu:
        glColor3ub(0,0,255);
        break;
    case couleur::gris:
        glColor3ub(128,128,128);
        break;
    case couleur::rose:
        glColor3ub(255,153,204);
        break;
    case couleur::vert:
        glColor3ub(0,255,0);
        break;
    case couleur::jaune:
        glColor3ub(255,255,0);
        break;
    case couleur::rouge:
        glColor3ub(255,0,0);
        break;
    case couleur::marron:
        glColor3ub(204,102,0);
        break;
    case couleur::orange:
        glColor3ub(255,140,0);
        break;

    case couleur::cyan :
        glColor3ub(255,0,255);
        break;

    case couleur::sapin :
        glColor3ub(9,82,40);
        break;

    case couleur::bordeaux :
        glColor3ub(109,7,26);
        break;

    case couleur::violet :
        glColor3ub(200,0,200);
        break;
    case couleur::blanc:
        glColor3ub(255,255,255);
        break;
        ;

    }
}

GLvoid TetrisClassiqueOpenGl::TranslateNombre(int i)
{ glPushMatrix();


    if(i<=0)
    {
        glEnable(GL_TEXTURE_2D);
        _textures.at(0)->bind();

        glPushMatrix();
        glScalef(0.6,0.75,1);
        glCallList(7);
        glPopMatrix();
        glDisable(GL_TEXTURE_2D);
    }
    else {

        glEnable(GL_TEXTURE_2D);

        float nbChiffre= static_cast<int>(floor(log10(i))+1);
        glTranslatef(0.8*(nbChiffre)+0.4,0,0);

        int current=0;

        while(nbChiffre >0)
        {
            current= i/pow(10,nbChiffre-1);
            current=current % 10;
            //std::cout << current<<"\n";

            glPushMatrix();
            glTranslatef(0.8*-nbChiffre,0,0);
            glScalef(0.8,1,1);
            _textures.at(current)->bind();
            glCallList(7);
            glPopMatrix();

            nbChiffre--;
        }
        glDisable(GL_TEXTURE_2D);


    }
    glPopMatrix();
}



void TetrisClassiqueOpenGl::OnCamRightPressed()
{
    _rotation_plateau_y-=_vitesse_rotation_y;
    if(_rotation_plateau_y<0)
        _rotation_plateau_y+=360;
}

void TetrisClassiqueOpenGl::OnCamLeftPressed()
{
    _rotation_plateau_y+=_vitesse_rotation_y;
    if(_rotation_plateau_y>360)
        _rotation_plateau_y-=360;
}

void TetrisClassiqueOpenGl::OnCamForwardPressed()
{
    if(_rotation_plateau_x<90 && _TypeRotationClassique)
        _rotation_plateau_x+=_vitesse_rotation_x;
    else {
        if(static_cast<int>(_rotation_plateau_x)==0)
            _rotation_plateau_x=90;
        else if (static_cast<int>(_rotation_plateau_x)==-15) {
            _rotation_plateau_x=0;
        }
    }
}

void TetrisClassiqueOpenGl::OnCamBackwardPressed()
{
    if(_rotation_plateau_x >-15 && _TypeRotationClassique)
        _rotation_plateau_x-=_vitesse_rotation_x;
    else {
        if(static_cast<int>(_rotation_plateau_x)==90)
            _rotation_plateau_x=0;
        else if (static_cast<int>(_rotation_plateau_x)==0){
            _rotation_plateau_x=-15;
        }
    }
}

void TetrisClassiqueOpenGl::OnMouvBackwardPressed()
{
    if(_rotation_plateau_y >=315 || _rotation_plateau_y < 45 ){
        emit Deplacement(DIRECTION_MOUVEMENT::arriere);
    }
    else if(_rotation_plateau_y >=45 && _rotation_plateau_y < 135 ){
        emit Deplacement(DIRECTION_MOUVEMENT::droite);
    }
    else if(_rotation_plateau_y >=135 && _rotation_plateau_y < 225 ){
        emit Deplacement(DIRECTION_MOUVEMENT::avant);
    }
    else if(_rotation_plateau_y >=225 && _rotation_plateau_y < 315 ){
        emit Deplacement(DIRECTION_MOUVEMENT::gauche);
    }
}

void TetrisClassiqueOpenGl::OnMouvForwardPressed()
{
    if(_rotation_plateau_y >=315 || _rotation_plateau_y < 45 ){
        emit Deplacement(DIRECTION_MOUVEMENT::avant);
    }
    else if(_rotation_plateau_y >=45 && _rotation_plateau_y < 135 ){
        emit Deplacement(DIRECTION_MOUVEMENT::gauche);
    }
    else if(_rotation_plateau_y >=135 && _rotation_plateau_y < 225 ){
        emit Deplacement(DIRECTION_MOUVEMENT::arriere);
    }
    else if(_rotation_plateau_y >=225 && _rotation_plateau_y < 315 ){
        emit Deplacement(DIRECTION_MOUVEMENT::droite);
    }
}

void TetrisClassiqueOpenGl::OnMouvLeftPressed()
{
    if(_rotation_plateau_y >=315 || _rotation_plateau_y < 45 ){
        emit Deplacement(DIRECTION_MOUVEMENT::gauche);
    }
    else if(_rotation_plateau_y >=45 && _rotation_plateau_y < 135 ){
        emit Deplacement(DIRECTION_MOUVEMENT::arriere);
    }
    else if(_rotation_plateau_y >=135 && _rotation_plateau_y < 225 ){
        emit Deplacement(DIRECTION_MOUVEMENT::droite);
    }
    else if(_rotation_plateau_y >=225 && _rotation_plateau_y < 315 ){
        emit Deplacement(DIRECTION_MOUVEMENT::avant);
    }
}

void TetrisClassiqueOpenGl::OnMouvRightPressed()
{
    if(_rotation_plateau_y >=315 || _rotation_plateau_y < 45 ){
        emit Deplacement(DIRECTION_MOUVEMENT::droite);
    }
    else if(_rotation_plateau_y >=45 && _rotation_plateau_y < 135 ){
        emit Deplacement(DIRECTION_MOUVEMENT::avant);
    }
    else if(_rotation_plateau_y >=135 && _rotation_plateau_y < 225 ){
        emit Deplacement(DIRECTION_MOUVEMENT::gauche);
    }
    else if(_rotation_plateau_y >=225 && _rotation_plateau_y < 315 ){
        emit Deplacement(DIRECTION_MOUVEMENT::arriere);
    }
}

void TetrisClassiqueOpenGl::OnMouvDownPressed()
{
    emit Deplacement(DIRECTION_MOUVEMENT::bas);
    emit AboutPositionPieceActuelle(_posPieceActu);
    _old_y_pos=_posPieceActu._y;
}

void TetrisClassiqueOpenGl::OnRotXRightPressed()
{
    if(_rotation_plateau_y >=315 || _rotation_plateau_y < 45 ){
        emit Rotation(DIRECTION_ROT::rotX_droite);
    }
    else if(_rotation_plateau_y >=45 && _rotation_plateau_y < 135 ){
        emit Rotation(DIRECTION_ROT::rotZ_droite);
    }
    else if(_rotation_plateau_y >=135 && _rotation_plateau_y < 225 ){
        emit Rotation(DIRECTION_ROT::rotX_gauche);
    }
    else if(_rotation_plateau_y >=225 && _rotation_plateau_y < 315 ){
        emit Rotation(DIRECTION_ROT::rotZ_gauche);
    }
}

void TetrisClassiqueOpenGl::OnRotXLeftPressed()
{
    if(_rotation_plateau_y >=315 || _rotation_plateau_y < 45 ){
        emit Rotation(DIRECTION_ROT::rotX_gauche);
    }
    else if(_rotation_plateau_y >=45 && _rotation_plateau_y < 135 ){
        emit Rotation(DIRECTION_ROT::rotZ_gauche);
    }
    else if(_rotation_plateau_y >=135 && _rotation_plateau_y < 225 ){
        emit Rotation(DIRECTION_ROT::rotX_droite);
    }
    else if(_rotation_plateau_y >=225 && _rotation_plateau_y < 315 ){
        emit Rotation(DIRECTION_ROT::rotZ_droite);
    }
}

void TetrisClassiqueOpenGl::OnRotYRightPressed()
{
    emit Rotation(DIRECTION_ROT::rotY_droite);
}

void TetrisClassiqueOpenGl::OnRotYLeftPressed()
{
    emit Rotation(DIRECTION_ROT::rotY_gauche);
}

void TetrisClassiqueOpenGl::OnRotZLeftPressed()
{
    if(_rotation_plateau_y >=315 || _rotation_plateau_y < 45 ){
        emit Rotation(DIRECTION_ROT::rotZ_gauche);
    }
    else if(_rotation_plateau_y >=45 && _rotation_plateau_y < 135 ){
        emit Rotation(DIRECTION_ROT::rotX_gauche);
    }
    else if(_rotation_plateau_y >=135 && _rotation_plateau_y < 225 ){
        emit Rotation(DIRECTION_ROT::rotZ_droite);
    }
    else if(_rotation_plateau_y >=225 && _rotation_plateau_y < 315 ){
        emit Rotation(DIRECTION_ROT::rotX_droite);
    }
}

void TetrisClassiqueOpenGl::OnRotZRightPressed()
{
    if(_rotation_plateau_y >=315 || _rotation_plateau_y < 45 ){
        emit Rotation(DIRECTION_ROT::rotZ_droite);;
    }
    else if(_rotation_plateau_y >=45 && _rotation_plateau_y < 135 ){
        emit Rotation(DIRECTION_ROT::rotX_droite);
    }
    else if(_rotation_plateau_y >=135 && _rotation_plateau_y < 225 ){
        emit Rotation(DIRECTION_ROT::rotZ_gauche);
    }
    else if(_rotation_plateau_y >=225 && _rotation_plateau_y < 315 ){
        emit Rotation(DIRECTION_ROT::rotX_gauche);
    }

}

void TetrisClassiqueOpenGl::OnReservePressed()
{
    emit UseReserve();

}

void TetrisClassiqueOpenGl::OnPausePressed()
{
    emit Pause();
}








void TetrisClassiqueOpenGl::initializeGL()
{


    emit AboutPositionPieceActuelle(_posPieceActu);
    _old_y_pos=_posPieceActu._y;
    emit aboutPLateau(_plato);

    float halfsize=0.5;
    _hauteurmatrice=_plato.Height();

    glClearColor(0,0,0,1);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_CULL_FACE);
    /*
    GLfloat ambiente [4]={0.25,0.25,0.25,1.0};
    glLightfv(GL_LIGHT0,GL_AMBIENT,ambiente);
    GLfloat diff[4]={0.2,0.2,0.2,1.0};
    glLightfv(GL_LIGHT0,GL_DIFFUSE,diff);
    glLightfv(GL_LIGHT0,GL_SPECULAR,diff);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,ambiente);*/
    glEnable(GL_LIGHT0);


    glColorMaterial(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);


    _textures.push_back(new QOpenGLTexture(QImage(":/ressources/0.png")));
    _textures.push_back(new QOpenGLTexture(QImage(":/ressources/1.png")));
    _textures.push_back(new QOpenGLTexture(QImage(":/ressources/2.png")));
    _textures.push_back(new QOpenGLTexture(QImage(":/ressources/3.png")));
    _textures.push_back(new QOpenGLTexture(QImage(":/ressources/4.png")));
    _textures.push_back(new QOpenGLTexture(QImage(":/ressources/5.png")));
    _textures.push_back(new QOpenGLTexture(QImage(":/ressources/6.png")));
    _textures.push_back(new QOpenGLTexture(QImage(":/ressources/7.png")));
    _textures.push_back(new QOpenGLTexture(QImage(":/ressources/8.png")));
    _textures.push_back(new QOpenGLTexture(QImage(":/ressources/9.png")));
    _textures.push_back(new QOpenGLTexture(QImage(":/ressources/pause.png")));
    _textures.push_back(new QOpenGLTexture(QImage(":/ressources/niveau.png")));
    _textures.push_back(new QOpenGLTexture(QImage(":/ressources/reserve.png")));
    _textures.push_back(new QOpenGLTexture(QImage(":/ressources/suivant.png")));
    _textures.push_back(new QOpenGLTexture(QImage(":/ressources/score.png")));


    //listes



    //2 Liste d'afficahe des ligne de l'axe y du cadrillage du plateau


    glNewList(2,GL_COMPILE);
    {


        glPushMatrix();
        {

            TranslateCouleurs(couleur::gris);
            glPushMatrix();
            {

                glScalef(_plato.Width(),_plato.Height(),_plato.Depth());
                AfficheFils(couleur::gris);

            }
            glPopMatrix();


        }
        glPopMatrix();


    }
    glEndList();

    //3 Liste d'afficahe des ligne de l'axe x du cadrillage du plateau
    glNewList(3,GL_COMPILE);
    {


        glPushMatrix();
        TranslateCouleurs(couleur::gris);
        glTranslatef(halfsize-static_cast<float>(_plato.Width())/2,halfsize - static_cast<float>(_plato.Height())/2,halfsize - static_cast<float>(_plato.Depth())/2);
        for(float w(-1);w<_plato.Width();w+=1){

            glPushMatrix();
            {
                glTranslatef(w+0.5,-0.5,-0.5);
                glBegin(GL_LINES);
                glVertex3f(0,0,0);
                glVertex3f(0,0,_plato.Depth());
                glEnd();

            }
            glPopMatrix();


            /*glPushMatrix();
                              {
                                  glTranslatef(w+0.5,_plato.Height()-0.5,-0.5);
                                  glBegin(GL_LINES);
                                      glVertex3f(0,0,0);
                                      glVertex3f(0,0,_plato.Depth());
                                  glEnd();

                              }
                              glPopMatrix();*/
        }


        glPopMatrix();



    }
    glEndList();

    //4 Liste d'afficahe des ligne de l'axe z du cadrillage du plateau
    glNewList(4,GL_COMPILE);
    {
        glPushMatrix();
        TranslateCouleurs(couleur::gris);
        glTranslatef(halfsize-static_cast<float>(_plato.Width())/2,halfsize - static_cast<float>(_plato.Height())/2,halfsize - static_cast<float>(_plato.Depth())/2);
        for(float d(-1);d<_plato.Depth();d+=1){
            glPushMatrix();
            {
                glTranslatef(-0.5,-0.5,d+0.5);
                glBegin(GL_LINES);
                glVertex3f(0,0,0);
                glVertex3f(_plato.Width(),0,0);
                glEnd();

            }
            glPopMatrix();
            /*glPushMatrix();
                               {
                                   glTranslatef(-0.5,_plato.Height()-0.5,d+0.5);
                                   glBegin(GL_LINES);
                                       glVertex3f(0,0,0);
                                       glVertex3f(_plato.Width(),0,0);
                                   glEnd();

                               }
                               glPopMatrix();*/
        }


        glPopMatrix();

    }
    glEndList();

    //5 liste d'affichage d'un cube
    normale norm;
    point S1={-halfsize,halfsize,halfsize};
    point S2={-halfsize,-halfsize,halfsize};
    point S3={halfsize,-halfsize,halfsize};
    point S4={halfsize,halfsize,halfsize};

    point S5={halfsize,halfsize,-halfsize};
    point S6={halfsize,-halfsize,-halfsize};
    point S7={-halfsize,-halfsize,-halfsize};
    point S8={-halfsize,halfsize,-halfsize};
    glNewList(5,GL_COMPILE);
    {
        glPushMatrix();
        {

            glBegin(GL_QUADS);{
                //face avant{1 2 3 4}

                norm=CalculerNormale(S1,S2,S4);
                glNormal3f(norm.x,norm.y,norm.z);
                glVertex3f(S1.x,S1.y,S1.z);
                glVertex3f(S2.x,S2.y,S2.z);
                glVertex3f(S3.x,S3.y,S3.z);
                glVertex3f(S4.x,S4.y,S4.z);


                //face droite(4,3,6,5)

                norm=CalculerNormale(S4,S3,S5);
                glNormal3f(norm.x,norm.y,norm.z);
                glVertex3f(S4.x,S4.y,S4.z);
                glVertex3f(S3.x,S3.y,S3.z);
                glVertex3f(S6.x,S6.y,S6.z);
                glVertex3f(S5.x,S5.y,S5.z);

                //face arrière(5,6,7,8)

                norm=CalculerNormale(S5,S6,S8);
                glNormal3f(norm.x,norm.y,norm.z);
                glVertex3f(S5.x,S5.y,S5.z);
                glVertex3f(S6.x,S6.y,S6.z);
                glVertex3f(S7.x,S7.y,S7.z);
                glVertex3f(S8.x,S8.y,S8.z);



                //face gauche(8,7,2,1)

                norm=CalculerNormale(S8,S7,S1);
                glNormal3f(norm.x,norm.y,norm.z);
                glVertex3f(S8.x,S8.y,S8.z);
                glVertex3f(S7.x,S7.y,S7.z);
                glVertex3f(S2.x,S2.y,S2.z);
                glVertex3f(S1.x,S1.y,S1.z);



                //face du dessous(2,7,6,3)
                norm=CalculerNormale(S2,S7,S3);
                glNormal3f(norm.x,norm.y,norm.z);
                glVertex3f(S2.x,S2.y,S2.z);
                glVertex3f(S7.x,S7.y,S7.z);
                glVertex3f(S6.x,S6.y,S6.z);
                glVertex3f(S3.x,S3.y,S3.z);



                //face du dessus(8,1,4,5)

                norm=CalculerNormale(S8,S1,S5);
                glNormal3f(norm.x,norm.y,norm.z);
                glVertex3f(S8.x,S8.y,S8.z);
                glVertex3f(S1.x,S1.y,S1.z);
                glVertex3f(S4.x,S4.y,S4.z);
                glVertex3f(S5.x,S5.y,S5.z);

            }
            glEnd();
        }
        glPopMatrix();

    }
    glEndList();
    //6 lisste d'affichage d'un cube en fils de fer
    glNewList(6,GL_COMPILE);

    glPushMatrix();
    {


        glBegin(GL_LINE_LOOP);
        {

            glVertex3f(-halfsize,-halfsize,halfsize);//1
            glVertex3f(halfsize,-halfsize,halfsize);//2

            glVertex3f(halfsize,-halfsize,-halfsize);//3
            glVertex3f(-halfsize,-halfsize,-halfsize);//4

        }
        glEnd();

        glBegin(GL_LINE_LOOP);
        {

            glVertex3f(-halfsize,halfsize,halfsize);//1
            glVertex3f(halfsize,halfsize,halfsize);//2

            glVertex3f(halfsize,halfsize,-halfsize);//3
            glVertex3f(-halfsize,halfsize,-halfsize);//4

        }
        glEnd();


        glBegin(GL_LINES);
        {
            glVertex3f(-halfsize,-halfsize,halfsize);
            glVertex3f(-halfsize,halfsize,halfsize);
        }
        glEnd();
        glBegin(GL_LINES);
        {
            glVertex3f(halfsize,-halfsize,halfsize);
            glVertex3f(halfsize,halfsize,halfsize);

        }
        glEnd();
        glBegin(GL_LINES);
        {
            glVertex3f(halfsize,-halfsize,-halfsize);
            glVertex3f(halfsize,halfsize,-halfsize);

        }
        glEnd();
        glBegin(GL_LINES);
        {
            glVertex3f(-halfsize,-halfsize,-halfsize);
            glVertex3f(-halfsize,halfsize,-halfsize);

        }
        glEnd();



    }
    glPopMatrix();


    glEndList();


    glNewList(7,GL_COMPILE);
    {


        glBegin(GL_QUADS);
        {

            norm=CalculerNormale(S1,S2,S4);
            glNormal3f(norm.x,norm.y,norm.z);

            glTexCoord2f(0,0);
            glVertex3f(S1.x,S1.y,0);//1

            glTexCoord2f(0, 1);
            glVertex3f(S2.x,S2.y,0);//2

            glTexCoord2f(1, 1);
            glVertex3f(S3.x,S3.y,0);//3

            glTexCoord2f(1, 0);
            glVertex3f(S4.x,S5.y,0);//4

        }
        glEnd();

    }
    glEndList();


    parentWidget()->setFocus();
}

void TetrisClassiqueOpenGl::resizeGL(int w, int h)
{
    pause.setGeometry(0,height()-40,100,40);
    quit.setGeometry((width()/2)-100,(height()/2)+30,80,30);
    retry.setGeometry((width()/2),(height()/2)+30,100,30);
    glViewport(0,0,h,w);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // gluPerspective(45, static_cast<GLdouble>(w)/static_cast<GLdouble>(h), 0.1, 150.0);

    GLdouble xmin, xmax, ymin, ymax;

    ymax = 0.1 * tan( 45 * M_PI / 360.0 );
    ymin = -ymax;
    xmin = ymin * (static_cast<GLdouble>(w)/static_cast<GLdouble>(h));
    xmax = ymax * (static_cast<GLdouble>(w)/static_cast<GLdouble>(h));

    glFrustum( xmin, xmax, ymin, ymax, 0.1, 150 );

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}

void TetrisClassiqueOpenGl::paintGL()
{

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


    glTranslatef(0,0,-30);

    bool fin=false;
    emit(JeuFinit(fin));

    bool pause=false;
    emit JeuPause(pause);



    if(!fin ){


        if(pause)
        {
            //pause
            glPushMatrix();
            {
                glTranslatef(0,0,10);
                AfficherCartonPause();
            }
            glPopMatrix();


            quit.show();


            retry.show();

        }
        else {
            quit.hide();
            retry.hide();
        }

        //Plateau
        glPushMatrix();
        {

            glTranslatef(0,0,5-(_hauteurmatrice*2));
            glScalef(2,2,2);
            if(!pause){
                AfficherPlateau();
                AfficherPieceActuelle();
            }
            AfficherBordPlateau();
        }
        glPopMatrix();




        if(!pause)
            AfficherSuivants();




        //reserve

            AfficherReserve();




        AfficherScore();
        AfficherNiveau();


        emit Jouer();

        this->update();

    }
    else {


        emit Fin(_Points);
    }



}
void TetrisClassiqueOpenGl::Bump_sfx(){

    _bumpsfx.play();
}

void TetrisClassiqueOpenGl::Pose_sfx()
{
    _posesfx.play();

}
