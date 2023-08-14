#include<bits/stdc++.h>

//Chuyển đổi giữa các ma trận
using namespace std;

int main(){
//Cho danh sách cạnh chuyển đổi vê ma trận kề và danh sách kề
    //Ma trận kề, dùng khi số đỉnh nhỏ
    int n,m;
    cin>>n>>m;
    int a[101][101];
    for(int i=0;i<m;i++){
        int x,y ;
        cin>>x>>y;
        a[x][y]=1;
        a[y][x]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    //Danh sách kề, hữu dụng
    vector<int>adj[1001];
    for(int i=0;i<m;i++){
        int x,y ;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x); 
    }
    for(int i=1;i<=n;i++){
        cout<<i<<" : ";
        for(int p:adj[i])cout<<p<<" ";
        cout<<endl;
    }
//Cho danh sách kề chuyển đổi về ma trận kề
    cin>>n;
    cin.ignore();
    for(int i=1;i<=n;i++){
        string s,num;
        getline(cin,s);
        stringstream ss(s);
        while(ss>>num){
            a[i][stoi(num)]=1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}