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

double DayPlan::getTotalCalories() const {

    double total = 0;

    for (Recipe* recipe : recipes) {

        total += recipe->calculateCalories();
    }

    return total;
}