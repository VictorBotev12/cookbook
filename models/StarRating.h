#pragma once

#include "Rating.h"
#include <vector>

class StarRating : public Rating {

private:
    std::vector<int> ratings;

public:
    void addRating(int stars) override;

    double getAverage() const override;
};