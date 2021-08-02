#include <bits/stdc++.h>
using namespace std;

int main(){
    int k,n,i,j,tind,sind=0,cnd,cnt=0;
    scanf("%d%d",&n,&k);
    int a[n];
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    //we are going to use brute force, using two nested loops
    //ALGORITHM - Its better to build power plant as far as it is valid from a city/point
    while(sind<n){
        tind=sind+(k-1);
        if(tind>(n-1))
            tind=n-1;
        cnd=0;
        for(j=tind;j>=sind-(k-1)&&j>=0;j--){  //NOTE:for each sind the search range is sind-(k-1) to sind+(k-1)
                                              // we start from sind+(k-1) and move left because we want to build tower as right as possible
            if(a[j]==1){
                sind=j+k;
                cnd=1;
                cnt++;
                break;
            }
        }
        if(cnd==0)
            break;
    }
    if(cnd==0) printf("-1\n");
    else printf("%d\n",cnt);

}
