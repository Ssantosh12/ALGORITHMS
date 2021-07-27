#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int e,n,i,u,v,j,s,d=6;
        scanf("%d%d",&n,&e);
        vector<vector<int>> adj(n);
        for(i=0;i<e;i++){
            scanf("%d%d",&u,&v);
            adj[u-1].push_back(v-1);
            adj[v-1].push_back(u-1);
        }
        vector<bool> visited(n,false);
        vector<int> dist(n,-1);
        //now we gonna run a bfs to calculate distance of each node from the given starting node s
        scanf("%d",&s);
        s--;
        dist[s]=0;
        queue<int> q;
        q.push(s);
        visited[s]=true;
        while(!q.empty()){
            for(auto x: adj[q.front()]){
                if(visited[x]==false){
                    dist[x]=dist[q.front()]+6;
                    visited[x]=true;
                    q.push(x);
                }
            }
            q.pop();
        }
        for(i=0;i<n;i++){
             if(i!=s)
               printf("%d ",dist[i]);
        }
        cout<<"\n";
    }
}
