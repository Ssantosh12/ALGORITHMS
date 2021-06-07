class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        //mlogn solution, can be optimised further
        //for each row we are gonna use binary search concept 
        int i,j,left,right,cnt=0,mid;
        for(i=0;i<grid.size();i++){
            left=-1;
            right=grid[i].size()-1;
            //we have to find index of last positive number
            while(left!=right){
                mid=left+right;
                if(mid&1)
                    mid++;
                mid=mid/2;
                if(grid[i][mid]<0)
                    right=mid-1;
                else left=mid;
            }
            cnt=cnt+(grid[i].size()-(left+1));
        }
        return cnt;
    }
};
