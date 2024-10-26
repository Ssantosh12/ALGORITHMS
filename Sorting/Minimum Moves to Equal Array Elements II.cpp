class Solution {
public:
    int minMoves2(vector<int>& nums) {
        // sort the array and change each element to the middle element (median) of the sorted array
        int median,i,ops=0,n=nums.size();
        sort(nums.begin(),nums.end());
        
        median=nums[n/2];  // when there are two medians, any of them can be chosen
        for(i=0;i<=n-1;i++){
            ops+=abs(median-nums[i]);
        }
        
        return ops;
    }
};

// OLD SOLUTION
/*
class Solution {
public:
    int minMoves2(vector<int>& nums) {
      
      //here we need to make all array elements equal in minimum total moves(one move is increment or decrement by 1 )
      //we sort the array, the most beneficial for all elements will be to change into midddle most element 
      //in case of even no. of elements , any of the two middle element will work
      //similar thinking in other similar but more complex problem (hackwithinfy problem 2, where we needed to make atleast k elements equal in least cost)
      
        long long int ind,i,cnt=0,diff;
        sort(nums.begin(),nums.end());
        ind=(nums.size())/2;
        for(i=0;i<nums.size();i++){
            cnt=cnt+llabs(nums[ind]-nums[i]);
        }
        return cnt;
    }
};
*/
