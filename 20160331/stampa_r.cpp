/** stampa_r.cpp
 * 
 * Stampa ricorsivamente i valori di un vettore di caratteri.
 * Se la lunghezza del vettore è zero non fa nulla, altrimenti
 * stampa il valore del primo elemento e richiama se stessa
 * con il vettore privato del primo elemento.
 */
 
#include <cstdio>
using namespace std;
 
void stampa_r(char stringa[], int lunghezza);
 
void stampa_r(char stringa[], int lunghezza)
{
     if (lunghezza > 0) {
        putchar(stringa[0]);
        stampa_r(stringa+1, lunghezza-1);
     } else {
        putchar('\n');
     }
}
 
int main(int argc, char *argv[])
{
  char s[]="Ciao quarta D!";
  
  stampa_r(s, sizeof(s));
  
  return 0;
}

 