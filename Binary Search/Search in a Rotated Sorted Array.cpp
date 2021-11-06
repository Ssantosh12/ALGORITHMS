class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ind=-1,left=0,right=nums.size()-1,mid;
        while(left<=right){
            mid=(left+right)/2;
            if(nums[mid]==target){
                ind=mid;
                break;
            }
             
           //we just have to decide which half of the array we will go to and which half we cut or decline (basic idea of binary search)
             
            if(nums[mid]>nums[right]){
                if(nums[mid]<target)
                    left=mid+1;
                else{
                    if(nums[left]<=target)
                        right=mid-1;
                    else
                        left=mid+1;
                }
            }
            else{
                
                if(nums[mid]<target){
                    if(nums[right]>=target)
                        left=mid+1;
                    else 
                        right=mid-1;
                }
                else
                    right=mid-1;
                
            }
        }
        return ind;
    }
};
