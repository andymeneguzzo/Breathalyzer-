#ifndef MEAL_H
#define MEAL_H

#include <string>

class Meal {
    private:
        std::string description;
        double quantity;
        double timeSinceMeal;

    public:
        Meal();
        Meal(const std::string& description, double quantity, double timeSinceMeal);

        // Getters
        std::string getDescription() const;
        double getQuantity() const;
        double getTimeSinceMeal() const;

        // Setters
        void setDescription(const std::string& description);
        void setQuantity(double quantity);
        void setTimeSinceMeal(double timeSinceMeal);
};

#endif // MEAL_H