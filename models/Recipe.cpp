#include "Recipe.h"
#include "StarRating.h"
#include <iostream>

Recipe::Recipe(const std::string& name)
    : name(name) {

    rating = new StarRating();
}

Recipe::~Recipe() {

    for (Step* step : steps) {
        delete step;
    }

    delete rating;
}

void Recipe::setName(const std::string& name) {
    this->name = name;
}

std::string Recipe::getName() const {
    return name;
}

void Recipe::addIngredient(const Ingredient& ingredient) {
    ingredients.push_back(ingredient);
}

void Recipe::clearIngredients() {
    ingredients.clear();
}

const std::vector<Ingredient>& Recipe::getIngredients() const {
    return ingredients;
}

void Recipe::addStep(Step* step) {
    steps.push_back(step);
}

void Recipe::showSteps() const {

    std::cout << "Steps:" << std::endl;

    for (Step* step : steps) {
        step->execute();
    }
}

void Recipe::rate(int stars) {
    rating->addRating(stars);
}

double Recipe::getRating() const {
    return rating->getAverage();
}