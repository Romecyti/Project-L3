
#pragma once
#include "../piece.hh"


class P_classique_4: public Piece
{
public:
    static const Position defaultSizeOfCube;
    P_classique_4(couleur c);
    ~P_classique_4() override = default;

    P_classique_4 & operator=(P_classique_4 const & p);

    //méthode clone
    std::unique_ptr<Piece> clone() const override;
};
