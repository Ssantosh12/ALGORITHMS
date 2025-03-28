class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        // subproblem/state defintion(dp[i]): max number of jumps we can make
        // to reach from ith index to last index, -1 means we cannot reach last index

        int i,j,n=nums.size();
        int dp[n];
        for(i=0;i<=n-1;i++)
            dp[i]=-1;

        // using iterative dp
        for(i=n-1;i>=0;i--){
            if(i==n-1){
                // base case
                dp[i]=0;
            }
            else{
                // transition: of all choices , choose which give max no. of jumps
                // NOTE: of all choices we can make from ith index to jump to (to jth index)
                // first check where we jump to (jth index), is it reachable (i.e abs(nums[j]-nums[i])<=target)
                // and if we can really reach the last index from it or not (i.e dp[j]=-1 means we can't)
                for(j=i+1;j<=n-1;j++){
                    if(abs(nums[j]-nums[i])<=target&&dp[j]!=-1){
                        dp[i]=max(dp[i],1+dp[j]);
                    }
                }
            }
        }
        return dp[0];
    }
};
