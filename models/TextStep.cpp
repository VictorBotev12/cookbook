#include "TextStep.h"
#include <iostream>

TextStep::TextStep(const std::string& text)
    : text(text) {
}

void TextStep::execute() const {
    std::cout << text << std::endl;
}