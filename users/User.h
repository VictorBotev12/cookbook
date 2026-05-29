#pragma once

#include <string>
#include <vector>

class Recipe;

class User {

protected:
    std::string username;
    std::vector<Recipe*> favoriteRecipes;

public:
    User(const std::string& username);

    virtual ~User() = default;

    virtual void showPermissions() const = 0;

    virtual std::string getRole() const = 0;

    std::string getUsername() const;

    void addFavorite(Recipe* recipe);

    void showFavorites() const;
};