#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll merge(int a[], int l, int r, int m){
    vector<int> x(a+l, a+m+1);
    vector<int> y(a+m+1, a+r+1);
    ll i=0, j=0;
    ll cnt = 0;
    while(i < x.size() && j < y.size()){
        if(x[i] > y[j]){
        cnt += x.size()-i;
        a[l] = y[j];
        l++;
        j++;
        }else{
            a[l] = x[i];
            l++;
            i++;
        }
    }
    while(i < x.size()){
        a[l] = x[i];
        l++;
        i++;
    }
    while(j<y.size()){
        a[l] = y[j];
        l++;
        j++;
    }
    return cnt;
}

ll mergesort(int a[], int l, int r){
    if(l>=r) return 0;
    int m = (l+r)/2;
    ll ans = 0;
    ans += mergesort(a,l,m);
    ans += mergesort(a,m+1,r);
    ans += merge(a,l,r,m);
    return ans;
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0;i<n;i++){
        cin >> a[i];
    }
    cout << mergesort(a, 0,n-1);

}