#include <bits/stdc++.h>
using namespace std;

void dfs(int node,vector<bool> &visited, vector<vector<int>> &adj ){
    if(visited[node])
        return;
    cout<<node<<" ";
    visited[node]=true;
    for(auto x: adj[node]){
        dfs(x,visited,adj);
    }

}

int main(){
    int u,v,n,i,j,e,cnt=0;
    scanf("%d%d",&n,&e);
    vector<vector<int>> adj(n);
    for(i=0;i<e;i++){
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> visited(n,false);
    for(i=0;i<n;i++){
        if(visited[i]==false){
            dfs(i,visited,adj);
            cout<<"\n";
            cnt++;
        }
    }

    cout<<cnt<<"\n";
}
