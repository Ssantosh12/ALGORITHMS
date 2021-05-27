class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        //using basic understaning of dp learnt from errichto's tutorials
        int arr[cost.size()+1],i,j,mn;
        //starting from 0 index
        arr[0]=0;
        arr[1]=cost[0];
        for(i=2;i<=cost.size();i++){
            //ith step can be reached from (i-1)th or (i-2)th step, we choose the cheapest among both
            arr[i]=min((arr[i-1]+cost[i-1]),(arr[i-2]+cost[i-2]));
            
        }
        mn=arr[cost.size()];
        //starting from 1 index
        arr[1]=0;
        arr[2]=cost[1];
        for(i=3;i<=cost.size();i++){
            //ith step can be reached from (i-1)th or (i-2)th step
            arr[i]=min((arr[i-1]+cost[i-1]),(arr[i-2]+cost[i-2]));
        }
        return min(arr[cost.size()],mn);
    }
};
