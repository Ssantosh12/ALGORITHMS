class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i,sum=0,mx;
        mx=nums[0];
      //learning from errichto's tutorial videos
      
        for(i=0;i<nums.size();i++){
            sum=sum+nums[i];
            if(sum>mx)
                mx=sum;
            if(sum<0)
                sum=0;
        }
        return mx;
    }
};
