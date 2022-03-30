#include "Paladin.h"

// Paladin::Paladin
Paladin::Paladin(std::string name_, int hp_, int armor_, int attackDamage_) : Character(hp_, armor_, attackDamage_), name{name_}
{
    helpfulItems = makeHelpfulItems(4);
    defensiveItems = makeDefensiveItems(2);
}

// Paladin::~Paladin
Paladin::~Paladin()
{
    
}

// Paladin::getName
const std::string& Paladin::getName()
{
    return name;
}

// Paladin::getStats
std::string Paladin::getStats()
{
    return getCharacterStats(this);
}
