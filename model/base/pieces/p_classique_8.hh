#pragma once
#include "../piece.hh"


class P_classique_8: public Piece
{
public:
    static const Position defaultSizeOfCube;
    P_classique_8(couleur c);
    ~P_classique_8() override = default;

    P_classique_8 & operator=(P_classique_8 const & p);

    //méthode clone
    std::unique_ptr<Piece> clone() const override;
};
