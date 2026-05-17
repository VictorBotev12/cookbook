#include "HealthyRecipe.h"
#include <iostream>

HealthyRecipe::HealthyRecipe(std::string name)
    : Recipe(name) {}

void HealthyRecipe::printInfo() {
    std::cout << "Healthy Recipe: " << name << std::endl;
}