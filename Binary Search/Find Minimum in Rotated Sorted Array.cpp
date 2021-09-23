class Solution {
public:
    int findMin(vector<int>& nums) {       //similar as finding the 1st index of an element in sorted array(like lowerbound)
        int left=0,right=nums.size()-1,mid;
        while(left<right){
            mid=(left+right)/2;
            if(nums[mid]<nums[right])
                right=mid;
            
            else
                left=mid+1;
            
        }
        return nums[left];
    }
};
