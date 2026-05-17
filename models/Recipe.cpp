#include "Recipe.h"
#include <iostream>

Recipe::Recipe() {}

Recipe::Recipe(std::string name) {
    this->name = name;
}

void Recipe::printInfo() {
    std::cout << "Recipe: " << name << std::endl;
}

double Recipe::calculateCalories() {
    return 0;
}