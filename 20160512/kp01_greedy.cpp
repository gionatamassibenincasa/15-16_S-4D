#include <cstdlib>
#include <iostream>

using namespace std;

bool verifica_ordinamento(
    const int n,
    const int p[],
    const int w[])
{
    // Ipotesi: tutti gli indici sono nella
    // posizione corretta
    for (int j = 0; j < n - 1; j++) {
        double rapp_j  = (double) p[j] / w[j],
               rapp_j1 = (double) p[j+1] / w[j+1];
        if (rapp_j < rapp_j1) {
            // ho trovato un controesempio
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv[])
{
    // Istanza del problema
    const int n = 8;
    const int p[n] =
        {15, 100, 90, 60, 40, 15, 10,  1};
    const int w[n] =
        { 2,  20, 20, 30, 40, 30, 60, 10};
    const int C = 102;
    // Soluzione
    int x[n] = {0, 0, 0, 0, 0, 0, 0, 0};
    int z = 0; //< profitto totale
 
    // Verificare l'ordinamento per
    // il rapporto tra profitto e peso
    bool ordinato = verifica_ordinamento(n, p, w);
    if (ordinato) {
        cout << "Vettore ordinato. Proseguiamo" << endl;
    } else {
        cout << "Immettere un vettore ordinato" << endl;
        return EXIT_FAILURE;
    }
    
}