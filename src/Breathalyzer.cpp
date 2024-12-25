#include "Breathalyzer.h"
#include <cmath>
#include <string>
#include <sstream>

Breathalyzer::Breathalyzer(double userWeight) : userWeight(userWeight), reduceForMeals(true) {}

void Breathalyzer::addDrink(const Drink &drink) {
    drinks.push_back(drink);
}

void Breathalyzer::addMeal(const Meal &meal) {
    meals.push_back(meal);
}

void Breathalyzer::setUserWeight(double userWeight) {
    this->userWeight = userWeight;
}

double Breathalyzer::calculateBAC() {
    double totalBAC = 0.0;

    for(const auto& d : drinks) {
        double alcoholGrams = d.calculateAlcoholGrams();
        double bacContribution = alcoholGrams / (userWeight * 0.68);

        double bacReduction = 0.15 * d.getTimeSinceDrink();
        bacContribution -= bacReduction;

        if(bacContribution < 0.0) {
            bacContribution = 0.0;
        }
        totalBAC += bacContribution;
    }

    if(reduceForMeals && !meals.empty()) {
        double totalMealFactor = 0.0;
        for(const auto& m : meals) {
            double mealFactor = m.getQuantity() / 300.0;
            totalMealFactor += mealFactor;
        }

        double mealReduction = (totalMealFactor > 3.0) ? 0.30 : (0.10 * totalMealFactor);
        totalBAC = totalBAC * (1.0 - mealReduction);

        if(totalBAC < 0.0) {
            totalBAC = 0.0;
        }
    }

    return totalBAC;
}

std::string Breathalyzer::getSanzioniFromBAC(double bac) {
    if(bac < 0.5) {
        return "Se hai meno di 21 anni, rischi multa da 164 euro";
    } else if(bac >= 0.5 && bac < 0.8) {
        return "Multa fino a 1064 euro e perdita di 10 punti dalla patente, 20 per neopatentati";
    } else if(bac >= 0.8 && bac < 1.5) {
        return "Multa fino a 3200 euro, perdita di 10 punti dalla patente, 20 per neopatentati, e sospensione da 6 a 12 mesi";
    } else if(bac == 0){
        return "Sei OKAY! bro";
    } else {
        return "Multa fino a 6000 euro, arresto da 6 a 12 mesi, perdita di 10 punti dalla patente, 20 se neopatentato, sospensione della patente da 12 a 24 mesi";
    }
}