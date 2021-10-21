#include <bits/stdc++.h>

using namespace std;

int main()
{
    int j,n,i,out1=0,in1=0,mx=0,temp;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(a[i]==1)
            out1++;
    }
    temp=out1;
    //so we check for all possible solutions and we take the best out of it
    //we place i and j at all possible indices and choose the segment which gives the max overall ones
    for(i=0;i<n;i++){
        for(j=i;j<n;j++){
            if(a[j]==1){
                out1--;
                in1++;
            }
            mx=max(mx,out1+((j-i+1)-in1));
        }
        out1=temp;
        in1=0;
    }

    printf("%d",mx);
}


