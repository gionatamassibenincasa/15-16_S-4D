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
    z = 0;
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
    s << "[";
    if (n > 0) {
        s << " " << v[0];
    }
    for (int j = 1; j < n; j++) {
        s << ", " << v[j];
    }
    s << "]";
    
    return s.str();
}

bool soluzione_successiva(int x_corrente[], const int n)
{
    // Non e' l'ultimo elemento
    if(x_corrente[n-1] == 0) {
        x_corrente[n-1] = 1;
        return true;
    }
    
    // Verifico che non sia l'ultimo elemento
    bool ultimo = true;
    for (int j = 0; j < n - 1; j++) {
        if (x_corrente[j] == 0) {
            ultimo = false;
            break;
        }
    }
    
    if (ultimo == true)
        return false; // ultimo elemento
    
    // Non e' l'ultimo elemento e termina con un 1 
    int k = n - 1;
    while (x_corrente[k] == 1) {
        x_corrente[k] = 0;
        k--;
    }
    // x_corrente[k] e' sicuramente 0
    x_corrente[k] = 1;
    
    return true;
}

bool valuta(const int p[], const int w[], int c,
                    const int n, int &z, int x[])
{
    z = 0;
    for (int j = 0; j < n; j++) {
        if (x[j] == 1) {
            z += p[j];
            c -= w[j];
            if (c < 0) {
                return false;
            }
        }
    }
    return true;
}

void copia(const int v_src[], int v_dst[], const int n)
{
    for(int j = 0; j < n; j++)
        v_dst[j] = v_src[j];
}

int ricerca_esaustiva(const int p[], const int w[], const int c,
                    const int n, int &z_star, int x_star[])
{
    // soluzione iniziale
    int x[n];
    for(int j = 0; j < n; j++) {
        x[j] = 0;
    }
    int z = 0;
    
    int soluzioni_ammissibili = 0;
    
    // calcola il profitto e valuta l'ammissibilita'
    if (valuta(p, w, c, n, z, x)) {
        soluzioni_ammissibili++;
        z_star = z;
        copia(x, x_star, n);
    }
    
    while (soluzione_successiva(x, n)) {
    // se la soluzione e' ammissibile
    //   se il profitto e' maggiore di quello della miglior soluzione trovata
    //   aggiorna la soluzione (ottima fino ad ora)
        if (valuta(p, w, c, n, z, x)) {
            soluzioni_ammissibili++;
            z_star = z;
            copia(x, x_star, n);
        }
    }

    return soluzioni_ammissibili;
}

int elemento_critico(const int w[], const int n, int c) {
    int s = 0;
    for (; s < n && c >= 0; s++) {
        c -= w[s];
    }
    
    return s-1;
}

int soluzione_rilassamento_continuo(const int n, const int p[],
        const int w[], int c, int x_star[], int &z_star)
{
    int s = elemento_critico(w, n, c);
    z_star = 0;
    for (int j = 0; j < s; j++) {
        z_star += p[j];
        c -= w[j];
    }
    z_star += (p[s] * c) / w[s];
}

int main(int argc, char *argv[])
{
    // Istanza del problema
    const int n = 8;
    const int p[n] =
        {15, 100, 90, 60, 40, 15, 10, 1};
    const int w[n] =
        {2,  20, 20, 30, 40, 30, 60, 10};
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
    
    // Soluzione esatta con ricerca esaustiva
    cout << endl << "Soluzione esatta con enumerazione totale" << endl;

    int soluzioni_ammissibili =
        ricerca_esaustiva(p, w, C, n, z, x);
 
    cout << "Il numeri soluzioni ammissibili e' " 
         << soluzioni_ammissibili
         << " mentre il numero di soluzioni e' "
         << (1 << n) << "." << endl;
    cout << "Il valore del profitto e' "
         << z << endl;
    cout << "Il vettore soluzione e' "
         << stampa_vettore(n, x) << endl;
    
    // Soluzione approssimata (golosa)
    cout << endl << "Soluzione approssimata con algoritmo 'goloso'" << endl;

    soluzione_greedy(n, p, w, C, x, z);
    
    cout << "Il valore del profitto e' "
         << z << endl;
    cout << "Il vettore soluzione e' "
         << stampa_vettore(n, x) << endl;
         
    // Soluzione del rilassamento continuo
    cout << endl << "Soluzione del rilassamento continuo" << endl;
    
    soluzione_rilassamento_continuo(n, p, w, C, x, z);

    cout << "Profitto della soluzione del rilassamento continuo: "
         << z << endl;
    
 
#ifdef _WIN32
    system("PAUSE");
#endif
}