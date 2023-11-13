#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        long long int i,n,maxSeqSum=0,maxEle;
        scanf("%lld",&n);
        int arr[n];
        for(i=0;i<=n-1;i++)
            scanf("%d",&arr[i]);

        // we generally use left and right pointers for calculating length of target subrray i.e right-left+1
        // here we just need the max element in one consecutive subarray of same parity (- or +), for loop is enough
        for(i=0;i<=n-1;i++){
            if(i==0)
                maxEle=arr[0];
            else{
                if(arr[i]>0&&arr[i-1]<0||arr[i]<0&&arr[i-1]>0){
                    maxSeqSum+=maxEle;
                    maxEle=arr[i];
                }
                else{
                    if(arr[i]>maxEle)
                        maxEle=arr[i];
                }
            }
            if(i==n-1)
                maxSeqSum+=maxEle;
        }
        cout<<maxSeqSum<<"\n";
    }
}
