#pragma once
#include "../piece.hh"


class P_Carre: public Piece
{
public:
    static const Position defaultSizeOfCube;
    P_Carre(couleur c);
    ~P_Carre() override = default;

    P_Carre & operator=(P_Carre const & p);

    //méthode clone
    std::unique_ptr<Piece> clone() const override;
};





