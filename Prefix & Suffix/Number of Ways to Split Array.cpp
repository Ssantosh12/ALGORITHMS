class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        // we will use prefix and suffix sum arrays for this problem
        int i,n=nums.size(),vSplits=0;
        long long int prefix[n],suffix[n];

        // store the prefix sums in array
        prefix[0]=nums[0];
        for(i=1;i<=n-1;i++)
            prefix[i]=prefix[i-1]+nums[i];

        // store the suffix sums in array
        suffix[n-1]=nums[n-1];
        for(i=n-2;i>=0;i--)
            suffix[i]=suffix[i+1]+nums[i];

        for(i=0;i<n-1;i++){
            if(prefix[i]>=suffix[i+1])
                vSplits++;
        }
        return vSplits;
    }
};
