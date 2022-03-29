#pragma once

#include "Character.h"

struct DefensiveItem : public Item
{
    DefensiveItem() : Item("defensive item", 3) { }
    void use(Character* character) override;
};
