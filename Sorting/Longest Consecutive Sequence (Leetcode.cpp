class Solution {
public:
    int longestConsecutive(vector<int>& nums) {  //nlogn time complexity because of sorting use, can be done in N time complexity as well
        int i,cnt=0,mx=1,prv;
        if(nums.size()==0)
            return 0;
        //here order of elements chosen doesn't matter that's why we can sort the elements before choosing (IMPORTANT)
        //using sorting and converting problem into non overlapping segment problem 
        sort(nums.begin(),nums.end());
        prv=nums[0];
        cnt=1;
        for(i=0;i<nums.size();i++){
            if(nums[i]==prv+1){
                cnt++;
                prv=nums[i];
            }
            else if(nums[i]>prv+1){ //breaking condition
                if(cnt>mx)
                    mx=cnt;
                cnt=1;
                prv=nums[i];
            }
            if(i==(nums.size()-1))
                cnt=max(mx,cnt);
            
        }
        return cnt;
    }
};
