/* mediano.cpp
 *
 * Dato in input il numero dispari di elementi di una serie di dati
 * interi e i dati stessi, calcola il mediano (quello che ha tanti
 * elementi più piccoli quanti elementi più grandi)
 */
 
#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

void stampa_array(int array[], int lunghezza)
{
    if (lunghezza > 0) {
        cout << array[0] << " ";
        stampa_array(array + 1, lunghezza - 1);
    } else {
        cout << endl;
    }
}

int main(int argc, char *argv[])
{
    // Dichiarazione della variabile numero_elementi
    int numero_elementi;
    do { // Itera fino a che numero_elementi e' pari
        cout << "Immetti il numero di dati (dispari): ";
        cin >> numero_elementi;
    } while (numero_elementi % 2 == 0);
    // numero_elementi e' dispari
    
    // riserva spazio per la serie dati
    int serie[numero_elementi];
    // popola l'array
    for(int j = 0; j < numero_elementi; j++) {
        cout << "Immetti il dato numero " << j+1 << ": ";
        cin >> serie[j];
    }
    
    // Stampa l'array
    cout << "Il vettore non ordinato ";
    stampa_array(serie, numero_elementi);
    
    // ordina l'array
    sort(serie, serie+numero_elementi);
    
    // Stampa l'array ordinato
    cout << "Il vettore ordinato: ";
    stampa_array(serie, numero_elementi);

    // Estrae l'elemento mediano
    cout << "L'elemento mediano vale: " <<
        serie[numero_elementi/2] << endl;

    return EXIT_SUCCESS;    
}
 