#include "Ingredient.h"

Ingredient::Ingredient() {
    name = "";
    quantity = 0;
}

Ingredient::Ingredient(std::string name, double quantity) {
    this->name = name;
    this->quantity = quantity;
}

std::string Ingredient::getName() const {
    return name;
}

double Ingredient::getQuantity() const {
    return quantity;
}

void Ingredient::setName(std::string name) {
    this->name = name;
}

void Ingredient::setQuantity(double quantity) {
    this->quantity = quantity;
}