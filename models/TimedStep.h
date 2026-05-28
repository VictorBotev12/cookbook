#pragma once

#include "Step.h"
#include <string>

class TimedStep : public Step {

private:
    std::string text;
    int minutes;

public:
    TimedStep(const std::string& text, int minutes);

    void execute() const override;
};