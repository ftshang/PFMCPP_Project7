#include "Character.h"
#include "DefensiveItem.h"
#include "HelpfulItem.h"

// Free function to update values after killing another character
void updateValues(int& currentStats, int& initialValue);

// 1. Constructor
Character::Character(int hp, int armor_, int attackDamage_ ) :
    hitPoints(hp),
    armor(armor_),
    attackDamage(attackDamage_)
{
    initialHitPoints.reset( new int(hitPoints) );
    initialArmorLevel.reset( new int( armor) );
    initialAttackDamage.reset( new int( attackDamage) );
}

// 2. attack member function
void Character::attack( Character& other )
{
    if( hitPoints <= 0 )
    {
        std::cout << getName() << " can't attack. " << getName() << " is dead." << std::endl;
        std::cout << "make another party member use an item to revive them" << std::endl << std::endl;
        return;
    }
        
    isDefending = false;
    std::cout << getName() << " has attacked " << other.getName() << std::endl;
    
    if( other.takeDamage(attackDamage) <= 0 ) 
    {
        //if you kill other, you get a boost in hit points and armor.
        attackInternal(other);
    }
}

// 3. defend member function
void Character::defend()
{
    std::cout << getName() << " is defending!!" << std::endl;
    for( auto& item : defensiveItems )
    {
        if( auto* defensiveItem = dynamic_cast<DefensiveItem*>(item.get()) )
        {
            defensiveItem->use(this);
            item.reset(); //can only be used once!
            break;
        }
    }
    isDefending = true;
}

// 4. help member function
void Character::help(Character& other)
{
    std::cout << getName() << " is going to help " << other.getName() << std::endl;
    for( auto& item : helpfulItems )
    {
        if( auto* helpfulItem = dynamic_cast<HelpfulItem*>(item.get()) )
        {
            helpfulItem->use(&other);
            item.reset(); //can only be used once!
            break;
        }
    }
}

// 5. takeDamage member function
int Character::takeDamage(int damage)
{
    std::cout << getName() << " is taking " << damage << " damage!" << std::endl;
    if( damage < armor )
    {
        armor -= damage;
    }
    else
    {
        damage -= armor;
        armor = 0;
        
        hitPoints -= damage;
        if( hitPoints < 0 )
        {
            std::cout << getName() << " has died in battle!" << std::endl;
            hitPoints = 0;
        }
    }
    printStats();
    return hitPoints;
}

// 6. attackInternal member function
void Character::attackInternal(Character& other)
{
    if( other.hitPoints <= 0 )
    {
        /*
        When you defeat another Character: 
            a) your stats are restored to their initial value if they are lower than it.
            b) your stats are boosted 10%
            c) the initial value of your stats is updated to reflect this boosted stat for the next time you defeat another character.
      */
        updateValues(hitPoints, *initialHitPoints);
        updateValues(armor, *initialArmorLevel);
        updateValues(attackDamage, *initialAttackDamage);

        std::cout << getName() << " defeated " << other.getName() << " and leveled up!" << std::endl;        
    }
}

// 7. printStats member function
void Character::printStats()
{
    std::cout << getName() << "'s stats: " << std::endl;
    /*
    make your getStats() use a function from the Utility.h
    */
    std::cout << getStats(); 
    
    std::cout << std::endl;
    std::cout << std::endl;
}

void updateValues(int& currentStats, int& initialValue)
{
    if (currentStats < initialValue)
    {
        currentStats = initialValue;
    }
    currentStats = currentStats * 1.10;
    initialValue = currentStats;
}
