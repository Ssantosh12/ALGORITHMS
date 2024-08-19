#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int n,m,i,mid,low=0,high,subsidySum=0,maxEle=1;
    cin>>n>>m;

    long long int arr[n];
    for(i=0;i<=n-1;i++){
        cin>>arr[i];
        maxEle=max(maxEle,arr[i]);
        subsidySum+=arr[i];
    }

    if(subsidySum<=m){
        cout<<"infinite";
    }
    else{
        high=maxEle;
      
        // using the technique 'YYYYYYYNNNNNNN' of binary search to find the answer 
        // main aim of this type of binary search is to lower the size of segment [low,high] until it contains only 1 element, i.e low = high
        while(low<high){
            // EDGE CASE in Binary Search : note whenever we do 'low = mid', there is always the chance for the loop to go infinite
            // TODO: better explanation 
            if(high-low==1)
                mid=high;
            else mid= low + (high-low)/2;

            // do the work for this possible asnwer 'mid'
            subsidySum=0;
            for(i=0;i<=n-1;i++){
                subsidySum+=min(arr[i],mid);
            }

            if(subsidySum<=m){
                // then we have landed at one of the 'Y' and we update the segment to 'mid to high' (notice low=mid, since this mid is a possible answer as well)
                low=mid;
            }
            else{
                // we have landed at one of the 'N' and  we update the segment to 'low to mid-1' (notice high=mid-1, since this mid is NOT a possible answer)
                high=mid-1;
            }
        }

        // since the loop ended when low = high, both low and high are the answer 
        cout<<low;
    }
}
