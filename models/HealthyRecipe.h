#pragma once

#include "Recipe.h"

class HealthyRecipe : public Recipe {
public:
    HealthyRecipe(std::string name);

    void printInfo() override;
};