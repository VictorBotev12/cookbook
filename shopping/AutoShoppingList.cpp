#include "AutoShoppingList.h"

void AutoShoppingList::generateList(const std::vector<Recipe*>& recipes) {

    items.clear();

    for (Recipe* r : recipes) {

        for (const Ingredient& ing : r->getIngredients()) {

            bool found = false;

            for (Ingredient& existing : items) {
                if (existing.getName() == ing.getName()) {
                    existing.setQuantity(existing.getQuantity() + ing.getQuantity());
                    found = true;
                    break;
                }
            }

            if (!found) {
                items.push_back(ing);
            }
        }
    }
}