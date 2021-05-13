#include <bits/stdc++.h>
using namespace std;

int main(){

        int n,i,k,sum=0,mn;
        scanf("%d%d",&n,&k);
        int a[n];
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(i=0;i<k;i++)
            sum=sum+a[i];
        mn=sum;
        for(i=1;i<=n-k;i++){
            sum=sum-a[i-1];
            sum=sum+a[i+(k-1)];
            if(sum<mn){
                mn=sum;
            }
        }
        printf("%d\n",mn);

}
