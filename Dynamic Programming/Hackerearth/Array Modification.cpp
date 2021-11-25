#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int n,i,mx=1;
    scanf("%lld",&n);
    long long int a[n];
    for(i=0;i<n;i++)
        scanf("%lld",&a[i]);
    //for this problem we use the basic defintion of dp- try out all possible solutions and choose the best out of them
    //we increase all elements to their max and choose the max out of those
    long long int left[n],right[n];
    //left array stores the max size of each element it is increased from its left neighbour and for right vice versa
    left[0]=a[0];
    right[n-1]=a[n-1];
    for(i=1;i<n;i++)
        left[i]=a[i]+left[i-1]/2;

    for(i=n-2;i>=0;i--)
        right[i]=a[i]+right[i+1]/2;

    for(i=0;i<n;i++){
        if((i-1)>=0)
            a[i]=a[i]+left[i-1]/2;
        if((i+1)<n)
            a[i]=a[i]+right[i+1]/2;
        mx=max(mx,a[i]);
    }
    printf("%lld\n",mx);
}
