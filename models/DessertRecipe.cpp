#include "DessertRecipe.h"
#include <iostream>

DessertRecipe::DessertRecipe(std::string name)
    : Recipe(name) {}

void DessertRecipe::printInfo() {
    std::cout << "Dessert Recipe" << std::endl;
}