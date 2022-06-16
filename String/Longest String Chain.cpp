class Solution {
public:
    
   
    int longestStrChain(vector<string>& words) {
        //we are going to use the knowledge of Longest increasing Subsequence(LIS) of O(n^2) algorithm
        int ind,i,j,k,mx=1;
       
        vector<int> dp(words.size(),1);
      
      //NOTE : 
       //first we sort the vector of strings by size using bubble sort(can use STL as well)
        for(i=words.size()-1;i>=0;i--){
            for(j=0;j<i;j++){
                if(words[j].size()>words[j+1].size())
                    swap(words[j],words[j+1]);
            }
        }
        for(i=0;i<words.size();i++){
            //for each word , we look at its left side 
            for(j=0;j<i;j++){
                if(words[i].size()==words[j].size()+1){
                    ind = 0;
                    for(k=0;k<words[i].size();k++){
                        if(words[i][k]==words[j][ind])
                            ind++;
                    }
                    if(ind==words[j].size())
                        dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        for(i=0;i<words.size();i++)
            mx=max(mx,dp[i]);
        return mx;
    }
  
    
};
