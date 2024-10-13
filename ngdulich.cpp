#include<bits/stdc++.h>
using namespace std;
const int  MAX = 1e6;

int n;
int A[105][105], x[100];
bool go[105];
int d = 0, ans = INT_MAX, Amin = INT_MAX;

// bool check(int i, int j){
//     if(A[i][j] != A[j][i]) return false;
//     if(A[i][i]!=0 || A[j][j] !=0 ) return false;
// }

void Try(int i){
    for(int j = 1; j<=n;j++){
        if(go[j] == false){
                x[i] = j;
                go[j] = true; 
                d += A[x[i-1]][x[i]]; 
                if(i==n) {
                    ans = min(ans, d + A[x[n]][1]);
                }
                else if(d + (n-i+1) * Amin < ans){ // can
                    Try(i+1);
                }
                //backtrack
                go[j] = false;
                d -= A[x[i-1]][x[i]];
        }
    }
}

int main(){
    cin >> n;
    for(int i = 1; i<=n;i++){
        for(int j = 1;j<=n;j++){
            cin >> A[i][j];
            if(A[i][j]!=0) Amin = min(Amin, A[i][j]);
        }
    }
    x[1] = 1;
    go[1] = true; 
    Try(2);
    cout << ans;
    return 0;
}