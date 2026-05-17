#pragma once

#include "ShoppingList.h"

class ManualShoppingList : public ShoppingList {

public:
    void generateList(const std::vector<Recipe*>& recipes) override;
};