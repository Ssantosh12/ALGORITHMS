class Solution {
  public:
    
    // state definition: check if there is a subsequence with sum 'target'
    // in set/array upto the ith index (or prefic of array upto ith index)
    bool isSubsetSumUptoIth(int index, vector<int> &arr, int target) {
        // base case
        if(target==0)
            return true;
        else if(index<0||target<0)
            return false;
        
        // transition: check if any of the two (take & not take) choices from here is true
        if(isSubsetSumUptoIth(index-1,arr,target-arr[index])||isSubsetSumUptoIth(index-1,arr,target))
            return true;
        
        return false;
    }
    
    
    bool isSubsetSum(vector<int>& arr, int target) {
        // code here
        return isSubsetSumUptoIth(arr.size()-1,arr,target);
    }
