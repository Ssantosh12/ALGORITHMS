#include <bits/stdc++.h>
using namespace std;

int main(){
    int i,j,node,cnt=0,u,v,n,e;
    scanf("%d%d",&n,&e);

    vector<vector<int>> adjvc(n);
    set<int> st;
    stack<int> stk;
    //creating adjacency matrix to store graph
    for(i=0;i<e;i++){
        scanf("%d%d",&u,&v);
        u--;
        v--;
        adjvc[u].push_back(v);
        adjvc[v].push_back(u);
    }

    //we use stack for dfs-> top node on stack is the current node being processed

    while(st.size()!=n){
        if(stk.empty()){
            for(node=0;node<n;node++){
                if(st.find(node)==st.end()){
                    stk.push(node);
                    st.insert(node);
                    break;
                }
            }
        }
        else{
            node=stk.top();
            if(adjvc[node].empty()){
                stk.pop();
                if(stk.empty())
                    cnt++;
            }
            else{
                stk.push(adjvc[node].back());
                st.insert(adjvc[node].back());
                adjvc[node].pop_back();
            }
        }
    }
    
    cnt++;  // cnt is incremented by 1 because the last component remained in it and loop exited before emptying the stack conataining this last component

    printf("%d\n",cnt);
}
