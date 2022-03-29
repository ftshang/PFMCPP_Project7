#pragma once
#include "Character.h"

struct Paladin : public Character
{
private:
    const std::string name;

public:
    // Constructor
    Paladin(std::string name_, int hp_, int armor_, int attackDamage_ = 10);

    // Virtual Destructor
    virtual ~Paladin() override;

    // Overridden pure virtual function getName
    virtual const std::string& getName() override;

    // Overriden pure virtual function getStats
    virtual std::string getStats() override;
};
