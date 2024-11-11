class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        
        int i,n=nums.size(),left=0,right=1,incLen=1,maxK=0;
        
        int arr[n];
        
        /*
        Using Two Pointers Left and Right:
        1. Right pointer keeps moving towards right until it is strictly increasing and store this ongoing increasing length in some variable. 
        2. When strictly increasing pattern ends, then we move the left pointer towards right one by one 
           storing the counted increasing length at each 'left' position in array, 
           and since we are moving right leaving some increasing elements, for next forward positions we store 1 less length than previous.
        */
        while(right<=n-1){
            if(nums[right]>nums[right-1]){
                incLen++;
            }
            else{
                while(left<=right-1){
                    arr[left]=incLen;
                    incLen--;
                    left++;
                }
                incLen=1;
            }
            
            right++;
            
            if(right==n){
                while(left<=right-1){
                    arr[left]=incLen;
                    incLen--;
                    left++;
                }
            }
        }
        
        /*
        1. For each increasing length stored in array at 'i'th position, if length store at 'i+(arr[i])'th postion is greater than equal to it, 
           then this length arr[i] is a valid candidate length and we compare it with current maxK, i.e 𝘮𝘢𝘹𝘬=𝘮𝘢𝘹(𝘮𝘢𝘹𝘬, 𝘢𝘳𝘳[𝘪])
        2. Any even increasing length stored at any ith position can be divided in half which also gives a valid candidate length of (arr[i]/2)
           Lastly result is the maximum of these possible increasing length candidates.
        */
        
        for(i=0;i<=n-1;i++){
            if(!(arr[i]&1)){
                maxK=max(maxK,arr[i]/2);
            }
            if(i+arr[i]<=n-1&&arr[i]<=arr[i+arr[i]]){
                maxK=max(maxK,arr[i]);
            }
        }
        return maxK;
    }
};
