#include <cstdlib>
#include <iostream>
#include <sstream>

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

void soluzione_greedy(
    const int n,
    const int p[],
    const int w[],
    int Cr, //< capacita' residua
    int x[],
    int& z)
{
    for (int j = 0; j < n; j++) {
        // Se il peso dell'oggetto j e'
        // <= alla capacita' residua
        if (w[j] <= Cr) {
            // Aggiungo l'oggetto j alla soluzione
            x[j] = 1;
            // Aggiorno il valore del profitto
            z += p[j];
            // Aggiorno la capacita' residua
            Cr -= w[j];
        } else {
            // Non ci sono oggetti j nella soluzione
            x[j] = 0;
        }
    }
}

string stampa_vettore(const int n, const int v[]) {
    stringstream s;
    s << "(";
    if (n > 0) {
        s << " " << v[0];
    }
    for (int j = 1; j < n; j++) {
        s << ", " << v[j];
    }
    s << ")";
    
    return s.str();
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
    
    soluzione_greedy(n, p, w, C, x, z);
    
    cout << "Il valore del profitto e' "
         << z << endl;
    cout << "Il vettore soluzione e' "
         << stampa_vettore(n, x) << endl;
 
#ifdef _WIN32
    system("PAUSE");
#endif
}