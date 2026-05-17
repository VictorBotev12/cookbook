#pragma once

#include "Step.h"

class TimedStep : public Step {
public:
    void execute() override;
};