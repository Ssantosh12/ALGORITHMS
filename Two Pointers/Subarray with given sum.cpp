#include <bits/stdc++.h>
using namespace std;

int main(){
   
    //standard concept of two pointers, move right pointer to get cumulative sum if this sum becomes gretaer than given target sum s
  // the we adjust sum be removing elments at left pointer and moving it right until sum is greater tahn s
  // at any time sum==s we output indices left and right  
  
    int left,right,i,n,s,cnd=0,sum=0;
    scanf("%d%d",&n,&s);
    int a[n];
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    left=0; right=0;
    while(right<n){
        sum=sum+a[right];
        if(sum==s){
            cnd=1;
            break;
        }
        else if(sum>s){
            while(sum>s){
                sum=sum-a[left];
                left++;
            }
          // here point to note, upper loop terminates when sum!>s, so it can terminate at 2 consitions, either sum becomes less than s
          //or sum becomes equal to s, if equal ans has been found, need to look carefully for these kind of thinking and logic
            if(sum==s){
                cnd=1;
                break;
            }
        }
        right++;
    }
    if(cnd==1) printf("%d %d\n",left,right);
    else printf("-1\n");
}
