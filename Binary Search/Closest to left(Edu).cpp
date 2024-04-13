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
        left=0; right=n-1;
        while(left!=right){
            mid=(left+right);     //diffrence lies here from closest to right problem, when even elements mid shifts to left of the two middle ones
                                  //but we have to shift to the right of the two middle one to choose the mid otherwise loop won't break
            if(mid&1)
                mid++;
            mid=mid/2;
            if(a[mid]>ele)
                right=mid-1;
            else left=mid;
            }
         if(ele<a[0]) printf("0\n");
         else
         printf("%d\n",left+1);
        }
}
