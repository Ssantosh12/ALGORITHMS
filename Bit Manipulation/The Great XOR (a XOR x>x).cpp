#include <bits/stdc++.h>
using namespace std;

int main(){
  //find no of all a , 0<a<x such that a XOR x greater than x
  //little bit similar to bit strings problem using knowlwdgw of permutations and combinations
    int q;
    scanf("%d",&q);
    while(q--){
        long long int x,i,cnt=0,cnd=0,pw;
        scanf("%lld",&x);
        for(i=33;i>=0;i--){ //since x<=10^10 , so we start i from 33
            if((1LL<<i)&x)
                cnd=1;
            else{
                if(cnd==1){

                    cnt=cnt+pow(2,i);
                }
            }
        }
        printf("%lld\n",cnt);
    }
}
