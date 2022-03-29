#pragma once
#include "Dragon.h"
#include "AttackItem.h"

struct DragonSlayer : public Character
{
public:
    // Constructor
    DragonSlayer(std::string name_, int hp_, int armor_, int attackDamage_ = 4);

    // Virtual Destructor
    virtual ~DragonSlayer() override;

    // Overriden attack member function from the Character class
    virtual void attack(Character& other) override;

    // Overriden pure virtual member function getName
    virtual const std::string& getName() override;

    // Overriden pure virtual member function getStats
    virtual std::string getStats() override;

protected:
    std::unique_ptr<Item> attackItemPtr;

private:
    const std::string name;
};
