#include "Meal.h"

Meal::Meal() : description(""), quantity(0.0), timeSinceMeal(0.0) {}

Meal::Meal(const std::string& description, double quantity, double timeSinceMeal) : description(description), quantity(quantity), timeSinceMeal(timeSinceMeal) {}

// Getters
std::string Meal::getDescription() const {
    return description;
}

double Meal::getQuantity() const {
    return quantity;
}

double Meal::getTimeSinceMeal() const {
    return timeSinceMeal;
}

// Setters
void Meal::setDescription(const std::string& description) {
    this->description = description;
}

void Meal::setQuantity(double quantity) {
    this->quantity = quantity;
}

void Meal::setTimeSinceMeal(double timeSinceMeal) {
    this->timeSinceMeal = timeSinceMeal;
}