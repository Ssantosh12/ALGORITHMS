class Solution {
public:
    //subproblem/state definition: maximum number of jumps we can make to reach from ith index to 'n-1'th
    int maxJumpsToReachFromIthToLast(int index, vector<int> &nums, int target){
        // base case
        if(index==nums.size()-1)
            return 0;
        
        // transition: of all choices , choose which gives the max number of jumps
        int maxJumps=-1,jumps;
        for(int i=index+1;i<=nums.size()-1;i++){

            // NOTE: of all choices we can make from ith index to jump to (to jth index)
            // first check where we jump to (jth index), is it reachable (i.e abs(nums[j]-nums[i])<=target)
            // and if we can really reach the last index from it or not (i.e dp[j]=-1 means we can't)
            if(nums[i]-nums[index]>=-target&&nums[i]-nums[index]<=target){
                jumps=maxJumpsToReachFromIthToLast(i,nums,target);
                if(jumps!=-1)
                    maxJumps=max(maxJumps,1+ jumps);
            }
        }
        return maxJumps;
    }

    int maximumJumps(vector<int>& nums, int target) {
        return maxJumpsToReachFromIthToLast(0,nums,target);
    }
};
