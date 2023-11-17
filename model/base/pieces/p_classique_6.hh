#pragma once
#include "../piece.hh"


class P_classique_6: public Piece
{
public:
    static const Position defaultSizeOfCube;
    P_classique_6(couleur c);
    ~P_classique_6() override = default;

    P_classique_6 & operator=(P_classique_6 const & p);

    //méthode clone
    std::unique_ptr<Piece> clone() const override;
};
