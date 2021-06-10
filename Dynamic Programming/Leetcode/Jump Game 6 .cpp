class Solution {
public:
    int maxResult(vector<int>& nums, int k) { 
        
        //same concept of DP thinking applied from learning and solving other dp problems
      // 1. find the no of ways to reach ith position
      // 2. reach ith posn from the position which itself has highest score among all posn from which we can reach ith posn
      
        int score[nums.size()],i,j,mx;
        map<int,int> mp;
        score[0]=nums[0];
        for(i=1;i<nums.size();i++){
            mp[score[i-1]]++;
            if((i-(k+1))>=0){
                mp[score[i-(k+1)]]--;
                if(mp[score[i-(k+1)]]==0)
                    mp.erase(score[i-(k+1)]);
            }
            score[i]=nums[i]+mp.rbegin()->first;
        }
        return score[nums.size()-1];
    }
};
