/* quadrato.cpp
 *
 * Definisce la funzione "quadrato" che accetta in
 * input un numero intero e ne restituisce il
 * quadrato.
 */
 
#include <iostream>
using namespace std;

// Dichiarazione
// "quadrato" e' una funzione che accetta un argomento
// di tipo intero e restituisce un valore intero
int quadrato(int n);

// Definizione della funzione "quadrato"
int quadrato(int n)
{
    return n*n;
}

int main(int argc, char *argv[])
{
    for (int i=0; i < 10; i++)
        cout << "Il quadrato di " << i
             << " vale " << quadrato(i) << endl;
#ifdef _WIN32
    system("pause");
#endif

    return 0;    
}
