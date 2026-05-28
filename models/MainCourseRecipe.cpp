#include "MainCourseRecipe.h"
#include <iostream>

MainCourseRecipe::MainCourseRecipe(const std::string& name)
    : Recipe(name) {
}

void MainCourseRecipe::printInfo() const {

    std::cout
        << "[Main Course] "
        << name
        << " | Calories: "
        << calculateCalories()
        << " | Rating: "
        << getRating()
        << std::endl;
}

double MainCourseRecipe::calculateCalories() const {

    double total = 0;

    for (const auto& ing : ingredients) {
        total += ing.getQuantity() * ing.getCaloriesPerUnit();
    }

    return total;
}