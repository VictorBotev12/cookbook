#pragma once

#include <vector>
#include "../models/Ingredient.h"
#include "../models/Recipe.h"

class ShoppingList {
protected:
    std::vector<Ingredient> items;

public:
    virtual void generateList(const std::vector<Recipe*>& recipes) = 0;

    virtual void showList() const;

    virtual ~ShoppingList() = default;
};