class Solution {
public:
    int numTeams(vector<int>& rating) {
        int i,j,cnt=0;
        vector<int> inc(rating.size(),0);
        
        //think in simple , just thiink what the problem asks or it needs
        
        //first we are going to solve for the increasing sequence
        for(i=1;i<rating.size();i++){
            for(j=0;j<i;j++){
                if(rating[i]>rating[j]){
                    cnt=cnt+inc[j];
                    inc[i]++;
                }
            }
        }
        //same for decreasing sequence
        vector<int> dec(rating.size(),0);
        for(i=rating.size()-2;i>=0;i--){
            for(j=rating.size()-1;j>i;j--){
                if(rating[i]>rating[j]){
                    cnt=cnt+dec[j];
                    dec[i]++;
                }
            }
        }
        
        return cnt;
    }
};
