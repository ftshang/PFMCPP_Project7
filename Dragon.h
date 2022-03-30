#pragma once

#include "Character.h"

struct Dragon : Character
{
    // Constructor
    Dragon(std::string name_, int hp_, int armor_, int attackDamage_ = 80);

    // Virtual Destructor
    ~Dragon() override;

    // overriden virtual function from Character Class
    void attack(Character& other) override;

    // overriden pure virtual function getName
    const std::string& getName() override;

    // overriden pure virtual function getStats
    std::string getStats() override;

private:
    const std::string name;
};
