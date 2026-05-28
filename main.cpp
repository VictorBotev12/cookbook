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

        cout << "Ingredient name: ";
        getline(cin, ingredientName);

        cout << "Quantity: ";
        cin >> quantity;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        recipe->addIngredient(
            Ingredient(ingredientName, quantity)
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

void showMenu() {

    cout << endl;

    cout << "1. Add Recipe" << endl;
    cout << "2. Show Recipes" << endl;
    cout << "3. Search by Ingredient" << endl;
    cout << "4. Generate Shopping List" << endl;
    cout << "5. Show Shopping List" << endl;
    cout << "6. Add Recipe to Weekly Plan" << endl;
    cout << "7. Show Weekly Plan" << endl;
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

    } while (choice != 0);

    for (Recipe* recipe : recipes) {
        delete recipe;
    }

    return 0;
}