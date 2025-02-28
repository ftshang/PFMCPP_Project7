#include "Dwarf.h"

//Dwarf::Dwarf
Dwarf::Dwarf(std::string name_, int hp_, int armor_, int attackDamage_) : Character(hp_, armor_, attackDamage_), name{name_}
{
    helpfulItems = makeHelpfulItems(6);
    defensiveItems = makeDefensiveItems(2);
}

//Dwarf::~Dwarf
Dwarf::~Dwarf()
{
    
}

//Dwarf::getName
const std::string& Dwarf::getName()
{
    return name;
}

//Dwarf::getStats
std::string Dwarf::getStats()
{
    return getCharacterStats(this);
}
