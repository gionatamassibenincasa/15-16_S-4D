/* potenza.cpp
 *
 * Definisce la funzione "potenza" che accetta in
 * input un numero intero detto base e uno non
 * negativo detto esponente e restituisce il
 * valore base elevato ad esponente.
 */
 
#include <iostream>
using namespace std;

int potenza(int base, int esponente);

int potenza(int base, int esponente)
{
    if (esponente == 0)
        return 1;
    else
        return base * potenza(base, esponente-1);
}

int main(int argc, char *argv[])
{
    cout << potenza(10, 3);
    
    /*
    for (int b=1; b < 11; b++)
        for (int e=0; e < 4; e++)
        cout << b << " elevato a " << e
             << " vale " << potenza(b, e) << endl;
    */
#ifdef _WIN32
    system("pause");
#endif

    return 0;    
}
