#include<bits/stdc++.h>

using namespace std;
//thuật toán tìm đường đi từ s đến t
//trong trường hợp đồ thị không có trọng số thì đường đi theo bfs sẽ là ngắn nhất
int n,m,s,t;
vector<int> adj[1001];
bool visited[1001];
int parent[1001];
void dfs(int u){
    visited[u]=true;
    for(auto v:adj[u]){
        if(!visited[v]){
            parent[v]=u;
            dfs(v);
        }
    }
}

void bfs(int u){
    queue<int> q;
    q.push(u);
    visited[u]=true;
    while(!q.empty()){
        int v=q.front();
        q.pop();
        //cout<<v<<" ";
        for(int x:adj[v]){
            if(!visited[x]){
                q.push(x);
                parent[x]=v;
                visited[x]=true;
            }
        }
    }
}

void Path(int s,int t){
    memset(visited,false,sizeof(visited));
    memset(parent,0,sizeof(parent));
    bfs(s);
    //dfs(s);
    if(!visited[t]){
        cout<<"khong co duong di tu "<<s<<" den "<<t;
    }else{
        vector<int>ans;
        int x=t;
        while(x!=s){
            ans.push_back(x);
            x=parent[x];
        }
        ans.push_back(x);
        cout<<"duong di tu "<<s<<" den "<<t<<" la : ";
        for(int i=ans.size()-1;i>=0;i--)cout<<ans[i]<<" ";
    }
}

int main(){
    cin>>n>>m;
    for(int i=0;i<m ;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cin>>s>>t;
    Path(s,t);
}