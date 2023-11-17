#pragma once
#include "../piece.hh"


class P_classique_5: public Piece
{
public:
    static const Position defaultSizeOfCube;
    P_classique_5(couleur c);
    ~P_classique_5() override = default;

    P_classique_5 & operator=(P_classique_5 const & p);

    //méthode clone
    std::unique_ptr<Piece> clone() const override;
};
