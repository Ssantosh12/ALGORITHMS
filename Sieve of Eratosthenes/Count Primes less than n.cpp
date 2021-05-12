#include <bits/stdc++.h>
using namespace std;

int main(){
    int j,n,i,cnt=0;
    scanf("%d",&n);
    bool primes[n];
    for(i=0;i<n;i++)
        primes[i]=true;
    primes[0]=false;
    primes[1]=false;
    for(i=2;i*i<n;i++){
        if(primes[i]){
            for(j=i*i;j<n;j=j+i)
                primes[j]=false;
        }
    }
    for(i=0;i<n;i++){
        if(primes[i])
            cnt++;
    }
    printf("%d\n",cnt);
}
// why condition for 'i' is ( i*i<n ) not ( i<n ) because each time j starts from ( j=i*i ), so ( i<n ) will create overflow
//why j starts from ( j=i*i ), look, idea is if p is prime then its multiples are not prime, i.e. 2p, 3p, 4p, 5p,..(p-1)p, pp etc are not prime
// and all lower multiples of p i.e 2p, 3p, 4p...(p-1)p come as multiples of these lower numbers itself 2, 3, 4..(p-1) and since they are not prime
//they have already been makrked as non prime , that's why we start j from ( j=i*i ), from ith multiple of that prime
