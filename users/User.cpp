#include "User.h"
#include "../models/Recipe.h"

#include <iostream>

User::User(const std::string& username)
    : username(username) {
}

std::string User::getUsername() const {
    return username;
}

void User::addFavorite(Recipe* recipe) {

    favoriteRecipes.push_back(recipe);
}

void User::showFavorites() const {

    if (favoriteRecipes.empty()) {

        std::cout << "No favorite recipes." << std::endl;
        return;
    }

    std::cout << "Favorite recipes:" << std::endl;

    for (Recipe* recipe : favoriteRecipes) {

        std::cout
            << "- "
            << recipe->getName()
            << std::endl;
    }
}