#include "AdminUser.h"
#include <iostream>

AdminUser::AdminUser(const std::string& username)
    : User(username) {
}

void AdminUser::showPermissions() const {

    std::cout << "Admin permissions: full access" << std::endl;
}

std::string AdminUser::getRole() const {
    return "Admin";
}