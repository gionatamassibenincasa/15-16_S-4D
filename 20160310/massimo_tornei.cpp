/* massimo_tornei.cpp
 *
 * Calcola il valore massimo tra quattro valori
 * memorizzati nelle variabili {a, b, c, d}.
 *
 * Considera gli "scontri diretti" in due turni:
 * il primo (le semifinali) fa emergere il valore
 * maggiore del confronto tra a e b e del confronto
 * tra c e d;
 * il secondo (la finale) fa emergere il valore
 * maggiore tra coloro che proseguono il primo turno.
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    // Variabili
    int a, b, c, d;
    int s1, s2; //< Il valore delle "finaliste"
    int max; //< Il valore massimo
    
    // Richiede l'immissione di 4 valori interi
    cout << "Immetti 4 valori interi" << endl;
    cin >> a >> b >> c >> d;
    
    if (a > b)
        s1 = a;
    else
        s1 = b;
        
    if (c > d)
        s2 = c;
    else
        s2 = d;
        
    if (s1 > s2)
        max = s1;
    else
        max = s2;
        
    cout << max << endl;
    return EXIT_SUCCESS;
}