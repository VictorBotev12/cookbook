#pragma once

#include "Step.h"
#include <string>

class TextStep : public Step {

private:
    std::string text;

public:
    TextStep(const std::string& text);

    void execute() const override;
};