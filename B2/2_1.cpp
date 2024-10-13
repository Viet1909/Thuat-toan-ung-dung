// interger linear equation
// cho n so nguyen duong a1, a2, ... an
// Tinh so nghiem nguyen duong cua pt: a1X1 + a2X2 +... + anXn = M
#include<bits/stdc++.h>
#define MAX 10005
using namespace std;

int n, M;
int f = 0, res = 0;
int a[MAX];
int t[MAX];
int X[MAX];
void Try( int k){
	for(int v = 1; v <= ( ( M - f - (t[n]-t[k]) )/a[k] ); v++){
		X[k] = v;
		f += a[k] * X[k];
		if(k == n){
			if( f == M){
				res += 1;
			}
		} else{
		Try( k + 1);
		}
		f -= X[k] * a[k];
	}
	
}
int main(){
	cin >> n >> M;
	for (int i = 1 ; i <= n; i++){
		cin >> a[i];
		t[i] = t[i-1] + a[i];
	}
	Try(1);
	cout << res;
	return 0;
}