#pragma once
#include"../piece.hh"


class P_L : public Piece
{
public:

    P_L(couleur c);
    ~P_L() override = default;

    P_L &operator=(P_L const & p);

    //méthode clone
    std::unique_ptr<Piece> clone() const override;
};
