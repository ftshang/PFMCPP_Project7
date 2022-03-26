#pragma once

#include <string>
#include <vector>
#include <memory>
#include <iostream>

#include "Item.h"

struct Character
{
    // 1. Constructor
    Character(int hp, int armor_, int attackDamage_ );

    // Virtual Destructor
    virtual ~Character() { }
    
    /*
     a pure virtual getName function.
     derived class stores the name, not the base class.
     */
    
    virtual const std::string& getName() = 0;
    virtual std::string getStats() = 0;

    // 2. attack member function
    virtual void attack( Character& other );
    // 3. defend member function
    void defend();
    // 4. help member function
    void help( Character& other );
    // 5. takeDamage member function
    int takeDamage(int damage);
    
    inline int getHP() const { return hitPoints; }
    inline int getArmorLevel() const { return armor; }
    inline int getAttackDamage() const { return attackDamage; }
    inline bool getIsDefending() const { return isDefending; }
    
    inline const std::vector<std::unique_ptr<Item>>& getHelpfulItems() const { return helpfulItems; }
    inline const std::vector<std::unique_ptr<Item>>& getDefensiveItems() const { return defensiveItems; }
    
    inline void boostArmor( int amount )
    {
        armor += amount;
        std::cout << getName() << "'s armor level has been boosted to " << armor << std::endl;
    }
    
    inline void boostHitPoints( int amount )
    {
        hitPoints += amount;
        std::cout << getName() << "'s hit point level has been boosted to " << hitPoints << std::endl;
    }
    
    inline void boostAttackDamage( int amount )
    {
        attackDamage += amount;
        std::cout << getName() << "'s attack damage level has been boosted to " << attackDamage << std::endl;
    }

    // 7. printStats member function
    void printStats();

protected:
    // protected member variables
    std::vector<std::unique_ptr<Item>> defensiveItems;
    std::vector<std::unique_ptr<Item>> helpfulItems;
    int hitPoints, armor;
    int attackDamage;
    bool isDefending = false;
private:
    // private member variables
    std::unique_ptr<int> initialHitPoints, initialArmorLevel, initialAttackDamage;

    // 6. attackInternal member function
    void attackInternal(Character& other);
};