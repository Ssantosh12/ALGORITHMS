class Solution{
public:
    vector<int> pattern(int N){
        // code here
        vector<int> ans;
        
        // recursive call with sending ans vector as a reference parameter
        printPatternRecursive(N,ans);
        
        return ans;
    }
    
    void printPatternRecursive(int N, vector<int> &ans){
        if(N<=0){
            ans.push_back(N);
            return;
        }
        // first add in decreasing order
        ans.push_back(N);
        
        printPatternRecursive(N-5,ans);
        
        // after we return from recursive call, we can say here that from -5 we came to current node/state
        // that is we jumped to +5, so like this it becomes increasing order when we are returning from recursive call back
        
        ans.push_back(N);
        
    }
};
