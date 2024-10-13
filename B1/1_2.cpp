#include<bits/stdc++.h>
using namespace std;

int dx[] = {-1,0,0,1};
int dy[] = {0,-1,1,0};
int a[1000][1000];
int n,m,r,c;
int d[1000][1000];
bool ok = false;

void bfs(int i, int j){
    queue<pair<int, int>> q;
    q.push({i,j});
    a[i][j]=1;
    d[i][j]=0;
    while (!q.empty()){
        pair<int, int> top = q.front(); q.pop();
        for(int k = 0;k<4;k++){
            int i1 = top.first + dx[k];
            int j1 = top.second + dy[k];
            if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] != 1){
                d[i1][j1] = d[top.first][top.second] + 1;
                q.push({i1, j1});
                a[i1][j1] = 1;
                if(i1==1 || i1==n || j1==1 || j1==m){
                    cout <<d[i1][j1]+1;
                    ok = true;
                    return;
                }
            }
        }
        
    }
}

void inp(){
    cin >> n >> m >> r >>c;
    for(int i=1; i<=n; i++){
        for(int j=1;j<=m;j++) cin >> a[i][j];
    }
    memset(d, 0, sizeof(d));
    bfs(r,c);
    if(!ok) cout << -1;
}

int main(){
    inp();
    return 0;
}
