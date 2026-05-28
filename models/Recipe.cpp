#include "Recipe.h"
#include <iostream>

Recipe::Recipe(const std::string& name)
    : name(name) {
}

Recipe::~Recipe() {

    for (Step* step : steps) {
        delete step;
    }
}

void Recipe::setName(const std::string& name) {
    this->name = name;
}

std::string Recipe::getName() const {
    return name;
}

void Recipe::addIngredient(const Ingredient& ingredient) {
    ingredients.push_back(ingredient);
}

void Recipe::clearIngredients() {
    ingredients.clear();
}

const std::vector<Ingredient>& Recipe::getIngredients() const {
    return ingredients;
}

void Recipe::addStep(Step* step) {
    steps.push_back(step);
}

void Recipe::showSteps() const {

    std::cout << "Steps:" << std::endl;

    for (Step* step : steps) {
        step->execute();
    }
}