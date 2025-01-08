#include <bits/stdc++.h>
using namespace std;
 
int main() {
    /*
    Initially, you have a coin with value n. You can perform the following operation any number of times (possibly zero):
    transform one coin with value x, where x is greater than 3 (x>3), into two coins with value ⌊x4⌋.
    What is the maximum number of coins you can have after performing this operation any number of times?
    */
    int t;
    scanf("%d",&t);
    while(t--){
        long long int n,times=0,ans=1;
        scanf("%lld",&n);
        while(n>3){
            n=n/4;
            times++;
        }
        while(times--)
            ans*=2;
        cout<<ans<<"\n";
    }
}
