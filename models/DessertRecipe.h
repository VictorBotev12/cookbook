#pragma once

#include "Recipe.h"

class DessertRecipe : public Recipe {
public:
    DessertRecipe(std::string name);

    void printInfo() override;
};