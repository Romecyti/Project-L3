#include "matrice3d.hh"
#include <iostream>


void Matrice3D::NettoiePronf(Cube *pt)
{
    if(pt !=nullptr)
    delete pt;
}

void Matrice3D::NettoieLargeur(std::vector<Cube *> *pt)
{
   if(pt != nullptr){
        for(int i=0;i<Depth();i++)
        {
            NettoiePronf(pt->at(i));

        }

        delete pt;
    }

}

void Matrice3D::NettoieHauteur(std::vector<std::vector<Cube *> *> *pt)
{
    if(pt != nullptr){
        for(int i=0;i<Width();i++)
        {
            NettoieLargeur(pt->at(i));


        }
        delete pt;
    }

}

Matrice3D::Matrice3D(): _matrice()
{

}

Matrice3D::Matrice3D(const Position &pos)//:_matrice(static_cast<std::size_t>(pos._z),nullptr)
{


    _taille._x=pos._x;
    _taille._y=pos._y;
    _taille._z=pos._z;

    for (int i=0;i<pos._y;i++) {

        _matrice.push_back(nullptr);
    }



}

Matrice3D::Matrice3D(const Matrice3D &M):_matrice(static_cast<std::size_t>(M.Height()),nullptr)
{


    _taille=M._taille;

   for(int h=0 ; h <Height() ; h++)
        {
            if(M.At(h)!=nullptr)
            {
                for(int i=0;i<Width();i++)

                    if(M.At(h)->at(i)!=nullptr)

                        for(int j=0;j<Depth();j++)
                            if(M.At(Position{i,h,j}))
                                Ajout(*M.At(Position{i,h,j}),Position{i,h,j});
            }
        }
}

Matrice3D::~Matrice3D()
{
    for(int i=0;i<Height();i++)
    {
        NettoieHauteur(_matrice.at(i));
    }



}

void Matrice3D::Ajout(const Cube &cube, const Position &pos)
{
     if(pos._y<Height() || pos._x<Width() || pos._z<Depth() )
     {
        if(_matrice.at(pos._y)==nullptr)
        {
            _matrice.at(pos._y)=new  std::vector<std::vector<Cube*>*>(Width(),nullptr);
        }
        if(_matrice.at(pos._y)->at(pos._x)==nullptr)
        {

            _matrice.at(pos._y)->at(pos._x)=new std::vector<Cube *> (Depth(),nullptr);
        }

        _matrice.at(pos._y)->at(pos._x)->at(pos._z)=new Cube(cube.GetCouleur());

     }
    else
     throw m3DepassementTaille("out of range");
}

void Matrice3D::Calque(const Matrice3D &sousMatrice, const Position &pos)
{
    if(pos._y+sousMatrice.Height() <= Height() || pos._x+sousMatrice.Width() <=Width() || pos._z+sousMatrice.Depth() <= Depth() )
    {

        for (int i=0;i<sousMatrice.Height();i++) {
            for (int j=0;j<sousMatrice.Width();j++) {
                for (int k=0;k<sousMatrice.Depth();k++) {
                    if(sousMatrice.Exist(Position{j,i,k}))
                        this->Ajout(*sousMatrice.At(Position{j,i,k}),Position{pos._x+j,pos._y+i,pos._z+k});
                }

            }
        }

    }
    else
        throw m3DepassementTaille("out of range");

}

bool Matrice3D::Exist(Position p) const
{
    if(p._y<Height() || p._x<Width() || p._z<Depth() )

        if(_matrice.at(p._y)==nullptr)
            return false ;
        else if(_matrice.at(p._y)->at(p._x)==nullptr)
             return false;
        else
        return _matrice.at(p._y)->at(p._x)->at(p._z);
    else
        throw m3DepassementTaille("out of range");
}

bool Matrice3D::ExistCarre(int h) const
{
    if(h<Height()){

        return _matrice.at(static_cast<unsigned int>(h))!=nullptr;

    }

     else {
        throw m3DepassementTaille("out of range");
    }
}

int Matrice3D::HauteurMax() const
{
    int i=0;

    while(ExistCarre(i))
    {

        i++;

    }
    return i;
}

Cube Matrice3D::GetAt(Position pos) const
{
    if(pos._y<Height() || pos._x<Width() || pos._z<Depth() )

        if(_matrice.at(pos._y)==nullptr)
            throw m3Exist("aucun cube à cette position");
        else if(_matrice.at(pos._y)->at(pos._x)==nullptr)
             throw m3Exist("aucun cube à cette position");
        else{
            if(_matrice.at(pos._y)->at(pos._x)->at(pos._z))
                return *_matrice.at(pos._y)->at(pos._x)->at(pos._z);
            else
                throw m3Exist("aucun cube à cette position");

        }
    else
       throw m3DepassementTaille("out of range");
}

