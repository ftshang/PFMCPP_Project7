#pragma once

#include "Dwarf.h"
#include "Paladin.h"
#include "DragonSlayer.h"
#include "Dragon.h"

struct HelpfulItem : public Item
{
    HelpfulItem() : Item("helpful item", 2) { }
    void use(Character* character) override;
};
