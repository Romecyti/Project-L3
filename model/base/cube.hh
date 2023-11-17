#pragma once

enum class couleur {vert,bleu,rouge,jaune,rose,orange,marron,cyan,violet,sapin,bordeaux,gris,blanc};

class Cube
{
private:
    couleur _couleur;
public:
    Cube(couleur coul);

    couleur GetCouleur() const;
    void SetCouleur(couleur c);
};

