#include "Ingredient.h"

Ingredient::Ingredient() {
    name = "";
    quantity = 0;
    caloriesPerUnit = 0;
}

Ingredient::Ingredient(const std::string& name, double quantity, double caloriesPerUnit) {
    this->name = name;
    this->quantity = quantity;
    this->caloriesPerUnit = caloriesPerUnit;
}

std::string Ingredient::getName() const {
    return name;
}

double Ingredient::getQuantity() const {
    return quantity;
}

double Ingredient::getCaloriesPerUnit() const {
    return caloriesPerUnit;
}

void Ingredient::setName(const std::string& name) {
    this->name = name;
}

void Ingredient::setQuantity(double quantity) {
    this->quantity = quantity;
}

void Ingredient::setCaloriesPerUnit(double caloriesPerUnit) {
    this->caloriesPerUnit = caloriesPerUnit;
}