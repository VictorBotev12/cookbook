#include "MainCourseRecipe.h"
#include <iostream>

MainCourseRecipe::MainCourseRecipe(const std::string& name)
    : Recipe(name) {
}

void MainCourseRecipe::printInfo() const {

    std::cout
        << "[Main Course] "
        << name
        << std::endl;
}

double MainCourseRecipe::calculateCalories() const {

    return ingredients.size() * 80;
}