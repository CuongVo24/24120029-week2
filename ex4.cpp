#include <iostream>
using namespace std;
const int MAX_N = 1000;
int findMax(int arr[], int n);
int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return maxVal;
}
int findSum(int arr[], int n);
int findSum(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}


bool canShip(int weights[], int n, int days, int capacity) {
    int dayCount = 1, currentWeight = 0;
    
    for (int i = 0; i < n; i++) {
        if (currentWeight + weights[i] > capacity) {
            dayCount++;
            currentWeight = 0;
        }
        currentWeight += weights[i];
    }
    
    return dayCount <= days;
}

int shipWithinDays(int weights[], int n, int days);
int shipWithinDays(int weights[], int n, int days) {
    int low = findMax(weights, n);
    int high = findSum(weights, n);

    while (low < high) {
        int mid = (low + high) / 2;
        if (canShip(weights, n, days, mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    
    return low;
}

int main() {
    int weights[MAX_N], n, days;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    cin >> days;

    cout << shipWithinDays(weights, n, days) << endl;

    return 0;
}
