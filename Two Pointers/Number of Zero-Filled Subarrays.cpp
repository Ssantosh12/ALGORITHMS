class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long int left=0,right=0,count=0,sublen;
        while(right<=nums.size()-1){
            // we have to fix left and right pointers to the subarrays with all 0s
            // right pointer will move linearly/incrementely to the right
            // if nums[right]!=0 and nums[left]==0, valid subarray is from left to (right-1)
            // if nums[right]==0 and nums[left]!=0, we fix left =right as it is the starting of one of the valid subarrays
            
            if(nums[right]==0){
                if(nums[left]!=0)
                    left=right;   // left points to starting of one valid subarray
                if(right==nums.size()-1){
                    sublen=right-left+1;
                    count+=(sublen*(sublen+1))/2;
                }
            }
            else{
                if(nums[left]==0){
                    sublen=(right-1)-left+1;
                    count+=(sublen*(sublen+1))/2;
                    left=right;   // left now points to non-zero
                }
            }
            right++;
        }
        return count;
    }
};
