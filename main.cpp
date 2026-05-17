#include <iostream>
#include <vector>
#include <limits>

#include "models/Recipe.h"
#include "models/DessertRecipe.h"
#include "models/HealthyRecipe.h"
#include "models/MainCourseRecipe.h"
#include "models/Ingredient.h"

#include "plans/WeeklyPlan.h"
#include "shopping/AutoShoppingList.h"

using namespace std;

WeeklyPlan weeklyPlan;
AutoShoppingList shoppingList;

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
    cout << "7. Add Recipe to Weekly Plan" << endl;
    cout << "8. Show Weekly Plan" << endl;
    cout << "9. Generate Shopping List" << endl;
    cout << "10. Show Shopping List" << endl;
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

    string name;

    cout << "Recipe name: ";
    getline(cin, name);

    Recipe* recipe;

    if (type == 1) recipe = new DessertRecipe(name);
    else if (type == 2) recipe = new HealthyRecipe(name);
    else recipe = new MainCourseRecipe(name);

    int count;

    cout << "How many ingredients: ";
    cin >> count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < count; i++) {

        string ingName;
        double qty;

        cout << "Ingredient name: ";
        getline(cin, ingName);

        cout << "Quantity: ";
        cin >> qty;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        recipe->addIngredient(Ingredient(ingName, qty));
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
        cout << "Invalid index." << endl;
        return;
    }

    Recipe* recipe = recipes[index - 1];

    string newName;
    cout << "New name: ";
    getline(cin, newName);

    recipe->setName(newName);
    recipe->clearIngredients();

    int count;

    cout << "How many ingredients: ";
    cin >> count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < count; i++) {

        string ingName;
        double qty;

        cout << "Ingredient name: ";
        getline(cin, ingName);

        cout << "Quantity: ";
        cin >> qty;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        recipe->addIngredient(Ingredient(ingName, qty));
    }

    cout << "Updated successfully." << endl;
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
        cout << "Invalid index." << endl;
        return;
    }

    delete recipes[index - 1];
    recipes.erase(recipes.begin() + index - 1);

    cout << "Deleted successfully." << endl;
}

int main() {

    vector<Recipe*> recipes;

    int choice;

    do {

        showMenu();

        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 1) {
            recipes.push_back(createRecipe());
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
        else if (choice == 7) {

            showRecipes(recipes);

            int index, day;

            cout << "Choose recipe: ";
            cin >> index;

            cout << "Choose day (1-7): ";
            cin >> day;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (index >= 1 && index <= recipes.size()) {
                weeklyPlan.addRecipeToDay(day - 1, recipes[index - 1]);
            }
        }
        else if (choice == 8) {
            weeklyPlan.showPlan();
        }
        else if (choice == 9) {
            shoppingList.generateList(recipes);
            cout << "Shopping list generated." << endl;
        }
        else if (choice == 10) {
            shoppingList.showList();
        }

    } while (choice != 0);

    for (Recipe* r : recipes) {
        delete r;
    }

    return 0;
}