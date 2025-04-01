#include <iostream>

using namespace std;

void swap(int &a, int &b);
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(int arr[], int n);
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}

void findThreeSum(int nums[], int n);
void findThreeSum(int nums[], int n) {
    selectionSort(nums, n);

    for (int i = 0; i < n - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int left = i + 1, right = n - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0) {
                cout << "[" << nums[i] << ", " << nums[left] << ", " << nums[right] << "]\n";
                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;
                left++;
                right--;
            } 
            else if (sum < 0) left++;
            else right--;
        }
    }
}

int main() {
    int nums[6] = {-1, 0, 1, 2, -1, -4};
    int n = 6;
    findThreeSum(nums, n);

    return 0;
}
