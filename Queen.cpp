#include<bits/stdc++.h>
using namespace std;
//cheo xuong i-j+n
//cheo len i+j-1
int cot[100], N, d1[100], d2[100], x[100];

int in(){
    for(int i=1;i<=N;i++){
        cout << "con hau nam o hang thu" << i << " cot " << x[i];
        cout << endl;
    }
}

void Try(int i){
    for(int j = 1;j < N;j++){
        if(cot[j]==1 && d1[i-j+N]==1 && d2[i+j-1]==1){
            x[i] = j;
            cot[j]=0;  d1[i-j+N]=0; d2[i+j-1]=0;
            if(j==N) in();
            else Try(i+1);
            cot[j]=1;  d1[i-j+N]=1;  d2[i+j-1]=1;
        }
    }
}

int main(){
    cin >> N;
    for(int i=1; i<=99;i++){
        cot[i] = d1[i] = d2[i] = 1;
    }
    Try(1);
}