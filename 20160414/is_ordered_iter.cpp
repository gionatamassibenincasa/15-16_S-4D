/** is_ordered_iter
 * Scrivere una funzione iterativa che
 * restituisca "true" se un vettore è ordinato,
 * "false" altrimenti.
 */
 
#include <iostream>
using namespace std;

// Dichiarazione delle funzioni
bool is_ordered(int v[], int len);
void print_ordered(int v[], int len);
void print_vector(int v[], int len);

// Definizione della funzione is_ordered
/** is_ordered accetta come argomenti
 * un vettore di interi e la sua lunghezza;
 * restituisce true se il vettore è ordinato
 * false altrimenti
 * 
 * @param v il vettore di numeri interi
 * @param len lunghezza del vettore
 * @return true se il vettore è ordnato
 */
bool is_ordered(int v[], int len)
{
    // Devo verificare che v[i] <= v[i+1]
    // per i = 0, 1, ..., len - 2
    for (int i = 0; i < len - 1; i++) {
        // se trovo un indice i tale che
        // v[i] > v[i+1] allora il vettore
        // non è ordinato
        if (v[i] > v[i+1])
            return false;
    }
    // il vettore è ordinato
    return true;
}

void print_ordered(int v[], int len)
{
    cout << "Il vettore: ";
    // Stampa il vettore
    print_vector(v, len);
    cout << " è ";
    if (is_ordered(v, len) == false) {
        cout << "non ";
    }
    cout << "ordinato" << endl;
}

void print_vector(int v[], int len)
{
    cout << "{";
    if (len > 0) {
        cout << v[0];
    }
    for (int i = 1; i < len; i++) {
        cout << ", " << to_string(v[i]);
    }
    cout << "}";
}

int main(int argc, char *argv[])
{
    int v1[5] = {4, 7, 10, 1, 5},
        v2[5] = {1, 4, 5, 7, 10};
        
    print_ordered(v1, 5);
    print_ordered(v2, 5);
    
    return 0;
}
