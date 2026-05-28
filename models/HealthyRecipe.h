#pragma once

#include "Recipe.h"

class HealthyRecipe : public Recipe {

public:
    HealthyRecipe(const std::string& name);

    void printInfo() const override;

    double calculateCalories() const override;
};