#include <algorithm>
#include <iostream>
#include <vector>
#include <limits>

#include "models/Recipe.h"
#include "models/DessertRecipe.h"
#include "models/HealthyRecipe.h"
#include "models/MainCourseRecipe.h"

#include "models/TextStep.h"
#include "models/TimedStep.h"

#include "plans/WeeklyPlan.h"

#include "shopping/AutoShoppingList.h"

#include "users/AdminUser.h"
#include "users/RegularUser.h"

using namespace std;

WeeklyPlan weeklyPlan;
AutoShoppingList shoppingList;

void showRecipes(const vector<Recipe*>& recipes) {

    if (recipes.empty()) {
        cout << "No recipes available." << endl;
        return;
    }

    for (int i = 0; i < recipes.size(); i++) {

        cout << i + 1 << ". ";

        recipes[i]->printInfo();

        recipes[i]->showSteps();

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

    string name;

    cout << "Recipe name: ";
    getline(cin, name);

    Recipe* recipe;

    if (type == 1) {
        recipe = new DessertRecipe(name);
    }
    else if (type == 2) {
        recipe = new HealthyRecipe(name);
    }
    else {
        recipe = new MainCourseRecipe(name);
    }

    int ingredientCount;

    cout << "How many ingredients: ";
    cin >> ingredientCount;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < ingredientCount; i++) {

        string ingredientName;
        double quantity;
        double calories;

        cout << "Ingredient name: ";
        getline(cin, ingredientName);

        cout << "Quantity: ";
        cin >> quantity;

        cout << "Calories per unit: ";
        cin >> calories;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        recipe->addIngredient(
            Ingredient(ingredientName, quantity, calories)
        );
    }

    int stepCount;

    cout << "How many steps: ";
    cin >> stepCount;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < stepCount; i++) {

        int stepType;

        cout << "1. Text Step" << endl;
        cout << "2. Timed Step" << endl;

        cin >> stepType;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string text;

        cout << "Step text: ";
        getline(cin, text);

        if (stepType == 1) {

            recipe->addStep(
                new TextStep(text)
            );
        }
        else {

            int minutes;

            cout << "Minutes: ";
            cin >> minutes;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            recipe->addStep(
                new TimedStep(text, minutes)
            );
        }
    }

    return recipe;
}

void searchRecipes(const vector<Recipe*>& recipes) {

    string ingredient;

    cout << "Enter ingredient name: ";
    getline(cin, ingredient);

    bool found = false;

    for (Recipe* recipe : recipes) {

        for (const Ingredient& ing : recipe->getIngredients()) {

            if (ing.getName() == ingredient) {

                recipe->printInfo();
                recipe->showSteps();

                cout << endl;

                found = true;
            }
        }
    }

    if (!found) {
        cout << "No recipes found." << endl;
    }
}

void sortRecipesByName(vector<Recipe*>& recipes) {

    sort(
        recipes.begin(),
        recipes.end(),
        [](Recipe* a, Recipe* b) {
            return a->getName() < b->getName();
        }
    );

    cout << "Recipes sorted by name." << endl;
}

void sortRecipesByRating(vector<Recipe*>& recipes) {

    sort(
        recipes.begin(),
        recipes.end(),
        [](Recipe* a, Recipe* b) {
            return a->getRating() > b->getRating();
        }
    );

    cout << "Recipes sorted by rating." << endl;
}

void sortRecipesByCalories(vector<Recipe*>& recipes) {

    sort(
        recipes.begin(),
        recipes.end(),
        [](Recipe* a, Recipe* b) {
            return a->calculateCalories() >
                   b->calculateCalories();
        }
    );

    cout << "Recipes sorted by calories." << endl;
}

