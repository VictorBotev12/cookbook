#pragma once

#include <string>

class User {
protected:
    std::string username;
    std::string password;

public:
    virtual void showPermissions();
    virtual ~User() = default;
};