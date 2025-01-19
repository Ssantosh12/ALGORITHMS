class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // using prefix sum technique
        int i,n=nums.size(),subCount=0,prefixSum=0;

        // store frequency of each prefix sum
        map<int,int> prefixFreq;

        // we count number of subarrays with sum k ending at each ith index
        for(i=0;i<=n-1;i++){
            prefixSum+=nums[i];
            subCount+=prefixFreq[prefixSum-k];

            // edge case: when the current prefix sum is itself k
            if(prefixSum==k)
                subCount++;
            
            prefixFreq[prefixSum]++;
        }

        return subCount;
    }
};
