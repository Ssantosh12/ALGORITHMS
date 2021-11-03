class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]==1)
            return 0;   // if the starting position is itself an obstacle then it cannot move at all and cannot reach any other cell
      
        int i,j,m=obstacleGrid.size(),n=obstacleGrid[0].size();
        
        vector<vector<int>> grid(m,vector<int> (n,0));
        grid[0][0]=1;
        i=0; j=1;
        while(j<n&&obstacleGrid[i][j]!=1){   //pay attention in giving conditions in While loops, in multiple condtions given the 1st condition is checked first
                                             //so make sure that the 1st condition is the most necessary and valid (like i<m and j<n will come first here )
            grid[i][j]=1;
            j++;
    
        }
        i=1; j=0;
        while(i<m&&obstacleGrid[i][j]!=1){
            grid[i][j]=1;
            i++;
            
        }
        for(i=1;i<m;i++){
            for(j=1;j<n;j++){
                //we look at the cells from which we can reach this cell
                //we can reach this cell from the upper or the left cell
                //we can only reach this cell if it is not an obstacle
                if(obstacleGrid[i][j]!=1)
                    grid[i][j]=grid[i-1][j]+grid[i][j-1];
                
            }
        }
        
        return grid[m-1][n-1];
    }
};
