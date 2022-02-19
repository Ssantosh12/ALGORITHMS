
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> path;
        path.push_back(0);
        travel(0,graph,path,ans);
        return ans;
    }
    
    void travel(int node, vector<vector<int>> &adj,vector<int> &path, vector<vector<int>>&ans)    {
    if(node==adj.size()-1){
        ans.push_back(path);
        return;
    }
    for(auto x: adj[node]){
        path.push_back(x);
        travel(x,adj,path,ans);
        path.pop_back();
    }
  }

    
};
