#pragma once
#include "../piece.hh"



class P_Cube : public Piece
{
public:
    static const Position defaultSizeOfCube;
    P_Cube(couleur c);
    ~P_Cube() override = default;

    P_Cube & operator=(P_Cube const & p);

    //méthode clone
    std::unique_ptr<Piece> clone() const override;

    virtual void Rotation(DIRECTION_ROT d)override;
};
