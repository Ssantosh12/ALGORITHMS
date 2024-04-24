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


/*
//ALTERNATE Solution

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> vc;
        vector<vector<int>> ans;
        subs(0,nums,vc,ans);
        return ans;
    }
    void subs(int ind,vector<int> &nums, vector<int> &vc,vector<vector<int>> &ans){   //only difference here is that we are sending vc with reference
        if(ind==nums.size()){
            ans.push_back(vc);
            return;
        }
        //we not take and take this element
        
        vc.push_back(nums[ind]);
        subs(ind+1,nums,vc,ans);
        vc.pop_back();              // 1st we push this element and then we pop this element i.e. we undid that we did, so we can send vc by reference
        subs(ind+1,nums,vc,ans);
        
    }
};

*/
