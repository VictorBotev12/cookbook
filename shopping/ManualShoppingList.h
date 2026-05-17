#pragma once

#include "ShoppingList.h"

class ManualShoppingList : public ShoppingList {
public:
    void generateList() override;
};