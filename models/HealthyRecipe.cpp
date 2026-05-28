#include "HealthyRecipe.h"
#include <iostream>

HealthyRecipe::HealthyRecipe(const std::string& name)
    : Recipe(name) {
}

void HealthyRecipe::printInfo() const {

    std::cout
        << "[Healthy] "
        << name
        << " | Rating: "
        << getRating()
        << std::endl;
}

double HealthyRecipe::calculateCalories() const {

    return ingredients.size() * 50;
}