#include <bits/stdc++.h>
using namespace std;

int main(){
    int t,i,j,l,r,left,right,diff,mid,ind1,ind2;
    bool primes[1000000];
    for(i=0;i<1000000;i++)
        primes[i]=true;
    primes[0]=false;
    primes[1]=false;
    for(i=2;i*i<1000000;i++){
        if(primes[i]){
            for(j=i*i;j<1000000;j=j+i)
                primes[j]=false;
        }
    }
    vector<int> vc;
    for(i=0;i<1000000;i++){
        if(primes[i])
            vc.push_back(i);
    }
    scanf("%d",&t);
    while(t--){
        ind1=-1; ind2=-1;
        scanf("%d%d",&l,&r);
        left=0; right=vc.size();
        while(left!=right){
            mid=(left+right)/2;
            if(vc[mid]==l){
                ind1=mid;
                break;
            }
            if(vc[mid]<l)
                left=mid+1;
            else right=mid;
        }
        if(ind1==-1)
            ind1=left;

        left=0; right=vc.size()-1;
        while(left!=right){
            mid=(left+right);
            if(mid&1)
                mid++;
            mid=mid/2;
            if(vc[mid]==r){
                ind2=mid;
                break;
            }
            if(vc[mid]>r)
                right=mid-1;
            else left=mid;
        }
        if(ind2==-1)
            ind2=left;
        if(ind1>ind2) printf("-1\n");
        else if(ind1==ind2)
            printf("0\n");
        else printf("%d\n",vc[ind2]-vc[ind1]);
    }
}
