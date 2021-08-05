class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //for this problem we create an array which contains the max length 
        // of increasing subsequence upto that posn
        int i,j,mx=1;
        vector<int> mxlen(nums.size(),1);
        for(i=1;i<nums.size();i++){
            for(j=i-1;j>=0;j--){
                if(nums[j]<nums[i]){
                    mxlen[i]=max(mxlen[i],mxlen[j]+1);
                    mx=max(mx,mxlen[i]);
                }
            }
        }
        return mx;
    }
};
