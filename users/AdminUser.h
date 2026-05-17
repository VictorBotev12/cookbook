#pragma once

#include "User.h"

class AdminUser : public User {
public:
    void showPermissions() override;
};