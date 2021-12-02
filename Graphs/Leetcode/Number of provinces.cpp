class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        //we just have to count the no of connected componenets
        //only point to note here is that the graph has already been stored in an adjacency matrix instead of adjacency list
        int i,node,cnt=0,n=isConnected.size();
        vector<bool> visited(n,false);
        for(i=0;i<n;i++){
            if(visited[i]==false){
                cnt++;
                dfs(i,isConnected,visited,n);
            }
        }
        return cnt;
        
    }
    void dfs(int node,vector<vector<int>> &isConnected, vector<bool> &visited,int n){
        if(visited[node])  //if node has been visited return
            return;
        visited[node]=true;   //if not visited , mark it as visited
                              //and call dfs on its neighbours
        for(int i=0;i<n;i++){
            if(i!=node&&isConnected[node][i]==1)
                dfs(i,isConnected,visited,n);
        }
    }
};
