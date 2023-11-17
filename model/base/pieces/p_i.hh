#pragma once
#include"../piece.hh"


class P_I : public Piece
{
public:

    P_I(couleur c);
    ~P_I() override = default;

    P_I &operator=(P_I const & p);

    //méthode clone
    std::unique_ptr<Piece> clone() const override;
};
