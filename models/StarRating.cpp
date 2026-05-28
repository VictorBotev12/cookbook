#include "StarRating.h"

void StarRating::addRating(int stars) {

    if (stars >= 1 && stars <= 5) {
        ratings.push_back(stars);
    }
}

double StarRating::getAverage() const {

    if (ratings.empty()) {
        return 0.0;
    }

    double sum = 0;

    for (int r : ratings) {
        sum += r;
    }

    return sum / ratings.size();
}