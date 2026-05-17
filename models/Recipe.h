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

    std::string getName() const;

    void setName(std::string name);

    void addIngredient(const Ingredient& ingredient);

    void clearIngredients();

    virtual void printInfo();
    virtual double calculateCalories();

    virtual ~Recipe() = default;
};