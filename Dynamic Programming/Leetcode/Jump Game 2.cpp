class Solution {
public:
  //prob- reach nth stair in min jumps where nums[i] denotes the max jump capacity from i
  //thinking is based on stair problem, just remember the basics from stair problem and think of smallest subproblem that can be solved
  // thinking of that smallest subproblem makes the solution for the entire problem (this is the thinking required for dp)
    int jump(vector<int>& nums) {
        int i,j,cost,mn;
        int jump[nums.size()];
        jump[0]=0;
        //jump[1]=1;
        for(i=1;i<nums.size();i++){
            mn=INT_MAX;
            for(j=0;j<i;j++){
                if((j+nums[j])>=i&&(jump[j]+1)<mn)
                    mn=jump[j]+1;
            }
            jump[i]=mn;
        }
        return jump[nums.size()-1];
    }
};
