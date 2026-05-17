#pragma once

#include "Recipe.h"

class MainCourseRecipe : public Recipe {
public:
    MainCourseRecipe(std::string name);

    void printInfo() override;
};