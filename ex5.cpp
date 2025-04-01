#include <iostream>
#include <climits>

using namespace std;

int minSubArrayLen(int target, int nums[], int n);
int minSubArrayLen(int target, int nums[], int n) {
    int left = 0, current_sum = 0;
    int min_length = INT_MAX;

    for (int right = 0; right < n; right++) {
        current_sum += nums[right];

        while (current_sum >= target) {
            min_length = min(min_length, right - left + 1);
            current_sum -= nums[left];
            left++;
        }
    }

    return (min_length == INT_MAX) ? 0 : min_length;
}

int main() {
    int n;
    cin>>n;
    int *nums = new int[n];
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    int target = 7;

    cout << minSubArrayLen(target, nums, n) << endl;
    return 0;
}
