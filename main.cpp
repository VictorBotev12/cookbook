#include <iostream>
#include <vector>
#include <limits>

#include "models/Recipe.h"
#include "models/DessertRecipe.h"
#include "models/HealthyRecipe.h"
#include "models/MainCourseRecipe.h"
#include "models/Ingredient.h"

using namespace std;

void searchRecipes(const vector<Recipe*>& recipes) {

    if (recipes.empty()) {
        cout << "No recipes available." << endl;
        return;
    }

    string keyword;
    cout << "Enter keyword: ";
    getline(cin, keyword);

    bool found = false;

    for (Recipe* recipe : recipes) {
        if (recipe->getName().find(keyword) != string::npos) {
            recipe->printInfo();
            cout << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No matching recipes found." << endl;
    }
}

void filterByType(const vector<Recipe*>& recipes) {

    cout << "Choose type:" << endl;
    cout << "1. Dessert" << endl;
    cout << "2. Healthy" << endl;
    cout << "3. Main Course" << endl;

    int type;
    cin >> type;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (Recipe* recipe : recipes) {

        if (type == 1 && dynamic_cast<DessertRecipe*>(recipe)) {
            recipe->printInfo();
            cout << endl;
        }
        else if (type == 2 && dynamic_cast<HealthyRecipe*>(recipe)) {
            recipe->printInfo();
            cout << endl;
        }
        else if (type == 3 && dynamic_cast<MainCourseRecipe*>(recipe)) {
            recipe->printInfo();
            cout << endl;
        }
    }
}

void showMenu() {
    cout << endl;
    cout << "1. Add Recipe" << endl;
    cout << "2. Show Recipes" << endl;
    cout << "3. Update Recipe" << endl;
    cout << "4. Delete Recipe" << endl;
    cout << "5. Search Recipe" << endl;
    cout << "6. Filter by Type" << endl;
    cout << "0. Exit" << endl;
}

void showRecipes(const vector<Recipe*>& recipes) {

    if (recipes.empty()) {
        cout << "No recipes available." << endl;
        return;
    }

    for (int i = 0; i < recipes.size(); i++) {
        cout << i + 1 << ". ";
        recipes[i]->printInfo();
        cout << endl;
    }
}

Recipe* createRecipe() {

    int type;

    cout << "Choose recipe type:" << endl;
    cout << "1. Dessert" << endl;
    cout << "2. Healthy" << endl;
    cout << "3. Main Course" << endl;

    cin >> type;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string recipeName;

    cout << "Recipe name: ";
    getline(cin, recipeName);

    Recipe* recipe = nullptr;

    if (type == 1) {
        recipe = new DessertRecipe(recipeName);
    }
    else if (type == 2) {
        recipe = new HealthyRecipe(recipeName);
    }
    else {
        recipe = new MainCourseRecipe(recipeName);
    }

    int ingredientCount;

    cout << "How many ingredients: ";
    cin >> ingredientCount;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < ingredientCount; i++) {

        string ingredientName;
        double quantity;

        cout << "Ingredient name: ";
        getline(cin, ingredientName);

        cout << "Quantity: ";
        cin >> quantity;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        Ingredient ingredient(ingredientName, quantity);
        recipe->addIngredient(ingredient);
    }

    return recipe;
}

void updateRecipe(vector<Recipe*>& recipes) {

    if (recipes.empty()) {
        cout << "No recipes available." << endl;
        return;
    }

    showRecipes(recipes);

    int index;

    cout << "Choose recipe number to update: ";
    cin >> index;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (index < 1 || index > recipes.size()) {
        cout << "Invalid recipe number." << endl;
        return;
    }

    Recipe* recipe = recipes[index - 1];

    string newName;

    cout << "New recipe name: ";
    getline(cin, newName);

    recipe->setName(newName);
    recipe->clearIngredients();

    int ingredientCount;

    cout << "How many ingredients: ";
    cin >> ingredientCount;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < ingredientCount; i++) {

        string ingredientName;
        double quantity;

        cout << "Ingredient name: ";
        getline(cin, ingredientName);

        cout << "Quantity: ";
        cin >> quantity;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        Ingredient ingredient(ingredientName, quantity);
        recipe->addIngredient(ingredient);
    }

    cout << "Recipe updated successfully." << endl;
}

void deleteRecipe(vector<Recipe*>& recipes) {

    if (recipes.empty()) {
        cout << "No recipes available." << endl;
        return;
    }

    showRecipes(recipes);

    int index;

    cout << "Choose recipe number to delete: ";
    cin >> index;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (index < 1 || index > recipes.size()) {
        cout << "Invalid recipe number." << endl;
        return;
    }

    delete recipes[index - 1];
    recipes.erase(recipes.begin() + (index - 1));

    cout << "Recipe deleted successfully." << endl;
}

int main() {

    vector<Recipe*> recipes;

    int choice;

    do {

        showMenu();

        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 1) {

            Recipe* recipe = createRecipe();
            recipes.push_back(recipe);

            cout << "Recipe added successfully." << endl;
        }
        else if (choice == 2) {
            showRecipes(recipes);
        }
        else if (choice == 3) {
            updateRecipe(recipes);
        }
        else if (choice == 4) {
            deleteRecipe(recipes);
        }
        else if (choice == 5) {
            searchRecipes(recipes);
        }
        else if (choice == 6) {
            filterByType(recipes);
        }

    } while (choice != 0);

    for (Recipe* recipe : recipes) {
        delete recipe;
    }

    return 0;
}