Cube* Matrice3D::At(const Position &pos) const
{
    if(pos._y<Height() || pos._x<Width() || pos._z<Depth() )

        if(_matrice.at(pos._y)==nullptr)
            return nullptr;
        else if(_matrice.at(pos._y)->at(pos._x)==nullptr)
             return nullptr;
        else
        return _matrice.at(pos._y)->at(pos._x)->at(pos._z);
    else
       throw m3DepassementTaille("out of range");
}




std::vector<std::vector<Cube *> *> *Matrice3D::At(std::size_t hauteur) const
{
    return _matrice.at(hauteur) ;
}

int Matrice3D::Width() const
{
    return  _taille._x;
}

int Matrice3D::Height() const
{
    return  _taille._y;
}

int Matrice3D::Depth() const
{
    return  _taille._z;
}

void Matrice3D::ModifSize(const Position &pos)
{
    //hauteur
    if(pos._y >=Height() )
    {
       _matrice.resize(pos._y,nullptr);

    }
    else
    {

       for(int i=0 ; i<Height(); i++)
       {
            if(i>=pos._y )
            {
                NettoieHauteur(_matrice.at(i));
            }
       }
       _matrice.resize(pos._y);
    }
    _taille._y=pos._y;



    //largeur
    if(pos._x >=Width())
    {
          for(auto &i : _matrice)
          {
              if (i!=nullptr)  i->resize(pos._x,nullptr);
          }

    }
    else
    {

        for(auto &i : _matrice)
        {
            if(i!=nullptr){
                for(int j=0 ; j<Width() ; j++)
                {
                    if(j>=pos._x)
                        NettoieLargeur(i->at(j));
                }
                i->resize(pos._x);
            }
        }
    }
    _taille._x=pos._x;



    //pronfondeur
    if(pos._z>=Depth())
    {
        for(auto &i : _matrice)
        {
            if (i!=nullptr)
            {
                for(auto &j : *i)
                {
                     if (j!=nullptr)  j->resize(pos._z,nullptr);
                }
            }
        }
    }
    else
    {
        for(auto &i : _matrice)
        {
            if (i!=nullptr)
            {
                for(auto &j : *i)
                {
                    if(j!=nullptr)
                    {
                        for(int k=0 ; k<Depth() ; k++)
                        {
                            if(k>=pos._z)
                                NettoiePronf(j->at(k));
                        }
                        j->resize(pos._z);
                    }
                }
            }
        }


    }
    _taille._z=pos._z;






}

void Matrice3D::SuppressionCube(const Position & pos)
{
    if(pos._y<Height() || pos._x<Width() || pos._z<Depth() )
    {
      NettoiePronf(this->At(pos));
      _matrice.at(pos._y)->at(pos._x)->at(pos._z)=nullptr;

      int i=0;
      while(i<Depth() && this->At(pos)==nullptr)
       {
         i++ ;
       }
      if (i == Depth()){
           NettoieLargeur(_matrice.at(pos._y)->at(pos._x));
           _matrice.at(pos._y)->at(pos._x)=nullptr;
        }
    }
    else
        throw m3DepassementTaille("out of range");
}

void Matrice3D::SuppressionCarre(int hauteur)
{
    if(hauteur<Height() )
    {
        NettoieHauteur(_matrice.at(hauteur));
        _matrice.at(hauteur)=nullptr;
    }
    else
        throw m3DepassementTaille("out of range");
}

void Matrice3D::MoveUp()
{
    NettoieHauteur(_matrice.at(Height()-1));
    _matrice.at(Height()-1)=nullptr;

    for (unsigned int i=Height()-1;i>0;i--) {
        EchangeCarre(i,i-1);
    }
    _matrice.at(0)=nullptr;

}

void Matrice3D::EchangeCarre(int hauteur1, int hauteur2)
{
    auto pt=this->At(hauteur1);

    _matrice.at(hauteur1)=_matrice.at(hauteur2);
    _matrice.at(hauteur2)=pt;
}

bool Matrice3D::CarrePlein(int hauteur) const
{
    if(hauteur >= _taille._y){
            return false;
        }
        else{
            //sinon on va venir parcourir le carré
            for (int i = 0; i < _taille._x; i++)
            {
                for (int j = 0; j < _taille._z; j++)
                {
                    Position p = {i,hauteur,j};
                    if (!this->At(p))
                    {
                        return false;
                    }
                }
            }
            return true;
    }
}

void Matrice3D::RotationY()
{

    Matrice3D M(*this);
    ModifSize(Position{Depth(),Height(),Width()});
    for(int h=0 ; h <M.Height() ; h++)
    {
        NettoieHauteur(At(h));
        _matrice.at(h)=nullptr;

        if(M.At(h))
        {
            for(int w =0 ; w < M.Width() ; w++)
            {
                if(M.At(h)->at(w))
                {

                    for(int d=(M.Depth()-1);d>=0;d--)
                    {
                        if(M.At(h)->at(w)->at(d))
                            Ajout(*M.At(h)->at(w)->at(d),Position{(M.Depth()-1)-d,h,w});

                    }
                }

            }
        }
    }
}

