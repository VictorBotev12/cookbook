#pragma once

#include "Recipe.h"

class MainCourseRecipe : public Recipe {

public:
    MainCourseRecipe(const std::string& name);

    void printInfo() const override;

    double calculateCalories() const override;
};