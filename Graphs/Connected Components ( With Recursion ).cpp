#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<bool> &visited, vector<vector<int>> &adj){
    if(visited[node])
        return;
    cout<<node<<" ";
    visited[node]=true;
    for(auto u : adj[node])
        dfs(u,visited,adj);

}

int main(){

    int n,e,i,j,u,v,cnt=0;
    scanf("%d%d",&n,&e);
    vector<vector<int>> adj(n);
    //creating adjacency list
    for(i=0;i<e;i++){
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> visited(n,false);
    //for counting connected components just increment cnt whenever dfs on 1 component ends
    for(i=0;i<n;i++){
        if(visited[i]==false){
            dfs(i,visited,adj);
            cnt++;
            cout<<"\n";
        }
    }
    cout<<cnt<<"\n";
}
