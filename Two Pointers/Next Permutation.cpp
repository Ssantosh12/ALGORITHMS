class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // we go from right to left to dind the 1st ith index
        // where in the right side of that index there is/are greater elements than it
        // TODO: a better solution with more comments

        int lastInd=0,i,j,n=nums.size(),ind,smallestGreater=100;
        bool greaterFound=false;
        for(i=n-1;i>=0;i--){
            for(j=i+1;j<=n-1;j++){
                if(nums[j]>nums[i]){
                    greaterFound=true;
                    smallestGreater=min(smallestGreater,nums[j]);
                }
            }
            if(greaterFound){
                for(j=i+1;j<=n-1;j++){
                    if(nums[j]==smallestGreater){
                        swap(nums[i],nums[j]);
                        break;
                    }
                }
                ind=i+1;
                break;
            }
        }
        
        if(greaterFound){
            sort(nums.begin()+ind,nums.end());
        }
        else{
            sort(nums.begin(),nums.end());
        }
    }
};
