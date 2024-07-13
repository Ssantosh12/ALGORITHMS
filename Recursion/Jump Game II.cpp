class Solution {
public:
    // subproblem : minimum jumps to reach from ith step to (n-1)th step
    int minJumpsToReachLast(int step, vector<int> &nums){
      
        // base case : when we reach (n-1)th step OR
        // we reach a step from where we cannot move forward
        if(step==(nums.size()-1))
            return 0;   // 0 jumps required as we have reached (n-1)th step
        else if(nums[step]==0)
            return 1e4;   // infinite jumps required as it is impossible to reach (n-1)th step

        // transition : from current state/subprobelm return the minimum of all the choices we can take
        int stateMinChoice=1e4;
        for(int i=1;i<=nums[step]&&step+i<=(nums.size()-1);i++){
            stateMinChoice=min(stateMinChoice,1+minJumpsToReachLast(step+i,nums));  // NOTE: using stateMinChoice default max value as INT_MAX gives Runtime Error as in min(result1,result2)
                                                                                    // both result1 and result2 must be upto INT_MAX but above we added 1 to some step which returned INT_MAX
        }
        
        return stateMinChoice;
    }
    
    int jump(vector<int>& nums) {
         return minJumpsToReachLast(0,nums);
    }
};
