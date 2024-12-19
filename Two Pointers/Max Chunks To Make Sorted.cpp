class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        // we will use two pointers left and right &  whenever left and right pointers will meet
        // then a valid chunk (segment) that we con sort independently found ending at left (or right)
        int n=arr.size(),left,right=0,chunks=0;

        // HERE we can use each element as an index as well since they are unique and from 0 to n-1
        for(left=0;left<=n-1;left++){

            // TO MAKE this chubnk/segment separate for sorting
            // we STRECTH the segment by moving the right pointer UPTO
            // where the current element would go after sorting
            right=max(right,arr[left]);
            
            if(right==left)
                chunks++;
        }
        return chunks;
    }
};
