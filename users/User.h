#pragma once

#include <string>

class User {

protected:
    std::string username;

public:
    User(const std::string& username);

    virtual void showPermissions() const = 0;

    virtual std::string getRole() const = 0;

    virtual ~User() = default;
};