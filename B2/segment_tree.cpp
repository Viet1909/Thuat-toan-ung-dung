#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m, s, t;
bool visited[1001];
vector<int> ke[1001];
int parent[1001];

void bfs(int u){
    queue<int> q;
    q.push(u);
    visited[u]=true;
    while(!q.empty()){
        int v = q.front; q.pop();
        for(int x:ke[v]){
            if(!visited[x]){
                parent[x]=v;
                visited[x]=true;
                q.push(x);
            }
        }
    }
}

void inp(){
    cin >>n >> m>> s >> t;
    for(int i=1;i<=m;i++){
        int x,y;
        cin >> x >> y;
        ke[x].push_back(y);
    }
    for(int i = 1;i<=n;i++) sort(ke[i].begin(), ke[i].end());
    memset(visited, false, sizeof(visited));
    bfs(s);
    if(!visited[t]){
        cout << -1;
    }else{
        vector<int> path;
        while(t!=s){
            path.push_back(t);
            t = parent[t];
        }
        for(int x:path){
            cout << x << " ";
        }
    }
}
int main(){
    inp();
}