class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i,wall=-1,mx=0;
      //using the technique of wall shifting from longest valid parenthesis
        for(i=0;i<nums.size();i++){
            if(nums[i]==0)
                wall=i;
            else
                mx=max(mx,i-wall);
        }
        return mx;
    }
};

//OLDER WAY for this problem (finding breaking condtions and calculating at those points)
/*
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i,cnt=0,mx=0;
        for(i=0;i<nums.size();i++){
            if(nums[i]==1){
                cnt++;
                if(i==nums.size()-1)   //breaking condition
                    mx=max(mx,cnt);
            }
            else{                //breaking conditon
                mx=max(mx,cnt);
                cnt=0;
            }
        }
        return mx;
    }
};
*/
