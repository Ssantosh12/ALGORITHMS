class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        //using simple dfs
        int cnd=1,n=rooms.size(),i;
        vector<bool> visited(n,false);
        dfs(0,rooms,visited);
        for(i=0;i<n;i++){
            if(visited[i]==false)
                return false;
        }
        return true;
    }
    void dfs(int node,vector<vector<int>> &adj,vector<bool> &visited){ //NOTE: send adjacency list as a reference to the recursive function to reduce time and space complexity
        if(visited[node])
            return;
        visited[node]=true;
        for(auto x: adj[node])
            dfs(x,adj,visited);
    }
};
