class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mxsum=nums[0],i,mx=nums[0];
        for(i=1;i<nums.size();i++){  // we are finding the max sum subarray ending at each ith position (having atleast one element)
            mxsum=mxsum+nums[i];
            if(nums[i]>mxsum)
                mxsum=nums[i];
            if(mxsum>mx)
                mx=mxsum;
        }
        return mx;
    }
};
