#include "WeeklyPlan.h"
#include <iostream>

WeeklyPlan::WeeklyPlan() {
    days.resize(7);
}

void WeeklyPlan::addRecipeToDay(int day, Recipe* recipe) {
    if (day >= 0 && day < 7) {
        days[day].addRecipe(recipe);
    }
}

void WeeklyPlan::showPlan() const {
    for (int i = 0; i < 7; i++) {
        std::cout << "Day " << i + 1 << std::endl;
        days[i].showDay();
        std::cout << std::endl;
    }
}

void WeeklyPlan::generatePlan() {
    std::cout << "Weekly plan generated" << std::endl;
}