class Solution {
public:
    void sortColors(vector<int>& nums) {
        // we will use two pointers, left pointer for '0' and right pointer for '1'
        // whenever we encounter '0', we update the nums[left] = 0 & pointer for '1' moves one position to right,
        // because starting position where segment of 0's and 1's meet is common for both
        // so whenever we say nums[left]=0 then starting posn of segment of 1 is being taken by 0
        // so we increase its size by one from the rightmost side of segment by saying nums[right]=1
        int i,n=nums.size(),left=0,right=0;
        
        for(i=0;i<=n-1;i++){
            if(nums[i]==0){
                if(left!=right){   // means some 1 have been found
                    nums[left]=0;
                    nums[right]=1;
                }
                else{    // means no 1 has been found till now
                    nums[left]=0;
                }
                left++;
                right++;
            }
            else if(nums[i]==1){
                nums[right]=1;
                right++;
            }
        }
        
        // adding 2 to the end of array
        while(right<=n-1){
            nums[right]=2;
            right++;
        }
    }
};
