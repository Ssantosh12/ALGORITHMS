class Solution {
  public:
    int maximumSumSubarray(vector<int>& arr, int k) {
        // code here
        // using sliding window for subarray of size k
        long long int i,maxSubSum=0,currSubSum=0;
        
        for(i=0;i<=k-1;i++){
            currSubSum+=arr[i];
        }
        maxSubSum=currSubSum;
        
        // index i will go upto which k subarray of size k can generated
        for(i=1;i<=arr.size()-k;i++){
            // using sliding window to get each subarray sum
            currSubSum=currSubSum-arr[i-1]+arr[i+(k-1)];
            maxSubSum=max(maxSubSum,currSubSum);
        }
        return maxSubSum;
    }
};
