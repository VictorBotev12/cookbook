#pragma once

#include "Recipe.h"

class DessertRecipe : public Recipe {

public:
    DessertRecipe(const std::string& name);

    void printInfo() const override;

    double calculateCalories() const override;
};