class Solution {
public:
    // TODO: this only works for small inputs, need better tie complexity solution
    // state defintion: minimum fibonacci numbers needed to reach from ith sum to target sum
    int minFibsToReachFromIth(int sum, vector<int> &fibNums, int k){
        if(sum==k)
            return 0;
        else if(sum>k)
            return 1e5; // treating 1e5 as infinity, not possible
        
        // transiton: we choose the min of all chices from here
        int minFibs=1e5;
        for(int i=0;i<=fibNums.size()-1;i++){
            minFibs=min(minFibs,1+ minFibsToReachFromIth(sum+fibNums[i],fibNums,k));
        }
        return minFibs;
    }
    
    
    int findMinFibonacciNumbers(int k) {
        // similar to minimum coins to reach target sum using given coins array
        // just we have to first store the array of fibonacci numbers that we will use
        
        vector<int> fibNums;
        fibNums.push_back(1);
        fibNums.push_back(1);
        
        // now we store the array of fib nums that we can use
        while(fibNums[fibNums.size()-1]+fibNums[fibNums.size()-2]<=k){
            fibNums.push_back(fibNums[fibNums.size()-1]+fibNums[fibNums.size()-2]);
        }
        
        return minFibsToReachFromIth(0,fibNums,k);
    }
};
