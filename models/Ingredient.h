#pragma once

#include <string>

class Ingredient {
private:
    std::string name;
    double quantity;

public:
    Ingredient();
    Ingredient(std::string name, double quantity);
};