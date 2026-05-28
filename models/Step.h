#pragma once

class Step {

public:
    virtual void execute() const = 0;

    virtual ~Step() = default;
};