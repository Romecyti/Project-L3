#pragma once

#include "../piece.hh"

class P_Z: public Piece
{
public:
    static const Position defaultSizeOfZ;
    P_Z(couleur c);
    ~P_Z() override = default;

    P_Z & operator=(P_Z const & p);

    //méthode clone
    std::unique_ptr<Piece> clone() const override;
};
