#include <iostream>
#include <string>
#include <fstream>

using namespace std;


// Complete the commonChild function below.
int commonChild(string s1, string s2) {
	int n_1 = s1.length();
	int **tab = new int*[n_1 + 1];
	for (int i = 0; i <= n_1; i++) {tab[i] = new int[n_1 + 1];}
	for (int i = 0; i <= n_1; i++) {
		for (int j = 0; j <= n_1; j++) {
			tab[i][j] = 0;
		}
	}
	for (int i = 0; i < n_1; i++) {
		for (int j = 0; j < n_1; j++) {
			if (s1[i] == s2[j]) {
				tab[i + 1][j + 1] = tab[i][j] + 1;
			} else {
				tab[i][j + 1] >= tab[i + 1][j] ?
					tab[i + 1][j + 1] = tab[i][j + 1] : tab[i + 1][j + 1] = tab[i + 1][j];
			}
		}
	}

	return tab[n_1][n_1];

}

int main() {
	ifstream F("Text.txt");

	string s1;
	getline(F, s1);

	string s2;
	getline(F, s2);

	int result = commonChild(s1, s2);

	cout << result << "\n";

	F.close();

	return 0;
}


