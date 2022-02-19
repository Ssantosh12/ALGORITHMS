class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int pfreq[26],sfreq[26],i,j,ind=0,cnd;
        for(i=0;i<26;i++){
            pfreq[i]=0;
            sfreq[i]=0;
        }
        //we will use characters in string p as the index for pfreq array
        //to store the frequency of each char
        for(i=0;i<p.size();i++)
            pfreq[p[i]-97]++;
        //we start from ind = 0
        //for each character we are going to store frequency of each char of the substring
        //starting from ind index and match with pfreq
        //time complexity will be O(n*26)
        vector<int> ans,ts;
      
      //NOTE: Concept is same as applied in the problem Longest substring without repeating characters
      
        for(i=0;i<s.size();i++){
            if(s[i]==p[0])
                ts.push_back(i);
            //separate test case if size of p is 1
            sfreq[s[i]-97]++;
            cnd=1;
            for(j=0;j<26;j++){
                if(sfreq[j]<pfreq[j])
                    cnd=2;
                else if(sfreq[j]>pfreq[j]){
                    cnd=3;
                    break;
                }
            }
            if(cnd==1){
                ans.push_back(ind);
                sfreq[s[ind]-97]--;
                ind=ind+1;
            }
            else if(cnd==3){
                while(s[ind]!=s[i]){
                    sfreq[s[ind]-97]--;
                    ind++;
                }
                sfreq[s[ind]-97]--;
                ind++;
            }
        }
        //if(p.size()==1)
          //  return ts;
        return ans;
    }
};
