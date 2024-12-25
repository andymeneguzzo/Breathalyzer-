#include "Drink.h"

Drink::Drink()
    : name(""), volumeMl(0.0), alcolholDegree(0.0), quantity(0.0), timeSinceDrink(0.0) 
{}

Drink::Drink(std::string name, double volumeMl, double alcolholDegree, int quantity, double timeSinceDrink)
    : name(name), volumeMl(volumeMl), alcolholDegree(alcolholDegree), quantity(quantity), timeSinceDrink(timeSinceDrink)
{}

// Getters
std::string Drink::getName() const {
    return name;
}

double Drink::getVolumeMl() const {
    return volumeMl;
}

double Drink::getAlcolholDegree() const {
    return alcolholDegree;
}

int Drink::getQuantity() const {
    return quantity;
}

double Drink::getTimeSinceDrink() const {
    return timeSinceDrink;
}

// Setters
void Drink::setName(const std::string& name) {
    this->name = name;
}

void Drink::setVolumeMl(double volumeMl) {
    this->volumeMl = volumeMl;
}

void Drink::setAlcolholDegree(double alcolholDegree) {
    this->alcolholDegree = alcolholDegree;
}

void Drink::setQuantity(int quantity) {
    this->quantity = quantity;
}

void Drink::setTimeSinceDrink(double timeSinceDrink) {
    this->timeSinceDrink = timeSinceDrink;
}

// Calcola grammi di alcohol totale
double Drink::calculateAlcoholGrams() const {
    double liters = (volumeMl * quantity) / 1000;
    return liters * (alcolholDegree/100) * 0.8;
}

