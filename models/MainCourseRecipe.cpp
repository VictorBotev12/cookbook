#include "MainCourseRecipe.h"
#include <iostream>

MainCourseRecipe::MainCourseRecipe(std::string name)
    : Recipe(name) {}

void MainCourseRecipe::printInfo() {
    std::cout << "Main Course Recipe: " << name << std::endl;
}