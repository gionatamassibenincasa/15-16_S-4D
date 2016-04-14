/** insertion_sort.cpp
 * Ordinamento di un vettore a bolle
 */
#include <iostream>

using namespace std;

// Dichiarazioni
void insertion_sort(int v[], int len);
bool is_ordered(int v[], int len);
string print(int v[], int len);
void print_ordered(int v[], int len);
void show_iteration(int v[], int l, int len);
void show_min(int v[], int posmin);
void show_exchange(int v[], int l, int posmin);

void show_iteration(int v[], int e, int len)
{
	cout << "\nIterazione n. " << e << endl;
	cout << "Vettore: " << print(v, len) << endl;
	cout << "Partizione ordinata: " << print(v, e) << endl;
	cout << "Partizione non ordinata: " << print(v + e, len - e) << endl;
}

void show_min(int v[], int posmin)
{
	cout << "Posizione del minimo: "
	    << posmin << " con valore " << v[posmin] << endl;
}

void show_exchange(int v[], int l, int posmin)
{
	cout << "Scambio delle posizioni "
	    << l << " (valore " << v[l] <<
	    ") e " << posmin << " (valore " << v[posmin] << ")" << endl;

}

void insertion_sort(int v[], int len)
{
	for (int n = 1; n < len; n++) {
		show_iteration(v, n, len);

		// sposta l'elemento in posizione
		// n nella posizione che gli compete
		int value = v[n];
		int j = n - 1;
		for (; j >= 0 && v[j] > value; j--) {
			v[j+1] = v[j];
		}
		v[j+1] = value;
	}
}

/* Definizione della funzione
 * is_ordered
 */
bool is_ordered(int v[], int len)
{
	if (len <= 1)
		return true;
	for (int i = 0; i < len - 1; i++)
		if (v[i] > v[i + 1])
			return false;
	return true;
}

/* Definizione della funzione
 * print
 */
string print(int v[], int len)
{
	string str = "{";
	if (len >= 1)
		str += to_string(v[0]);
	for (int i = 1; i < len; i++)
		str += ", " + to_string(v[i]);
	str += "}";
	return str;
}

/* Definizione della funzione
 * print_ordered
 */
void print_ordered(int v[], int len)
{
	cout << "Il vettore " <<
	    print(v, len) <<
	    " e' " << (is_ordered(v, len) ? "" : "non ") << " ordinato" << endl;
}

/* test della funzione con due
 * casi di test
 */
int main(int argc, char *argv[])
{
	int v1[] = { 4, 7, 2, 9, 1 };
	// int v1[] = { 1, 2, 3, 4, 5 };

	print_ordered(v1, 5);
	insertion_sort(v1, 5);
	print_ordered(v1, 5);

	return 0;
}
