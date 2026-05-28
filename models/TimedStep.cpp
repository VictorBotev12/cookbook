#include "TimedStep.h"
#include <iostream>

TimedStep::TimedStep(const std::string& text, int minutes)
    : text(text), minutes(minutes) {
}

void TimedStep::execute() const {

    std::cout
        << text
        << " ("
        << minutes
        << " min)"
        << std::endl;
}