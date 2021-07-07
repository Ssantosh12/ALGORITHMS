#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n,e,i,u,v,cnt=0,node,curr;
 
    scanf("%d%d",&n,&e);
 
    vector<vector<int>> adjvc(n);
    vector<bool> visited(n,false);
    stack<int> stk;
    vector<int> ans;
 
    //first we are going to create an adjacency list
    for(i=0;i<e;i++){
        scanf("%d%d",&u,&v);
        u--;
        v--;
        adjvc[u].push_back(v);
        adjvc[v].push_back(u);
    }
 
    //now for every node that is not visited , we are going to run dfs from that node
    for(node=0;node<n;node++){
        if(visited[node]==false){
            stk.push(node);
            visited[node]=true;
            
            while(!stk.empty()){
                curr=stk.top();
                if(!adjvc[curr].empty()){
                    stk.push(adjvc[curr].back());
 
                    if(visited[adjvc[curr].back()]==false){
                        visited[adjvc[curr].back()]=true;
                        
                    }
 
                    adjvc[curr].pop_back();
                }
                else
                    stk.pop();
 
            }
            // counting each component
            cnt++;
        }
    }
 
    printf("%d\n",cnt);
}
