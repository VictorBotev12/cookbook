#include "Recipe.h"
#include <iostream>

Recipe::Recipe() {
    name = "";
}

Recipe::Recipe(std::string name) {
    this->name = name;
}

std::string Recipe::getName() const {
    return name;
}

void Recipe::setName(std::string name) {
    this->name = name;
}

void Recipe::addIngredient(const Ingredient& ingredient) {
    ingredients.push_back(ingredient);
}

void Recipe::clearIngredients() {
    ingredients.clear();
}

void Recipe::printInfo() {
    std::cout << "Recipe: " << name << std::endl;

    std::cout << "Ingredients:" << std::endl;

    for (const Ingredient& ingredient : ingredients) {
        std::cout
            << "- "
            << ingredient.getName()
            << " : "
            << ingredient.getQuantity()
            << std::endl;
    }
}

double Recipe::calculateCalories() {
    return 0;
}