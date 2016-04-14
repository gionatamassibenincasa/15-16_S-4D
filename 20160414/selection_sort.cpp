/** selection_sort.cpp
 * 
 * Ordinamento per selezione
 */

#include <iostream>

using namespace std;

// Dichiarazioni
void selection_sort(int v[], int len);
bool is_ordered(int v[], int len);
string print(int v[], int len);
void print_ordered(int v[], int len);
void show_iteration(int v[], int l, int len);
void show_min(int v[], int posmin);
void show_exchange(int v[], int l, int posmin);

void show_iteration(int v[], int l, int len)
{
	cout << "\nIterazione n. " << l + 1 << endl;
	cout << "Vettore: " << print(v, len) << endl;
	cout << "Partizione ordinata: " << print(v, l) << endl;
	cout << "Partizione non ordinata: " << print(v + l, len - l) << endl;
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

// Definizioni
void selection_sort(int v[], int len)
{
	for (int l = 0; l < len - 1; l++) {
		show_iteration(v, l, len);

		// selezione del minimo
		int posmin = l;
		for (int j = l + 1; j < len; j++)
			if (v[j] < v[posmin])
				posmin = j;

		/* posmin è diventato l' indice del
		   valore minimo nella partizione di
		   v non ordinato */
		show_min(v, posmin);

		// scambio
		if (l != posmin) {
			show_exchange(v, l, posmin);

			int tmp = v[posmin];
			v[posmin] = v[l];
			v[l] = tmp;
		}
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

	print_ordered(v1, 5);
	selection_sort(v1, 5);
	print_ordered(v1, 5);

	return 0;
}