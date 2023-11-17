#pragma once
#include "../piece.hh"


class P_classique_7: public Piece
{
public:
    static const Position defaultSizeOfCube;
    P_classique_7(couleur c);
    ~P_classique_7() override = default;

    P_classique_7 & operator=(P_classique_7 const & p);

    //méthode clone
    std::unique_ptr<Piece> clone() const override;
};
