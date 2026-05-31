#pragma once

#include <vector>
#include "../models/Recipe.h"
class DayPlan {
private:
    std::vector<Recipe*> recipes;

public:
    void addRecipe(Recipe* recipe);
    void showDay() const;
    double getTotalCalories() const;
};