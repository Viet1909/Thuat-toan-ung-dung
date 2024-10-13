#include <bits/stdc++.h>

using namespace std;

// Hàm khởi tạo mảng cộng dồn
vector<int> createPrefixSumArray(const vector<int>& arr) {
    int n = arr.size();
    vector<int> prefixSum(n);
    prefixSum[0] = arr[0]; // Giá trị đầu tiên của mảng cộng dồn bằng giá trị đầu tiên của mảng gốc
    for (int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i - 1] + arr[i]; // Cộng dồn giá trị từ mảng gốc vào mảng cộng dồn
    }
    return prefixSum;
}

// Hàm tính tổng các phần tử từ chỉ số l đến r
int rangeSum(const vector<int>& prefixSum, int l, int r) {
    if (l == 0) {
        return prefixSum[r]; // Nếu l = 0 thì tổng là giá trị tại chỉ số r
    } else {
        return prefixSum[r] - prefixSum[l - 1]; // Tổng là hiệu của giá trị tại r và l-1
    }
}

int main() {
    // Mảng gốc
    vector<int> arr = {2, 4, 5, 3, 6};

    // Tạo mảng cộng dồn
    vector<int> prefixSum = createPrefixSumArray(arr);

    // Nhập chỉ số l và r để tính tổng từ arr[l] đến arr[r]
    int l, r;
    cout << "Nhap chi so l va r (0-based index): ";
    cin >> l >> r;

    // Kiểm tra chỉ số hợp lệ
    if (l < 0 || r >= arr.size() || l > r) {
        cout << "Chi so khong hop le!" << endl;
        return 1;
    }

    // Tính và in tổng các phần tử từ chỉ số l đến r
    cout << "Tong tu chi so " << l << " den " << r << " la: " << rangeSum(prefixSum, l, r) << endl;

    return 0;
}
