#pragma once

class Rating {

public:
    virtual void addRating(int stars) = 0;
    virtual double getAverage() const = 0;

    virtual ~Rating() = default;
};