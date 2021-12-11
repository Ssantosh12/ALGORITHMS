class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low=weights[0],high=0,mid,i,cnt,sum;
        for(i=0;i<weights.size();i++){
            high=high+weights[i];
            low=max(low,weights[i]);
        }
        
        while(low<high){
            mid=low+(high-low)/2;
            //now we check if mid is feasible answer or not
            cnt=0;
            sum=0;
            //we will iterate over the array and count the no days it requires when we choose mid as capacity
            for(i=0;i<weights.size();i++){
                sum=sum+weights[i];
                if(sum>mid){
                    cnt++;
                    sum=weights[i];
                }
                if(i==(weights.size()-1))
                    cnt++;
            }
            if(cnt>days)
                low=mid+1;
            else high=mid;
        }
        return low;
    }
};
