#pragma once

#include "User.h"

class RegularUser : public User {

public:
    RegularUser(const std::string& username);

    void showPermissions() const override;

    std::string getRole() const override;
};