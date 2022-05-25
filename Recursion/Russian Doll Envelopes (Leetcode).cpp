class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        //a particular subset will give the optimal results
        //we can use this idea and use our recursive knowledge
        sort(envelopes.begin(),envelopes.end());  //NOTE : Sometimes to find the optimal subset/subsequence , we must 1st order the set properly (here by sorting)
        return knapsack(0,envelopes,0,0);
   
    }
    int knapsack(int ind, vector<vector<int>> &envelopes, int lastW,int lastH){
        if(ind==envelopes.size()) return 0;
        
        if(envelopes[ind][0]>lastW&&envelopes[ind][1]>lastH){
            //here we have two choices
            return max(1+knapsack(ind+1,envelopes,envelopes[ind][0],envelopes[ind][1]),knapsack(ind+1,envelopes,lastW,lastH));
        }
        else return knapsack(ind+1,envelopes,lastW,lastH);
    
    }
};
