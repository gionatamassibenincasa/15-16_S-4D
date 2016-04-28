/** indovina_num.cpp
 * 
 * Il computer chiede all'utente di pensare
 * ad un numero compreso tra 1 e 1024.
 * Il computer determina il numero tramite
 * la ricerca binaria, chiedendo all'utente
 * se il numero è quello giusto, oppure se
 * è maggiore o minore.
 * Il computer stampa il numero di tentativi.
 */
 
#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    cout << "Pensa ad un numero compreso tra"
       " 1 e 1024." << endl;
     
    int l = 1,
        r = 1024,
        iter = 0,
        numero;
    
    while (l != r) {
        char ans;
        if (iter == 0) {
            cout << "Il numero e' " 
                 << l << " (I) o e' maggiore (M)?"
                 << endl;
            cin >> ans;
            if (ans == 'I') {
                numero = l;
                break;
            }
            
            cout << "Il numero e' "  
                 << r << " (I) o e' minore (m)?"
                 << endl;
            cin >> ans;
            if (ans == 'I') {
                numero = r;
                break;
            }
        }
        
        int m = (l + r) / 2;
        cout << "Iterazione " << iter + 3 << " ";
        cout << "il numero e' " 
             << m << " (I) o e' minore (m)"
             << " o e' maggiore (M)?"
             << endl;
        cin >> ans;
        if (ans == 'I') {
            numero = m;
            break;
        } else if (ans == 'm') {
            r = m;
        } else if (ans == 'M') {
            l = m;
        }
        iter++;
    }
    
    cout << "Il numero e' " << numero << endl;
    cout << "Iterazioni " << iter + 3 << endl;
    
    return EXIT_SUCCESS;
}