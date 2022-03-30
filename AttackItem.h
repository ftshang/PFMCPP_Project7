#include "Utility.h"

struct AttackItem : Item
{
    // Constructor
    AttackItem();

    // Destructor
    ~AttackItem() override;

    // Pure virtual member function
    void use(Character*) override;
};
