class Solution {
public:
    // state definition: minimum difference between max and min element
    // of the given subsegment/subproblem contained within left and right pointers
    // with number of operations that can be done is k
    int minDiffOfSegmentAfterKOps(int left, int right, vector<int> &nums, int k){
        // base case : when k is 0 , then no ops is left, so return current segment max min diff
        if(k==0){
            return nums[right]-nums[left];
        }
      
        // transition: of all choices from here , choose which gives the minimum difference
        return min(minDiffOfSegmentAfterKOps(left+1,right,nums,k-1), minDiffOfSegmentAfterKOps(left,right-1,nums,k-1));
    }

    int minDifference(vector<int>& nums) {
        int n=nums.size(),ans;

        if(n==1||n==2||n==3||n==4)
            return 0;

        sort(nums.begin(),nums.end());    
        ans = minDiffOfSegmentAfterKOps(0,n-1,nums,3);
        return ans;
    }
};
