class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int i,zero=0,mn=s.size(),lone=0,lzero=0;
        for(i=0;i<s.size();i++){
            if(s[i]=='0')
                zero++;
        }
        //we consider each ith index as the starting point of 1's
        //where after that index (rightside ) all elements are 1
        //we consider all possibilities of a valid resulting string and choose which takes the min flips
        for(i=0;i<=s.size();i++){
            mn=min(mn,lone+(zero-lzero));
            if(s[i]=='0')
                lzero++;
            else lone++;
        }
        return mn;
    }
};
