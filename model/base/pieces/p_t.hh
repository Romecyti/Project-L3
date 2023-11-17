#pragma once

#include "../piece.hh"

class P_T: public Piece
{
public:
    static const Position defaultSizeOfT;
    P_T(couleur c);
    ~P_T() override = default;

    P_T & operator=(P_T const & p);

    //méthode clone
    std::unique_ptr<Piece> clone() const override;
};
