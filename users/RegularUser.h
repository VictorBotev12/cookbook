#pragma once

#include "User.h"

class RegularUser : public User {
public:
    void showPermissions() override;
};