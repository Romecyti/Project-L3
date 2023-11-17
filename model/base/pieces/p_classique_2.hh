#pragma once
#include "../piece.hh"


class P_classique_2: public Piece
{
public:
    static const Position defaultSizeOfCube;
    P_classique_2(couleur c);
    ~P_classique_2() override = default;

    P_classique_2 & operator=(P_classique_2 const & p);

    //méthode clone
    std::unique_ptr<Piece> clone() const override;
};


