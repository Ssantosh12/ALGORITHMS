class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs;
        vector<int> vc;
        subset(vc,0,nums,subs);
        return subs;
    }
    
    void subset(vector<int> vc, int ind,vector<int> &nums, vector<vector<int>> &subs){
     if(ind==nums.size()){
        subs.push_back(vc);
        return;
      }
     subset(vc,ind+1,nums,subs);
     vc.push_back(nums[ind]);
     subset(vc,ind+1,nums,subs);
   }
    
};
