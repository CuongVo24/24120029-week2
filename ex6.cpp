#include <iostream>
using namespace std;
void twoPointers(int a[], int n, int k);
void twoPointers(int a[], int n, int k) {
	int left = 0;
	int right = n - 1;
	while (left < right) {
		if (a[left] + a[right] == k) {
			cout << "YES" << endl;
			return;
		}
		if (a[left] + a[right] < k) {
			left++;
		}
		if (a[left] + a[right] > k) {
			right--;
		}
	}
	cout << "NO" << endl;
	return;
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
	twoPointers(a, n, k);
	return 0;
}
