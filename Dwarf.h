#pragma once
#include "Character.h"

struct Dwarf : public Character
{
    // Constructor
    Dwarf(std::string name_, int hp_, int armor_, int attackDamage_ = 4);

    // Virtual Destructor
    ~Dwarf() override;

    // Override the pure virtual function named getName
    const std::string& getName() override;

    // Override the pure virtual function named getStats
    std::string getStats() override;

private:
    const std::string name;
};
