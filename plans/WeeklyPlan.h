#pragma once

#include "MealPlan.h"

class WeeklyPlan : public MealPlan {
public:
    void generatePlan() override;
};