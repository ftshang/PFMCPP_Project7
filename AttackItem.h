#include "Utility.h"

struct AttackItem : public Item
{
public:
    // Constructor
    AttackItem();

    // Destructor
    virtual ~AttackItem() override;

    // Pure virtual member function
    virtual void use(Character*) override;
};
