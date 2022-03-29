#include "Utility.h"

struct AttackItem : public Item
{
    // Constructor
    AttackItem();

    // Destructor
    ~AttackItem() override;

    // Pure virtual member function
    void use(Character*) override;
};
