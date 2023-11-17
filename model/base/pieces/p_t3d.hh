#pragma once

#include "../piece.hh"

class P_T3d: public Piece
{
public:
    static const Position defaultSizeOfT;
    P_T3d(couleur c);
    ~P_T3d() override = default;

    P_T3d & operator=(P_T3d const & p);

    //méthode clone
    std::unique_ptr<Piece> clone() const override;
};
