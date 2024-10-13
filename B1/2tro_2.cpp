#include <bits/stdc++.h>
using namespace std;

void findSubarrays(const vector<int>& arr, int target) {
    int left = 0;                 
    int sum = 0;                 

    for (int right = 0; right < arr.size(); right++) {
        sum += arr[right];        

                while (sum > target && left <= right) {
            sum -= arr[left];     
            left++;              
        }

                if (sum <= target) {
            cout << "Doan con: ";
            for (int k = left; k <= right; k++) {
                cout << arr[k] << " ";
            }
            cout << " (Tong: " << sum << ")" << endl;
        }
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int target;

    cout << "Nhap gia tri target: ";
    cin >> target;

    findSubarrays(arr, target);

    return 0;
}
