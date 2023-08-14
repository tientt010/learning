#include<bits/stdc++.h>

using namespace std;
int n,m;
vector<int>adj[1001];
bool visited[1001];

void inp(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(visited,false,sizeof(visited));
}

//thuật toán tìm kiếm theo chiều sâu (DFS)
void dfs(int u){
    cout<<u<<" ";
    visited[u]=true;
    for(int v:adj[u]){
        if(!visited[v]){
            dfs(v);
        }
    }
}

//thuật toán tìm kiếm theo chiều rộng (BFS)
void bfs(int u){
    queue<int> q;
    q.push(u);
    visited[u]=true;
    while(!q.empty()){
        int v=q.front();
        q.pop();
        cout<<v<<" ";
        for(int x:adj[v]){
            if(!visited[x]){
                q.push(x);
                visited[x]=true;
            }
        }
    }
}

int main(){
    inp();
    dfs(1);
    //bfs(1);
}