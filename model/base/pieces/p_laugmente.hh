#pragma once
#include"../piece.hh"


class P_LAugmente : public Piece
{
public:

    P_LAugmente (couleur c);
    ~P_LAugmente () override = default;

    P_LAugmente  &operator=(P_LAugmente  const & p);

    //méthode clone
    std::unique_ptr<Piece> clone() const override;
};
