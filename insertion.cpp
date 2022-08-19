/*
- Giả sử a0,..., ai có thứ tự, hãy tìm vị trí để chèn phần tử
ai +1 vào trình tự đó sao cho nó vẫn có trật tự.
*/

#include<iostream>
using namespace std;
void flash_sort(int a[], int n) {
	if (n <= 1) return;
	int m = floor(n * 0.45);
	// int m = n;
	for (int i = 0; i < m; ++i)
		__L[i] = 0;
	int Mx = a[0], Mn = a[0];
	for (int i = 1; i < n; ++i) {
		if (Mx < a[i]) Mx = a[i];
		if (Mn > a[i]) Mn = a[i];
	}
	if (Mx == Mn)
		return;
	for (int i = 0; i < n; ++i) {
		int k = floor(((m - 1) * (a[i] - Mn)) / (Mx - Mn));
		++__L[k];
	}
	for (int i = 1; i < m; ++i)
		__L[i] += __L[i - 1];
	//step 2
	int count = 0;
	int i = 0;
	while (count < n) {
		int k = floor(((m - 1) * (a[i] - Mn)) / (Mx - Mn));
		while (i >= __L[k]) {
			++i;
			k = floor(((m - 1) * (a[i] - Mn)) / (Mx - Mn));
		}
		int z = a[i];
		while (i != __L[k]) {
			k = floor(((m - 1) * (z - Mn)) / (Mx - Mn));
			int y = a[__L[k] - 1];
			a[--__L[k]] = z;
			z = y;
			++count;
		}
	}
	//step 3

	for (int k = 1; k < m; ++k) {
		for (int i = __L[k] - 2; i >= __L[k - 1]; --i)
			if (a[i] > a[i + 1]) {
				int t = a[i], j = i;
				while (t > a[j + 1]) { a[j] = a[j + 1]; ++j; }
				a[j] = t;
			}
	}

}
void InsertionSort(int* a, int n) {
	for (int i = 1; i < n; i++) {
		int x = a[i];
		int pos = i - 1;
		while (pos >= 0 && a[pos] > x) {
			a[pos + 1] = a[pos];
			pos--;
		}
		a[pos + 1] = x;
	}
}

int main() {
	int n;
	cout << "Enter the number of elements : ";
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		a[i] = rand();
	}
	InsertionSort(a, n);
	for (int j = 0; j < n; j++) {
		cout << a[j] << " ";
	}
	delete[] a;
	return 0;
}