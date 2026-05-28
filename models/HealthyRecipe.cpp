#include "HealthyRecipe.h"
#include <iostream>

HealthyRecipe::HealthyRecipe(const std::string& name)
    : Recipe(name) {
}

void HealthyRecipe::printInfo() const {

    std::cout
        << "[Healthy] "
        << name
        << " | Calories: "
        << calculateCalories()
        << " | Rating: "
        << getRating()
        << std::endl;
}

double HealthyRecipe::calculateCalories() const {

    double total = 0;

    for (const auto& ing : ingredients) {
        total += ing.getQuantity() * ing.getCaloriesPerUnit();
    }

    return total;
}