#pragma once

#include <string>

class Ingredient {
private:
    std::string name;
    double quantity;

public:
    Ingredient();
    Ingredient(std::string name, double quantity);

    std::string getName() const;
    double getQuantity() const;

    void setName(std::string name);
    void setQuantity(double quantity);
};