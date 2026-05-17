#pragma once

class MealPlan {
public:
    virtual void generatePlan() = 0;
    virtual ~MealPlan() = default;
};