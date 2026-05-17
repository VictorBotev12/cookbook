#pragma once

#include <string>
#include <vector>
#include "Ingredient.h"
#include "Step.h"

class Recipe {
protected:
    std::string name;
    std::vector<Ingredient> ingredients;
    std::vector<Step*> steps;

public:
    Recipe();
    Recipe(std::string name);

    virtual void printInfo();
    virtual double calculateCalories();

    virtual ~Recipe() = default;
};