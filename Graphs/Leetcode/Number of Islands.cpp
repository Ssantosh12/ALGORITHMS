class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int i,j,cnt=0,n=grid.size(),m=grid[0].size();
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    dfs(i,j,grid,n,m);
                }
            }
        }
        return cnt;
    }
    void dfs(int i,int j,vector<vector<char>> &grid,int n,int m){   //NOTE: WE use the given matrix as both the adjacency list and the visited array that we use in normal dfs 
        if(i<0||i>(n-1)||j<0||j>(m-1)||grid[i][j]=='0'||grid[i][j]=='v')
            return;
        grid[i][j]='v';
        //now we call dfs on this node's neighbours
        dfs(i,j-1,grid,n,m);
        dfs(i,j+1,grid,n,m);
        dfs(i-1,j,grid,n,m);
        dfs(i+1,j,grid,n,m); 
    }
};
