#ifndef BREATHALYZIER_H
#define BREATHALYZIER_H

#include <vector>
#include "Drink.h"
#include "Meal.h"

class Breathalyzer {
    private:
        std::vector<Drink> drinks;
        std::vector<Meal> meals;
        double userWeight;
        bool reduceForMeals;

    public:
        Breathalyzer(double userWeight = 70.0); // default peso

        void addDrink(const Drink& drink);
        void addMeal(const Meal& meal);
        void setUserWeight(double userWeight);

        // Metodo PRINCIPALE per calcolo BAC
        double calculateBAC();

        static std::string getSanzioniFromBAC(double bac);
};

#endif