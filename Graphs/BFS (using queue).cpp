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
    //now we do bfs on the graph using queue
    queue<int> q;
    //we insert the initial node 0 in the queue to start bfs
    q.push(0);
    while(!q.empty()){
        if(visited[q.front()]==false){  //here we only print the node value if it unvisited
             cout<<q.front()<<" ";
             visited[q.front()]=true;
        }
        for(auto u: adj[q.front()]){
            if(visited[u]==false){
                q.push(u);
            }
        }
        q.pop();
    }
}
