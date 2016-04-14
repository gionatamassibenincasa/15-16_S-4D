/** bubble_sort.cpp
 * Ordinamento di un vettore a bolle
 */
#include <iostream>

using namespace std;

// Dichiarazioni
void bubble_sort(int v[], int len);
bool is_ordered(int v[], int len);
string print(int v[], int len);
void print_ordered(int v[], int len);
void show_iteration(int v[], int l, int len);
void show_min(int v[], int posmin);
void show_exchange(int v[], int l, int posmin);

void show_iteration(int v[], int e, int len)
{
	cout << "\nIterazione n. " << len - e << endl;
	cout << "Vettore: " << print(v, len) << endl;
	cout << "Partizione ordinata: " << print(v + e + 1, len - e - 1) << endl;
	cout << "Partizione non ordinata: " << print(v, e + 1) << endl;
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

void bubble_sort(int v[], int len)
{
	int swaps;
	
	for (int e = len - 1; e > 0; e--) {
		show_iteration(v, e, len);
		swaps = 0;

		for (int j = 0; j < e; j++) {
			if (v[j] > v[j + 1]) {
				show_exchange(v, j, j + 1);
				swaps++;

				int tmp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = tmp;
			}
		}
		if (swaps == 0)
			break;
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
	bubble_sort(v1, 5);
	print_ordered(v1, 5);

	return 0;
}
