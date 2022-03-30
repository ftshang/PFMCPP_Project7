#include "AttackItem.h"

// AttackItem::AttackItem
AttackItem::AttackItem() : Item("attack item", 4)
{
    
}

// AttackItem::~AttackItem
AttackItem::~AttackItem()
{
    
}

// AttackItem::use
void AttackItem::use(Character* character)
{
    useAttackItem(character, this);
}
