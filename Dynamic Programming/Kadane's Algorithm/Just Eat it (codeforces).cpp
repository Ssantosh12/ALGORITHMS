#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){ 
        //simple use of kadane's algorithm
        
        long long int sum=0,val,mx,n,i,ans,sm=0;
        scanf("%lld",&n);
        int a[n];
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
            sum=sum+a[i];
        }
        mx=a[0];
        for(i=0;i<n-1;i++){
            sm=sm+a[i];
            if(sm>mx)
                mx=sm;
            if(sm<0)
                sm=0;
        }
        ans=mx;
        mx=a[1];
        sm=0;
        for(i=1;i<n;i++){
            sm=sm+a[i];
            mx=max(sm,mx);
            if(sm<0)
                sm=0;
        }
        ans=max(mx,ans);
        if(sum>ans)
            printf("YES\n");
        else printf("NO\n");
    }
}
