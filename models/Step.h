#pragma once

class Step {
public:
    virtual void execute() = 0;
    virtual ~Step() = default;
};