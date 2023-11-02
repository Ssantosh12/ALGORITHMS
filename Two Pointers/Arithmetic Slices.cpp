class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        // to point at the current arithmetic subarray we use two pointer technique ,left and right
        int left=0,right=1,diff,apSubarray=0,subLength;
        
        while(right<=nums.size()-1){
            if(right==1)
                diff=nums[right]-nums[right-1];   // or diff=nums[right]-nums[left];
            else{
                // NOTE : any AP subarray of length subLength pointed by left and right pointers will also contain internal AP subarrays
                if(nums[right]-nums[right-1]!=diff){
                    subLength=(right-1)-left+1;
                    if(subLength>=3){
                        apSubarray+=(subLength*(subLength+1))/2-subLength-(subLength-1);
                    }
                    diff=nums[right]-nums[right-1];
                    left=right-1;
                }
                if(right==nums.size()-1){
                    subLength=right-left+1;
                    if(subLength>=3){
                        apSubarray+=(subLength*(subLength+1))/2-subLength-(subLength-1);
                    }
                }
            }
            right++;
        }
        return apSubarray;
    }
};


// REFER OTHER OLD SOLUTIONS for comparing and learning purposes, 1 of the old solutions is below :
/*
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        //we will store the lengths of all the arithmetic subarrays
        int sub=0,cnt=0,i;
        for(i=2;i<nums.size();i++){
            if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2]){
                if(sub==0)
                    sub=3;
                else sub++;
            }
            else{
                if(sub!=0)
                cnt=cnt+(sub*(sub+1))/2-(sub+(sub-1));
                sub=0;
            }
            if(i==nums.size()-1&&sub!=0)
                 cnt=cnt+(sub*(sub+1))/2-(sub+(sub-1));
        }
        return cnt;
    }
};
*/
