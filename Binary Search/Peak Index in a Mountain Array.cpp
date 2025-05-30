class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        // we will use binary search on answer for this problem (Of Type NNNYNNN)
        // we use low,mid,high as indices for the array
        int i,n=arr.size(),low,mid,high;

        // using binary search we will pick a 'mid' index element for checking
        // we will compare it its right adjacent element that is on mid+1 index
        //NOTE: there is always a right side element present as even if high=low+1
        // or low and high are adajacent then mid will land on low
        low=0;
        high=n-1;
        while(low<high){
            mid=low+(high-low)/2;

            // Checking: comapre the element at 'mid' with its right side element at "mid+1"

            // when right ele<current ele at mid, answer lies on left part and mid is a candidate
            if(arr[mid+1]<arr[mid])
                high=mid;
            // when right ele>current ele at mid, answer lies on right part and mid is NOT a candidate
            else low=mid+1;
        }
        return low;
    }
};
