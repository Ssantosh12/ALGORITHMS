class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // similar thinking just like dynamic programming state defintion
        // we store the max subarray sum ending at each ith position
        int i,n=nums.size(),maxSubSum=-1e4;
        int maxSubSumEndingIth[n];
        maxSubSumEndingIth[0]=nums[0];
        
        // max subarray sum ending at ith index is either
        // we add the current ith element to the max subarray sum ending at (i-1)th position
        // or the current element (nums[i]) is itself greater than maxSubSumEndingIth[i-1]+nums[i]
        // NOTE: we cannot skip ith element, as we have to find valid subarray not subsequence
        for(i=1;i<=n-1;i++){
            // we store the max subarray sum ending at ith in maxSubSumEndingIth array
            maxSubSumEndingIth[i]=max(maxSubSumEndingIth[i-1]+nums[i],nums[i]);
        }
        
        for(i=0;i<=n-1;i++){
            maxSubSum=max(maxSubSum, maxSubSumEndingIth[i]);
        }
        
        return maxSubSum;
    }
};
