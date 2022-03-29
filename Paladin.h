#pragma once
#include "Character.h"

struct Paladin : public Character
{
    // Constructor
    Paladin(std::string name_, int hp_, int armor_, int attackDamage_ = 10);

    // Virtual Destructor
    ~Paladin() override;

    // Overridden pure virtual function getName
    const std::string& getName() override;

    // Overriden pure virtual function getStats
    std::string getStats() override;

private:
    const std::string name;
};
