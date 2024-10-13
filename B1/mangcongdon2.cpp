#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> createPrefixSum(const vector<vector<int>> & arr){
    int rows = arr.size();
    int cols = arr[0].size();

vector<vector<int>> prefixSum(rows, vector<int>(cols, 0));

for(int i=0;i<rows;i++){
    for(int j=0;j<cols;j++){
        int current = arr[i][j];
        int top = (i>0) ? prefixSum[i-1][j] : 0;
        int left = (j>0) ? prefixSum[i][j-1] : 0;
        int topLeft = (i>0 && j>0) ? prefixSum[i-1][j-1] : 0;

        prefixSum[i][j] = current + top + left - topLeft;
    }
}
return prefixSum;
}

int querySum(const vector<vector<int>> & prefixSum, int x1, int y1, int x2, int y2){
    int total = prefixSum[x2][y2];
    int top = (x1>0) ? prefixSum[x1-1][y2] : 0;
    int left = (y1>0) ? prefixSum[x2][y1-1] : 0;
    int topLeft = (x1>0 && y1>0) ? prefixSum[x1-1][y1-1] : 0;

    return total - top - left + topLeft;
}

int main(){
    vector<vector<int>> arr = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    vector<vector<int>> prefixSum = createPrefixSum(arr);

    cout << "mang cong don:" << endl;
    for(const auto& row : prefixSum) {
        for(int val : row){
            cout << val << " ";
        }
        cout << endl;
    }
    int result = querySum(prefixSum, 1, 1, 2, 2);
    cout << "tong cac phan tu tu (1,1) den (2,2): "<< result << endl;
}