#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int s,n,left=0,right=0,sum=0,mn=100000,i;
    scanf("%lld%lld",&n,&s);
    int a[n];
    bool cnd=false;
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    //segment with sum atleast s and with minimum length
    while(right<n){
        sum=sum+a[right];
        if(sum>=s){
            cnd=true;
            //mn=min(mn,right-left+1);  //no need to check here, since we need the smallest length, so first we reduce the subarray size from the left side
                                           //as much as we can and then we check the last valid length of the subarray
            while(sum>=s){
                sum=sum-a[left];
                left++;
            }
           
            mn=min(mn,right-left+2);
        }
        right++;
    }
    if(cnd)
       printf("%d\n",mn);
    else printf("-1\n");
}
