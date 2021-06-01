class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i,sum=0,mx;
        mx=nums[0];
        for(i=0;i<nums.size();i++){  //initial thinking of the problem
            sum=sum+nums[i];
            
            if(sum<nums[i])  //important to understand this line
                sum=nums[i];
            if(sum>mx)
                mx=sum;
           
        }
        return mx;
    }
};
