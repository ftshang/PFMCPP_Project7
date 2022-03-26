#pragma once
#include "Character.h"

struct Dwarf : public Character
{
private:
    const std::string name;

public:
    // Constructor
    Dwarf(std::string name_, int hp_, int armor_, int attackDamage_ = 4);

    // Virtual Destructor
    virtual ~Dwarf() override;

    // Override the pure virtual function named getName
    virtual const std::string& getName() override;

    // Override the pure virtual function named getStats
    virtual std::string getStats() override;
};
