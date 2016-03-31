/* minimo_serie.cpp
 * Dato in input il numero di elementi di una serie di dati interi
 * e i dati stessi, calcolare il minimo e stamparlo
 */
 
#include <iostream>
#include <cstdlib>
#include <climits>
 
using namespace std;
 
int main(int argc, char *argv[]) {
 int numero_di_dati_residuo,
     numero,
     minimo = INT_MAX;
 
 cout << "Immetti il numero di dati della serie numerica: ";
 cin >> numero_di_dati_residuo;
 
 do {
   cout << "Scrivi un numero: ";
   cin >> numero;
   if (numero < minimo)
     minimo = numero;
   numero_di_dati_residuo--;
 } while (numero_di_dati_residuo > 0);
 
 cout << "Il numero minimo della serie vale: " << minimo << endl;
 
#ifdef _WIN32
	/* Se si compila per windows allora si richiede
	   l'esecuzione del programma pause */
	system("pause");
#endif
 
 return EXIT_SUCCESS;
}