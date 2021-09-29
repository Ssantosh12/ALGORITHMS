#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,i,j,mx=1,val;
    scanf("%d",&n);
    int a[n][3],ans[n][3];
    for(i=0;i<n;i++){
        for(j=0;j<3;j++)
            scanf("%d",&a[i][j]);
    }
    ans[0][0]=a[0][0]; ans[0][1]=a[0][1]; ans[0][2]=a[0][2]; //1st row is same as original grid
    for(i=1;i<n;i++){
        ans[i][0]=a[i][0]+max(ans[i-1][1],ans[i-1][2]);  //we are making a grid that will store the max value we can have  at each point in each row (i.e. each day)
        ans[i][1]=a[i][1]+max(ans[i-1][0],ans[i-1][2]);  // at each point the max value is the value present there + max(of choices from where we can reach this point)
        ans[i][2]=a[i][2]+max(ans[i-1][0],ans[i-1][1]);
    }
    for(j=0;j<3;j++)
        mx=max(ans[n-1][j],mx);
    printf("%d\n",mx);
}
