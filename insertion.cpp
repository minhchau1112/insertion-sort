/*
- Giả sử a0,..., ai có thứ tự, hãy tìm vị trí để chèn phần tử
ai +1 vào trình tự đó sao cho nó vẫn có trật tự.
*/

#include<iostream>
using namespace std;

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