#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

vector<string> split_string(string input_string);

long long fusion(int tab[], int left, int right) {
	long long cont = 0;
	int media = ((left + right) / 2) + 1, end = right + 1;
	int bg = left;
	int *tmp = new int[right - left + 1];
	right = media;
	int k = 0;
	while (left < media && right < end) {
		if (tab[left] <= tab[right]) {
			tmp[k] = tab[left];
			left++;
		} else {
			tmp[k] = tab[right];
			cont += (media - left);
			right++;
		}
		k++;
	}
	for (; left < media; left++, k++)
		tmp[k] = tab[left];
	for (; right < end; right++, k++)
		tmp[k] = tab[right];
	for (k = 0; bg < end; bg++, k++)
		tab[bg] = tmp[k];
	delete[]tmp;
	return cont;
}

void MergeSort(int tab[], int left, int right, long long &cont) {

	int media;
	if (left < right) {
		media = (left + right) / 2;
		
		MergeSort(tab, left, media, cont);
		MergeSort(tab, media + 1, right,cont);
		cont += fusion(tab, left, right);
	}
}


int main() {
	ifstream F("Text.txt");

	int t;
	F >> t;

	for (int t_itr = 0; t_itr < t; t_itr++) {
		int n;
		F >> n;

		int* arr = new int[n];
		for (int i = 0; i < n; i++) {	
			F >> arr[i];
		}

		long long result = 0;
		MergeSort(arr, 0, n - 1, result);
		cout << result << "\n";
		delete[]arr;	
	}

	F.close();
	return 0;
}

