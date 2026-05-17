#pragma once

#include "ShoppingList.h"

class AutoShoppingList : public ShoppingList {

public:
    void generateList(const std::vector<Recipe*>& recipes) override;
};