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
    Recipe(const std::string& name);

    virtual ~Recipe();

    void setName(const std::string& name);

    std::string getName() const;

    void addIngredient(const Ingredient& ingredient);

    void clearIngredients();

    const std::vector<Ingredient>& getIngredients() const;

    void addStep(Step* step);

    void showSteps() const;

    virtual void printInfo() const = 0;

    virtual double calculateCalories() const = 0;
};