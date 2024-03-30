class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // using sorting and comparing
        long long int i,smallestPos=1;
        sort(nums.begin(),nums.end());
        for(i=0;i<=nums.size()-1;i++){
            if(nums[i]>0){
                if(nums[i]==smallestPos)    // we found smallestPos then increase it by 1 and search for it
                    smallestPos++;
                else if(nums[i]>smallestPos)      // means we could't find this smallest positive smallestPos
                    break;
                                // NOTE: if(nums[i]!=smallestPos&&nums[i]<smallestPos) then there is a chance we can find smallestPos ex: -3 -2 0 1 2 2 2 3 4 
            }
        }
        return smallestPos;
    }
};

// OLDER SOLUTION : BETTER ONE
/*
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int miss=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==miss) miss++;
        }
        return miss;
    }
};
*/
