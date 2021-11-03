class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int i,j,m=grid.size(),n=grid[0].size();
        if(m==1&&n==1)
            return grid[0][0];
        //we will craete another matrix/ grid of same size which will store the max path sum for each cell
        vector<vector<int>> mat(m,vector<int> (n));
        mat[0][0]=grid[0][0];
        for(j=1;j<n;j++)
            mat[0][j]=mat[0][j-1]+grid[0][j];
        for(i=1;i<m;i++)
            mat[i][0]=mat[i-1][0]+grid[i][0];
        //for each cell we have two choices to reach it, we choose to reach this cell which gives the optimal results (i.e max sum upto that cell)
        for(i=1;i<m;i++){
            for(j=1;j<n;j++){
                //we store the max sum that each cell can have and other cells max sum are calculated with previous calculated sums
                // of cells from this cell can be reached ( we can reach cell[i][j] from cell[i-1][j] or cell[i][j-1])  
                mat[i][j]=grid[i][j]+min(mat[i-1][j],mat[i][j-1]);
            }
        }
        
        return mat[m-1][n-1];
    }
};
