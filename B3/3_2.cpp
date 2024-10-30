#include<bits/stdc++.h>
using namespace std;

bool check(int a[], int n, int c, int dis){
    int last_pos = a[0];
    int cnt = 1;
    for(int i = 1;i<n;i++){
        if(a[i] - last_pos >= dis){
            last_pos = a[i];
            cnt++;
            if(cnt == c) return true;
        }
    }
    return false;
}

int max_dis(int a[], int n, int c){
    int ans = -1;
    sort(a, a+n);
    int min = 0;
    int max = a[n-1] - a[0];
    int m = (max + min)/2;
    if(check(a, n, c, m)){
        ans = m;
        min = m+1;
    }
    else{
        max = m-1;
    }
}


int main(){
    int t;
    cin >> t;
    while(t--){
        int n,c;
        cin >> n >> c;
        int a[n];
        for(int i = 0;i < n;i++){
            cin >> a[i];
        }
        cout << max_dis(a,n,c);
    }
    return 0;
}