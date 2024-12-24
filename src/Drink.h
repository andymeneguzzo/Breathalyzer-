#ifndef DRINK_H
#define DRINK_H

#include <string>

class Drink {
    private:
        std::string name;
        double volumeMl;
        double alcolholDegree;
        int quantity;
        double timeSinceDrink;

    public:
        Drink();
        Drink(std::string name, double volumeMl, double alcolholDegree, int quantity, double timeSinceDrink);

        // Getters
        std::string getName() const;
        double getVolumeMl() const;
        double getAlcolholDegree() const;
        int getQuantity() const;
        double getTimeSinceDrink() const;

        // Setters
        void setName(const std::string& name);
        void setVolumeMl(double volumeMl);
        void setAlcolholDegree(double alcolholDegree);
        void setQuantity(int quantity);
        void setTimeSinceDrink(double timeSinceDrink);

        // Calcola grammi di alcohol totale
        double calculateAlcoholGrams() const;
};


#endif // DRINK_H