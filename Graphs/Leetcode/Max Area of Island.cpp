class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int i,j,cnt,mx=0,n=grid.size(),m=grid[0].size();
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(grid[i][j]==1){
                    cnt=0;
                    dfs(i,j,grid,n,m,cnt);
                    if(cnt>mx)
                        mx=cnt;
                }
            }
        }
        return mx;
        
    }
    
     void dfs(int i,int j,vector<vector<int>> &grid,int n,int m, int &cnt){  //NOTE: we use the given matrix as both the adjacency list and the visited array
        if(i<0||i>(n-1)||j<0||j>(m-1)||grid[i][j]!=1)
            return;
        cnt++; 
        grid[i][j]=0;
        //now we call dfs on this node's neighbours
        dfs(i,j-1,grid,n,m,cnt);
        dfs(i,j+1,grid,n,m,cnt);
        dfs(i-1,j,grid,n,m,cnt);
        dfs(i+1,j,grid,n,m,cnt); 
    }
    
};
