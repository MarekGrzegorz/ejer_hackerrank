#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Complete the substrCount function below.
long substrCount(int n, string s) {
	bool fx = false;
	int cont = 0, mem = 0, result = 0;
	int **tab = new int*[26];	
	for (int i = 0; i < 26; i++) { tab[i] = new int[n];}

	for (int i = 0; i < 26; i++) {		//initialization
		for (int j = 0; j < n; j++) { tab[i][j] = 0; }
	}
	
	for (int i = 0; i < n; i++) { tab[s[i]-97][i] = 1;} // cada fila una letra

	for (int i = 0; i < 26; i++) {		//contador por letras
		for (int j = 0; j < n; j++) {
			if (tab[i][j] == 1) { cont++; }
			if (tab[i][j] == 0) {
				if (fx) {
					mem < cont ? result += mem : result += cont;
					mem = 0; fx = false;
				}
				if (j - 1 >= 0 && j + 1 < n && tab[i][j - 1] == 1 && tab[i][j + 1] == 1) {
					mem = cont;
					fx = true;
				}
				result += (cont + cont * cont) / 2;
				cont = 0;				
			}
		}		
	}
	for (int i = 0; i < 26; i++) { delete[] tab[i]; }
	delete[]tab;
	return result;
}

int main() {
	ifstream F("Text.txt");

	int n;
	F >> n;
	F.ignore(numeric_limits<streamsize>::max(), '\n');

	string s;
	getline(F, s);
	long result = substrCount(n, s);
	cout << result << "\n";
	F.close();
	return 0;
}


