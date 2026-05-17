#pragma once

class ShoppingList {
public:
    virtual void generateList() = 0;
    virtual ~ShoppingList() = default;
};