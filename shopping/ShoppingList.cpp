#include "ShoppingList.h"
#include <iostream>

void ShoppingList::showList() const {

    std::cout << "Shopping List:" << std::endl;

    for (const auto& item : items) {
        std::cout << "- " << item.getName()
                  << " : "
                  << item.getQuantity()
                  << std::endl;
    }
}