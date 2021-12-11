class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=piles[0],mid,cnt,i;
        for(i=0;i<piles.size();i++)
            high=max(high,piles[i]);
        while(low<high){
            mid=low+(high-low)/2;
            //we check if answer is possible at mid or not
            cnt=0;
            for(i=0;i<piles.size();i++){
                cnt=cnt+piles[i]/mid;
                if(piles[i]%mid!=0)
                    cnt++;
            }
            if(cnt>h)
                low=mid+1;
            else high=mid;
        }
        return low;
    }
};
