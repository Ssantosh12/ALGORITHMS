#include <bits/stdc++.h>
using namespace std;

int main(){
   long long int cost,n,i;

   while(1){
        scanf("%lld",&n);  //two ways to think, that's where greedy lies i think, we hab=ve to make a[i]=0 (nothing to take or give)
                           //if a[i] wants to take we go on its right side and find the 1st one who wnats to give, but still this may not enough for a[i] to become zero
                           // and we will keep doing it untill a[i] becomes zero, but for the single a[i] we ran loops several times
                           //ANS->Just make transaction to the next one i+1 and mae ith zero no matter (i+1)th wants to give or take
        if(n!=0){
            long long int a[n];
            cost=0;
            for(i=0;i<n;i++)
                scanf("%lld",&a[i]);
            for(i=0;i<n-1;i++){
                if(a[i]<0){

                    a[i+1]=a[i+1]-llabs(a[i]);
                    cost=cost+llabs(a[i]);
                    a[i]=0;
                }
                else{
                    a[i+1]=a[i+1]+a[i];
                    cost=cost+a[i];
                    a[i]=0;
                }
            }
            printf("%lld\n",cost);
        }
        else break;
   }

}
