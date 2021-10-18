#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int s,n,left=0,right=0,sum=0,mx=0,i;
    scanf("%lld%lld",&n,&s);
    int a[n];
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    //segment with sum atmost s and with maximum length
    while(right<n){
        sum=sum+a[right];
        if(sum>s){            //subarray became in valid, we check the previous valid length and again make this subarray valid by reducing its length from the left
            mx=max(mx,right-left);
            while(sum>s){
                sum=sum-a[left];
                left++;
            }

        }
        if(right==(n-1))
            mx=max(mx,right-left+1);
        right++;
    }
    printf("%d\n",mx);
}
