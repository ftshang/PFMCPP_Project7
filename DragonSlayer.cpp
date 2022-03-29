#include "DragonSlayer.h"
#include "Dragon.h"
#include "Utility.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//DragonSlayer::DragonSlayer
DragonSlayer::DragonSlayer(std::string name_, int hp_, int armor_, int attackDamage_) : Character(hp_, armor_, attackDamage_), name{name_}
{
    // srand(time(NULL));
    // int num1 = rand() % 10
}

//DragonSlayer::~DragonSlayer
DragonSlayer::~DragonSlayer()
{
    
}

//DragonSlayer::getName
const std::string& DragonSlayer::getName()
{
    return name;
}


#include <cassert>
void DragonSlayer::attack(Character& other)
{
    std::cout << name << " is attacking " << other.getName() << " !!" << std::endl;
    if( auto* dragon = dynamic_cast<Dragon*>(&other) )
    {
        assert(false);
        //DragonSlayers get a 10x boost when attacking dragons, from their attack item.
        //so they should USE their attack item before attacking the dragon... 
        //note: they should only use the item if the dragon's hitpoints are > 0...
        //note: items are single-use only, so you need to reset it after use.  
        //look in the Character class for how the other item types are reset after use.
        while( dragon->getHP() > 0 )
        {
            dragon->takeDamage(attackDamage);
        }
    }
        
    Character::attack(other);
        
}

//DragonSlayer::getStats
std::string DragonSlayer::getStats()
{
    return getCharacterStats(this);
}
