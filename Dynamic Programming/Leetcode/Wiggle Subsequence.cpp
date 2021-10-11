class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int j,i,mx=1,n=nums.size();
        vector<pair<int,bool>> vc(n,{1,false});  // O(n^2) solution, a better solution can be found
                                                 // we use the concept learnt while solving Longest Increasing Subsequence problem
                                                 // we store the max length of valid sequence at each ith index
        for(i=1;i<n;i++){
          for(j=0;j<i;j++){
            if(vc[j].first==1){
                if(vc[i].first==1){
                    if(nums[i]>nums[j]){
                        vc[i].first=2;
                        vc[i].second=true;
                     }
                     else if(nums[i]<nums[j])
                        vc[i].first=2;
                }
            }
            else{
                //now we check the validity of the sequence for this particular ith element
                if(vc[j].second==true&&nums[i]<nums[j]){
                    if(vc[j].first+1>vc[i].first){
                        vc[i].first=vc[j].first+1;
                        vc[i].second=false;
                    }
                }
                else if(vc[j].second==false&&nums[i]>nums[j]){
                    if(vc[j].first+1>vc[i].first){
                        vc[i].first=vc[j].first+1;
                        vc[i].second=true;
                    }
                }
            }
        }
        mx=max(vc[i].first,mx);
    }
        return mx;
    }
};
