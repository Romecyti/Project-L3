#pragma once

#include "../piece.hh"

class P_Z3d: public Piece
{
public:
    static const Position defaultSizeOfZ3d;
    P_Z3d(couleur c);
    ~P_Z3d() override = default;

    P_Z3d & operator=(P_Z3d const & p);

    //méthode clone
    std::unique_ptr<Piece> clone() const override;
};
