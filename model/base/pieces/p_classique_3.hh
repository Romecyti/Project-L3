
#pragma once
#include "../piece.hh"


class P_classique_3: public Piece
{
public:
    static const Position defaultSizeOfCube;
    P_classique_3(couleur c);
    ~P_classique_3() override = default;

    P_classique_3 & operator=(P_classique_3 const & p);

    //méthode clone
    std::unique_ptr<Piece> clone() const override;
};


