#include <bits/stdc++.h>
using namespace std;

int main(){
    
    //remember to make different array for costs

        int n,i;
        scanf("%d",&n);
        int a[n],cost[n];
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        //we use basic concept learnt from stair problem and Errichto's DP learning videos
        //think in terms of smaller inputs
        cost[1]=abs(a[1]-a[0]);
        cost[0]=0;
        //remember in stair problem we had to reach (i)th stair, that was possible from (i-1)th stair or from (i-2)th stair
        //so we counted how many ways we can reach to (i)th stair by counting no of ways we can reach (i-1)th stair and (i-2)th stair
        //almost same thinking here, its just that we have to reach (i)th stair with the min cost,i.e we choose which has min cost
        // (i-1)th posn or (i-2)th posn
        for(i=2;i<n;i++){
            //we will store the min cost to reach each ith position
            cost[i]=min((cost[i-2]+abs(a[i]-a[i-2])),(cost[i-1]+abs(a[i]-a[i-1])));
        }
     
        printf("%d\n",cost[n-1]);
    
}
