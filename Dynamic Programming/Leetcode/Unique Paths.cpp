class Solution {
public:
    int uniquePaths(int m, int n) {
        // same thinking applied in problem no of ways to reach nth stair
        //we create another grid which wiil store the no of ways to reach a cell
      
        int i,j;
        vector<vector<int>> grid(m,vector<int> (n));
        for(j=0;j<n;j++)
            grid[0][j]=1;
        for(i=1;i<m;i++)
            grid[i][0]=1;
        for(i=1;i<m;i++){
            for(j=1;j<n;j++){
                //we look at the cells from which we can reach this cell
                //we can reach this cell from the upper or the left cell
                //so  no. of ways we can reach this cell is sum of the no. of ways from which we can reach this cell
                grid[i][j]=grid[i-1][j]+grid[i][j-1];
            }
        }
        return grid[m-1][n-1];
    }
};
