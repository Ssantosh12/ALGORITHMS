#include <bits/stdc++.h>
using namespace std;

int main(){
    int newnode,u,v,n,e,i,j,node;
    scanf("%d%d",&n,&e);
    vector<vector<int>> adjvc(n);
    for(i=0;i<e;i++){
        scanf("%d%d",&u,&v);
        adjvc[u].push_back(v);
        adjvc[v].push_back(u);
    }
    //now we traverse the graph using dfs without recursion and with recursion
    stack<int> stk;
    vector<bool> visited(n,false);
    node=0;
    stk.push(node);
    while(!stk.empty()){
        if(!visited[stk.top()]){
           printf("%d ",stk.top());  //print the current node
           visited[stk.top()]=true;
        }
        //now we check if this current node leads us to another node it is connected to
        if(!adjvc[stk.top()].empty()){
            newnode=adjvc[stk.top()].back();
            adjvc[stk.top()].pop_back();
            stk.push(newnode);
        }

        else stk.pop();
    }
}
