#pragma once
#include "../piece.hh"


class P_classique_1: public Piece
{
public:
    static const Position defaultSizeOfCube;
    P_classique_1(couleur c);
    ~P_classique_1() override = default;

    P_classique_1 & operator=(P_classique_1 const & p);

    //méthode clone
    std::unique_ptr<Piece> clone() const override;
};


