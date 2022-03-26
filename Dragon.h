#pragma once

#include "Character.h"

struct Dragon : public Character
{
public:

    // Constructor
    Dragon(std::string name_, int hp_, int armor_, int attackDamage_ = 80);

    // Virtual Destructor
    virtual ~Dragon() override;

    // overriden virtual function from Character Class
    virtual void attack(Character& other) override;

    // overriden pure virtual function getName
    virtual const std::string& getName() override;

    // overriden pure virtual function getStats
    virtual std::string getStats() override;

private:
    const std::string name;
};
