#include <bits/stdc++.h>
using namespace std;

int main(){

    int u,v,e,n,i;
    scanf("%d%d",&n,&e);
    vector<vector<int>> adj(n);
    for(i=0;i<e;i++){
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> visited(n,false);
    //now we gonna do bfs traversal using queue
    queue<int> q;
    q.push(0);
    visited[0]=true;
    //here the main thinking is if a node is pushed into the queue then it will be considered as visited
    //and also we push only the unvisited nodes into the queue
    while(!q.empty()){
        cout<<q.front()<<" ";
        for(auto x : adj[q.front()]){
             if(visited[x]==false){
                visited[x]=true;
                q.push(x);
             }
        }
        q.pop();
    }

}
