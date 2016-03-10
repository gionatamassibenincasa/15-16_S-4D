/* somma_while.cpp
 *
 * Calcola la somma dei primi n numeri naturali.
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    // Variabili
    unsigned int n; //< Il massimo numero da sommare.
    unsigned int sum; //< Somma (fin ora)
    unsigned int c; //< Il numero che sto considerando ora
    
    // Richiede l'immissione di n (intero)
    cout << "Immetti il numero n" << endl;
    cin >> n;
    
    sum = 0;
    c = 1;
    while (c <= n) {
        sum += c;
        c++;
    }
    
    // Scrittura della somma
    cout << "La somma dei primi " << n << " numeri vale " << sum << endl;
    return EXIT_SUCCESS;
}