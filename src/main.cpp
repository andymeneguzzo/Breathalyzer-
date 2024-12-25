// Da correggere la formula che dà risultati errati

#include <iostream>
#include <vector>
#include <string>
#include "Drink.h"
#include "Meal.h"
#include "Breathalyzer.h"

int main() {
    std::cout << "=== ETILOMETRO INTELLIGENTE ===\n\n";

    // Creiamo un oggetto Breathalyzer, chiedendo il peso all'utente (opzionale)
    double userWeight;
    std::cout << "Inserisci il tuo peso in kg (default 70): ";
    std::cin >> userWeight;

    // Se l'utente inserisce un peso non valido, usiamo 70 kg
    if(userWeight <= 0) {
        userWeight = 70.0;
    }

    Breathalyzer breathalyzer(userWeight);

    // 1) Acquisizione bevande
    int numDrinks;
    std::cout << "\nQuante diverse tipologie di bevande alcoliche hai ingerito? ";
    std::cin >> numDrinks;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // pulizia buffer

    for(int i = 0; i < numDrinks; ++i) {
        std::string nomeBevanda;
        double volumeMl;
        double gradi;
        int quantita;
        double oreTrascorse;

        std::cout << "\n--- Bevanda #" << (i+1) << " ---\n";
        std::cout << "Nome bevanda (es. vino rosso, spritz, birra...): ";
        std::getline(std::cin, nomeBevanda);

        std::cout << "Volume di un bicchiere (ml) (es. 125 ml per vino, 200 ml per birra): ";
        std::cin >> volumeMl;

        std::cout << "Gradi alcolici (es. 12.5 per vino, 5.0 per birra): ";
        std::cin >> gradi;

        std::cout << "Numero di bicchieri ingeriti: ";
        std::cin >> quantita;

        std::cout << "Quante ore fa (circa) hai ingerito questa bevanda? ";
        std::cin >> oreTrascorse;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        Drink d(nomeBevanda, volumeMl, gradi, quantita, oreTrascorse);
        breathalyzer.addDrink(d);
    }

    // 2) Acquisizione pasti
    char haMangiato;
    std::cout << "\nHai fatto dei pasti nel frattempo? (s/n): ";
    std::cin >> haMangiato;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if(haMangiato == 's' || haMangiato == 'S') {
        int numMeals;
        std::cout << "Quanti pasti hai fatto? ";
        std::cin >> numMeals;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        for(int i = 0; i < numMeals; ++i) {
            std::string descrizione;
            double quantita;
            double oreTrascorse;

            std::cout << "\n--- Pasto #" << (i+1) << " ---\n";
            std::cout << "Descrizione pasto (es. 'Pasta al pomodoro'): ";
            std::getline(std::cin, descrizione);

            std::cout << "Quantita' approssimativa (grammi o porzioni): ";
            std::cin >> quantita;

            std::cout << "Quante ore fa (circa) hai mangiato? ";
            std::cin >> oreTrascorse;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            Meal m(descrizione, quantita, oreTrascorse);
            breathalyzer.addMeal(m);
        }
    }

    // 3) Calcolo del valore "etilometro" (BAC)
    double bac = breathalyzer.calculateBAC();
    
    // 4) Stampa risultato
    std::cout << "\n=================================\n";
    std::cout << "Valore stimato del BAC (g/l): " << bac << "\n";
    std::cout << Breathalyzer::getSanzioniFromBAC(bac) << std::endl;
    std::cout << "=================================\n";

    return 0;
}
