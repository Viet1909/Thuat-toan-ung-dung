// find x+y = Q (have Q)
#include <bits/stdc++.h>

using namespace std;

void findPairWithSum(const vector<int> & arr, int Q){
    int left = 0;
    int right = arr.size() - 1;

    while(left<right){
        int sum = arr[left] + arr[right];
         if(sum == Q){
                cout << "cap phan tu: (" << arr[left] << ", " << arr[right] << ")" << endl;
                left++;
                right--;
            }else if(sum < Q){
                left++;
            }else{
                right--;
            }
        }
    }

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    int Q;

    cout << "Nhap gia tri Q: ";
    cin >> Q;

    findPairWithSum(arr,Q);
    return 0;
}

