#include <bits/stdc++.h>
using namespace std;

int main(){
    int k,n,i,j,tim;
    scanf("%d%d",&n,&k);
    int a[n];
    vector<int> cst(n,-1);
    cst[0]=0;
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<n;i++){
        tim=k;
        for(j=i-1;j>=0&&tim>0;j--){
            if(cst[i]!=-1){
                cst[i]=min(cst[i],abs(a[i]-a[j])+cst[j]);
            }
            else cst[i]=abs(a[i]-a[j])+cst[j];
            tim--;
        }
    }
    printf("%d\n",cst[n-1]);
}
