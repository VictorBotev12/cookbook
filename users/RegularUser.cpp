#include "RegularUser.h"
#include <iostream>

RegularUser::RegularUser(const std::string& username)
    : User(username) {
}

void RegularUser::showPermissions() const {

    std::cout << "Regular user: limited access" << std::endl;
}

std::string RegularUser::getRole() const {
    return "Regular";
}