void showMenu() {

    cout << endl;

    cout << "1. Add Recipe" << endl;
    cout << "2. Show Recipes" << endl;
    cout << "3. Search by Ingredient" << endl;
    cout << "4. Generate Shopping List" << endl;
    cout << "5. Show Shopping List" << endl;
    cout << "6. Add Recipe to Weekly Plan" << endl;
    cout << "7. Show Weekly Plan" << endl;
    cout << "8. Rate Recipe" << endl;
    cout << "9. Sort Recipes By Name" << endl;
    cout << "10. Sort Recipes By Rating" << endl;
    cout << "11. Sort Recipes By Calories" << endl;
    cout << "12. Add Favorite Recipe" << endl;
    cout << "13. Show Favorite Recipes" << endl;
    cout << "14. Remove Favorite Recipe" << endl;
    cout << "0. Exit" << endl;
}

int main() {

    AdminUser admin("admin");
    RegularUser user("user");

    admin.showPermissions();
    user.showPermissions();

    vector<Recipe*> recipes;

    int choice;

    do {

        showMenu();

        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 1) {

            recipes.push_back(createRecipe());

            cout << "Recipe added." << endl;
        }
        else if (choice == 2) {

            showRecipes(recipes);
        }
        else if (choice == 3) {

            searchRecipes(recipes);
        }
        else if (choice == 4) {

            shoppingList.generateList(recipes);

            cout << "Shopping list generated." << endl;
        }
        else if (choice == 5) {

            shoppingList.showList();
        }
        else if (choice == 6) {

            if (recipes.empty()) {

                cout << "No recipes available." << endl;
            }
            else {

                showRecipes(recipes);

                int recipeIndex;
                int day;

                cout << "Choose recipe number: ";
                cin >> recipeIndex;

                cout << "Choose day (1-7): ";
                cin >> day;

                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if (recipeIndex >= 1 &&
                    recipeIndex <= recipes.size() &&
                    day >= 1 &&
                    day <= 7) {

                    weeklyPlan.addRecipeToDay(
                        day - 1,
                        recipes[recipeIndex - 1]
                    );

                    cout << "Recipe added to weekly plan." << endl;
                }
                else {

                    cout << "Invalid input." << endl;
                }
            }
        }
        else if (choice == 7) {

            weeklyPlan.showPlan();
        }
        else if (choice == 8) {

            if (recipes.empty()) {
                cout << "No recipes available." << endl;
            }
            else {

                showRecipes(recipes);

                int index;
                int stars;

                cout << "Choose recipe number: ";
                cin >> index;

                cout << "Stars (1-5): ";
                cin >> stars;

                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if (index >= 1 &&
                    index <= recipes.size()) {

                    recipes[index - 1]->rate(stars);

                    cout << "Recipe rated." << endl;
                }
                else {
                    cout << "Invalid input." << endl;
                }
            }
        }
        else if (choice == 9) {

            sortRecipesByName(recipes);
        }
        else if (choice == 10) {

            sortRecipesByRating(recipes);
        }
        else if (choice == 11) {

            sortRecipesByCalories(recipes);
        }
        else if (choice == 12) {

            if (recipes.empty()) {

                cout << "No recipes available." << endl;
            }
            else {

                showRecipes(recipes);

                int index;

                cout << "Choose recipe number: ";
                cin >> index;

                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if (index >= 1 &&
                    index <= recipes.size()) {

                    user.addFavorite(
                        recipes[index - 1]
                    );

                    cout
                        << "Recipe added to favorites."
                        << endl;
                }
                else {

                    cout << "Invalid input." << endl;
                }
            }
        }
        else if (choice == 13) {

            user.showFavorites();
        }
        else if (choice == 14) {

            user.showFavorites();

            int index;

            cout << "Favorite number to remove: ";

            cin >> index;

            cin.ignore(
                numeric_limits<streamsize>::max(),
                '\n'
            );

            user.removeFavorite(index - 1);
        }
                

    } while (choice != 0);

    for (Recipe* recipe : recipes) {
        delete recipe;
    }

    return 0;
}