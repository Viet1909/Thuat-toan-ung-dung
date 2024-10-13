#include<bits/stdc++.h>
using namespace std;
const int Max=1e6+5;
int n;
int A[Max];
int M[20][Max];
int Q,x,y;
int sum;
void preCompute(){
    for(int i=0;i<n;i++){
        M[0][i]=i;
    }
    for(int i = 1 ; (1<<i) <= n ; i++ ){
        for(int j=0;j+(1<<i)-1<n;j++){
            if(A[M[i-1][j]]<A[M[i-1][j+(1<<(i-1))]]){
                M[i][j]=M[i-1][j];
            } else M[i][j] = M[i-1][j+(1<<(i-1))];
        }
    }
}
void quan_dai_be(){
    cin >> Q;
    int k;
    for(int i=0;i<Q;i++){
        cin >> x >>y;
        k = log2(y - x + 1);
    if(A[M[k][x]]<A[M[k][y - (1 << k)+1]]){
        sum = sum + A[M[k][x]];
    } else sum = sum + A[M[k][y - (1 << k)+1]];
}
cout << sum;
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++) cin >> A[i];
    preCompute();
    quan_dai_be();
    }
