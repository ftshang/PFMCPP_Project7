#pragma once
#include "Dragon.h"
#include "AttackItem.h"

struct DragonSlayer : public Character
{
    // Constructor
    DragonSlayer(std::string name_, int hp_, int armor_, int attackDamage_ = 4);

    // Virtual Destructor
    ~DragonSlayer() override;

    // Overriden attack member function from the Character class
    void attack(Character& other) override;

    // Overriden pure virtual member function getName
    const std::string& getName() override;

    // Overriden pure virtual member function getStats
    std::string getStats() override;

private:
    const std::string name;
    std::unique_ptr<Item> attackItemPtr = std::make_unique<AttackItem>(); 
};
