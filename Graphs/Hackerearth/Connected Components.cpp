#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,e,u,v,i,j,cnt=0,node,ele;  //my own first time implementation of dfs and finding connected components in graph, code is too lengthy
    scanf("%d%d",&n,&e);
    vector<deque<int>> adjlst(n);
    set<int> st;
    stack<int> stk;
    for(i=0;i<e;i++){
        scanf("%d%d",&u,&v);
        adjlst[u-1].push_back(v-1);
        adjlst[v-1].push_back(u-1);
    }
    node=0;
    while(!stk.empty()||st.size()!=n){
        if(!stk.empty()&&stk.top()!=node||stk.empty())
           stk.push(node);
        st.insert(node);
        //now we update node
        if(!adjlst[node].empty()){
            while(!adjlst[node].empty()&&st.find(adjlst[node][0])!=st.end())
                adjlst[node].pop_front();
           if(!adjlst[node].empty()){
            ele=adjlst[node][0];
            adjlst[node].pop_front();
            node=ele;
           }
        }
        else{
            stk.pop();
            if(!stk.empty())
                node=stk.top();
            else{
                cnt++;
                for(i=0;i<n;i++){
                    if(st.find(i)==st.end()){
                        node=i;
                        break;
                    }
                }
            }

        }
    }
    printf("%d\n",cnt);
}
