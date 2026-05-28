#include "DessertRecipe.h"
#include <iostream>

DessertRecipe::DessertRecipe(const std::string& name)
    : Recipe(name) {
}

void DessertRecipe::printInfo() const {

    std::cout
        << "[Dessert] "
        << name
        << " | Calories: "
        << calculateCalories()
        << " | Rating: "
        << getRating()
        << std::endl;
}

double DessertRecipe::calculateCalories() const {

    double total = 0;

    for (const auto& ing : ingredients) {
        total += ing.getQuantity() * ing.getCaloriesPerUnit();
    }

    return total;
}