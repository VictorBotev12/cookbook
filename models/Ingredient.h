#pragma once

#include <string>

class Ingredient {

private:
    std::string name;
    double quantity;
    double caloriesPerUnit;

public:
    Ingredient();

    Ingredient(const std::string& name, double quantity, double caloriesPerUnit);

    std::string getName() const;

    double getQuantity() const;

    double getCaloriesPerUnit() const;

    void setName(const std::string& name);

    void setQuantity(double quantity);

    void setCaloriesPerUnit(double caloriesPerUnit);
};