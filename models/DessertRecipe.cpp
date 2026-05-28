#include "DessertRecipe.h"
#include <iostream>

DessertRecipe::DessertRecipe(const std::string& name)
    : Recipe(name) {
}

void DessertRecipe::printInfo() const {

    std::cout
        << "[Dessert] "
        << name
        << " | Rating: "
        << getRating()
        << std::endl;
}

double DessertRecipe::calculateCalories() const {

    return ingredients.size() * 100;
}