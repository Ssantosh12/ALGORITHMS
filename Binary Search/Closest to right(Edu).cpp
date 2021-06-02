#include <bits/stdc++.h>
using namespace std;

int main(){

        int mid,left,right,k,n,i,ele;
        scanf("%d%d",&n,&k);
        int a[n];

        for(i=0;i<n;i++)
            scanf("%d",&a[i]);

        //using binary search for creating lower_bound search
        while(k--){
        scanf("%d",&ele);
        left=0; right=n;
        while(left!=right){
            mid=(left+right)/2; 
            if(a[mid]<ele)
                left=mid+1;
            else right=mid;
            }
         
         printf("%d\n",left+1);
        }
}
