/* esempio_argomenti.cpp
 * Mostra il numero di argomenti e il loro contenuto
 */
 
 #include <iostream>
 #include <cstdlib>
 #include <climits>
 
 using namespace std;
 
 int main(int argc, char *argv[]) {
     cout << "argc: " << argc << endl;
     for (int j = 0; j < argc; j++)
        cout << "argv[" << j << "] <- " << argv[j] << endl;
     
     return EXIT_SUCCESS;
 }