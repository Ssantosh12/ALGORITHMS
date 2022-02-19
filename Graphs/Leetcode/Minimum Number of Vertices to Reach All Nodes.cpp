class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        int i,j;
        //first we create and adjacency  list to store the graph in proper usable manner
      // the idea is to take one node from each component but unlike from undirected graphs, here components
      // are directed so we will have to take only the root of each component
        vector<vector<int>> adj(n);
        for(i=0;i<edges.size();i++)
            adj[edges[i][0]].push_back(edges[i][1]);
        vector<bool> visited(n,false);
        vector<int> ans;
        vector<bool> vc(n,false);
        for(i=0;i<edges.size();i++){
            if(visited[edges[i][0]]==false){
                vc[edges[i][0]]=true;
                dfs(edges[i][0],adj,visited,vc);
            }
        }
        for(i=0;i<n;i++){
            if(vc[i])
                ans.push_back(i);
        }
        return ans;
        
    }
    void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited,vector<bool> &vc){
        if(visited[node]){
            vc[node]=false;
            return;
        }
        visited[node]=true;
        for(auto x: adj[node])
            dfs(x,adj,visited,vc);
    }
};
