#include "Dwarf.h"
#include "Utility.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Dwarf::Dwarf
Dwarf::Dwarf(std::string name_, int hp_, int armor_, int attackDamage_) : Character(hp_, armor_, attackDamage_), name{name_}
{
    srand(time(NULL));
    // Generates a random number between 1 and 5
    int num1 = rand() % 5 + 1;
    int num2 = rand() % 5 + 1;

    helpfulItems = makeHelpfulItems(num1);
    defensiveItems = makeDefensiveItems(num2);
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
