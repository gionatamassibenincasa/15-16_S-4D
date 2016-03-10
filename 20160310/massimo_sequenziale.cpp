/* massimo_sequenziale.cpp
 *
 * Calcola il valore massimo tra quattro valori
 * memorizzati nelle variabili {a, b, c, d}.
 *
 * Considera a come valore massimo.
 * Confronta il massimo fino ad ora con il prossimo
 * valore. Se il valore e' maggiore del massimo fin
 * ora allora aggiorna il valore del massimo.
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    // Variabili
    int a, b, c, d;
    int max; //< Il valore massimo (fin ora)
    
    // Richiede l'immissione di 4 valori interi
    cout << "Immetti 4 valori interi" << endl;
    cin >> a >> b >> c >> d;
    
    max = a;
    if (b > max)
        max = b;
    if (c > max)
        max = c;
    if (d > max)
        max = d;
    
    // Scrittura del massimo
    cout << "Il numero massimo e' " << max << endl;
    return EXIT_SUCCESS;
}