#include <iostream>
using namespace std;
void rotate(int a[], int n, int k);
void rotate(int a[], int n, int k) {
	k= k % n;
	if (k == 0) {
		return;
	}
	int* temp = new int[n];
	for (int i = 0; i < k; i++) {
		temp[i] = a[n - k + i];
	}
	for (int i = k; i < n; i++) {
		temp[i] = a[i - k];
	}
	for (int z = 0; z < n; z++) {
		a[z] = temp[z];
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}
int main() {
	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int k;
	cin >> k;
	rotate(a, n, k);
	return 0;
}
