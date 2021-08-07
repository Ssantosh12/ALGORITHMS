class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //create another array of distinct elements
        int i,j,cnt,mx=0,left,right;
        unordered_map<int,int> mp;  //map takes 100 ms whereas unordered_map takes 60 ms
        vector<int> vc;
        for(i=0;i<nums.size();i++){
            if(mp[nums[i]]==0){
                vc.push_back(nums[i]);
                mp[nums[i]]=vc.size();
            }
        }
        //we use concept of dfs here, we visit elements like we visit nodes in dfs and maintain visited array
        vector<bool> visited(vc.size(),false);
        for(i=0;i<vc.size();i++){
            if(visited[i]==false){
                left=vc[i]-1;
                right=vc[i]+1;
                cnt=1;
                while(mp[left]!=0){
                    cnt++;
                    visited[mp[left]-1]=true;
                    left--;
                }
                while(mp[right]!=0){
                    cnt++;
                    visited[mp[right]-1]=true;
                    right++;
                }
                
                if(cnt>mx)
                    mx=cnt;
            }
        }
        return mx;
    }
};
