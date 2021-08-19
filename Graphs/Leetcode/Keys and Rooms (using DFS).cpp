class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        //we run simple dfs (Here time and space complexity is too much) 
        int n=rooms.size(),i,j,cnd=1;
        vector<bool> visited(n,false);
       // visited[0]=true;
        dfs(0,rooms,visited);
        for(i=0;i<n;i++){
            if(visited[i]==false){
                cnd=0;
                break;
            }
        }
        if(cnd==1)
            return true;
        else return false;
    }
    void dfs(int node,vector<vector<int>> adj, vector<bool> &visited){
        if(visited[node])
            return;
        visited[node]=true;
        for(auto x: adj[node]){
            //if(visited[node]==false)
                dfs(x,adj,visited);
        }
    }
};
