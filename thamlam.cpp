#include<bits/stdc++.h>
using namespace std;

int cnt = 0;
int n;
int a[9];

int main(){
    cin >> n;
    for(int i = 0;i<=9;i++){
        cin >> a[i];
    }
    for(int i = 9;i>=0;i--){
        if(n / a[i] != 0){
            cnt += (n/a[i]);
            n = n % a[i];
        }
    }
    cout << cnt;
}