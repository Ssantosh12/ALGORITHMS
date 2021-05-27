class Solution {
public:
    int climbStairs(int n) {
        int ways[n+1],i;
        ways[0]=1;
        ways[1]=1;
        for(i=2;i<=n;i++)
            //ith step can be reached from (i-1) or (i-2)th step
            ways[i]=ways[i-1]+ways[i-2];
        return ways[n];
    }
};
