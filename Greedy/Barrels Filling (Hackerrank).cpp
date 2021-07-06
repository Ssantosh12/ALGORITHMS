#include <bits/stdc++.h>
using namespace std;

int main(){
       
       // Problem : given two arrays a and b of size n barrels each having some elements, we have to take another array of size n and fill each ith posn of this new array
       // from any two posn of both of the arrays a and b
       
       int x,n,m,i,sum1=0,sum2=0,ans=0,left,right,cnd;
       scanf("%d",&n);
       int a[n];
       for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        sum1=sum1+a[i];
       }
       scanf("%d",&m);
       int b[m];
       for(i=0;i<m;i++){
        scanf("%d",&b[i]);
        sum2=sum2+b[i];

       }
       scanf("%d",&x);
       
       sort(a,a+n);
       sort(b,b+m);
       left=0; right=m-1;
       
       while(left<n){
             ans=max(ans,(a[left]+b[right]));
             left++;
             right--;
       }
       
       if((sum1+sum2)<=x*n&&ans<=x){
          cnd=1;
          ans=(x*n)-(sum1+sum2);
       }
       else
          cnd=-1;
           
       printf("%d\n%d\n",cnd,ans);
}
