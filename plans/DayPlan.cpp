#include "DayPlan.h"
#include <iostream>

void DayPlan::addRecipe(Recipe* recipe) {
    recipes.push_back(recipe);
}

void DayPlan::showDay() const {
    for (Recipe* r : recipes) {
        r->printInfo();
        std::cout << std::endl;
    }
}