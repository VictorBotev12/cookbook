#pragma once

#include "MealPlan.h"
#include "DayPlan.h"
#include <vector>

class WeeklyPlan : public MealPlan {
private:
    std::vector<DayPlan> days;

public:
    WeeklyPlan();

    void addRecipeToDay(int day, Recipe* recipe);
    void showPlan() const;
    void generatePlan() override;
    double getWeeklyCalories() const;
};