void Matrice3D::RotationMY()
{
    Matrice3D M(*this);
    ModifSize(Position{Depth(),Height(),Width()});
    for(int h=0 ; h <M.Height() ; h++)
    {
        NettoieHauteur(At(h));
        _matrice.at(h)=nullptr;

        if(M.At(h))
        {
            for(int w =0 ; w < M.Width() ; w++)
            {
                if(M.At(h)->at(w))
                {

                    for(int d=(M.Depth()-1);d>=0;d--)
                    {
                        if(M.At(h)->at(w)->at(d))
                            Ajout(*M.At(h)->at(w)->at(d),Position{d,h,(M.Width()-1)-w});

                    }
                }

            }
        }
    }
}

void Matrice3D::RotationX()
{
    Matrice3D M(*this);
   ModifSize(Position{Width(),Depth(),Height()});


    for(auto &i : _matrice){
        NettoieHauteur(i);
        i=nullptr;
    }

    for(int h=0 ; h <M.Height() ; h++)
    {


        if(M.At(h))
        {
            for(int w =0 ; w < M.Width() ; w++)
            {
                if(M.At(h)->at(w))
                {

                    for(int d=0;d<M.Depth();d++)
                    {
                        if(M.At(h)->at(w)->at(d))
                            Ajout(*M.At(h)->at(w)->at(d),Position{w,d,(M.Height()-1)-h});

                    }
                }

            }
        }
    }
}

void Matrice3D::RotationMX()
{
    Matrice3D M(*this);
    ModifSize(Position{Width(),Depth(),Height()});


    for(auto &i : _matrice){
        NettoieHauteur(i);
        i=nullptr;
    }

    for(int h=0 ; h <M.Height() ; h++)
    {


        if(M.At(h))
        {
            for(int w =0 ; w < M.Width() ; w++)
            {
                if(M.At(h)->at(w))
                {

                    for(int d=0;d<M.Depth();d++)
                    {
                        if(M.At(h)->at(w)->at(d))
                            Ajout(*M.At(h)->at(w)->at(d),Position{w,(M.Depth()-1)-d,h});

                    }
                }

            }
        }
    }
}

void Matrice3D::RotationZ()
{
    Matrice3D M(*this);
    ModifSize(Position{Height(),Width(),Depth()});

    for(auto &i : _matrice){
        NettoieHauteur(i);
        i=nullptr;
    }

    for(int h=0 ; h <M.Height() ; h++)
    {


        if(M.At(h))
        {
            for(int w =0 ; w < M.Width() ; w++)
            {
                if(M.At(h)->at(w))
                {

                    for(int d=0;d<M.Depth();d++)
                    {
                        if(M.At(h)->at(w)->at(d))
                            Ajout(*M.At(h)->at(w)->at(d),Position{(M.Height()-1)-h,w,d});

                    }
                }

            }
        }
    }
}

void Matrice3D::RotationMZ()
{
    Matrice3D M(*this);
    ModifSize(Position{Height(),Width(),Depth()});

    for(auto &i : _matrice){
        NettoieHauteur(i);
        i=nullptr;
    }

    for(int h=0 ; h <M.Height() ; h++)
    {


        if(M.At(h))
        {
            for(int w =0 ; w < M.Width() ; w++)
            {
                if(M.At(h)->at(w))
                {

                    for(int d=0;d<M.Depth();d++)
                    {
                        if(M.At(h)->at(w)->at(d))
                            Ajout(*M.At(h)->at(w)->at(d),Position{h,(M.Width()-1)-w,d});

                    }
                }

            }
        }
    }
}

bool Matrice3D::operator==(const Matrice3D &M)
{
    if( _taille._x == M._taille._x && _taille._y == M._taille._y && _taille._z == M._taille._z)
    {
        for (int i=0;i<Height();i++)
            for (int j = 0; j < Width(); ++j)
                for (int k = 0; k <Depth(); ++k) {

                    if(this->At(Position{j,i,k})!=M.At(Position{j,i,k}))
                        return false;
                }



    }
    return  false;
}

void Matrice3D::operator=(const Matrice3D &M)
{
    _taille=M._taille;

    this->ModifSize(_taille);

   for(int h=0 ; h <Height() ; h++)
        {
            NettoieHauteur(this->At(h));
            _matrice.at(h)=nullptr;

            if(M.At(h)!=nullptr)
            {
                for(int i=0;i<Width();i++)

                    if(M.At(h)->at(i)!=nullptr)

                        for(int j=0;j<Depth();j++)
                            if(M.At(Position{i,h,j}))
                                Ajout(*M.At(Position{i,h,j}),Position{i,h,j});
            }
        }
}
