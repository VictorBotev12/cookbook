#pragma once

#include "User.h"

class AdminUser : public User {

public:
    AdminUser(const std::string& username);

    void showPermissions() const override;

    std::string getRole() const override;
};