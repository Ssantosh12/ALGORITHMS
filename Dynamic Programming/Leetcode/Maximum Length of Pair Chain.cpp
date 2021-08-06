class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int i,j,mx=1;
        //we use the same concept learnt from problem longest increasing subsequence
        vector<int> mxlen(pairs.size(),1);
        sort(pairs.begin(),pairs.end());
        for(i=1;i<pairs.size();i++){
            for(j=i-1;j>=0;j--){
                if(pairs[j][1]<pairs[i][0]){
                    mxlen[i]=max(mxlen[i],mxlen[j]+1); //mxlen array stores the max. length of the inc.chain/increasing subsequence upto that ith posn
                    mx=max(mx,mxlen[i]);
                }
            }
        }
        return mx;
    }
};
