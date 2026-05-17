#include "Ingredient.h"

Ingredient::Ingredient() {}

Ingredient::Ingredient(std::string name, double quantity) {
    this->name = name;
    this->quantity = quantity;
}