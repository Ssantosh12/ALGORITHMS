#include<bits/stdc++.h>
using namespace std;

// method to check if target element is present or not in given array
bool elementPresent(int a[], int target, int n){
    int mid,low=0,high=n-1;
    while(low<=high){
        mid = low+(high-low)/2;
        if(a[mid]==target)
            return true;
        else if(a[mid]>target)
            high=mid-1;
        else low=mid+1;
    }
    return false;
}

int main() {
    int n,i,x,ldiff,rdiff;
    scanf("%d%d",&x,&n);

    int a[n];
    for(i=0;i<=n-1;i++)
        scanf("%d",&a[i]);

    sort(a,a+n);

    // we will try to find the closest element on the right side of x not present in array
    // similarly we will do this for th left side of x, and finally choose the better between them
    rdiff=x;
    while(elementPresent(a,rdiff,n)){
        rdiff++;
    }

    ldiff=x-1;
    while(elementPresent(a,ldiff,n)){
        ldiff--;
    }
    if(x-ldiff<=rdiff-x)
        cout<<ldiff;
    else cout<<rdiff;
}

// OLD SOLUTION
/*
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x,n,e,lf,rt,cnd=0,i,anl,anr;
    scanf("%d%d",&x,&n);
    set<int> st;
    for(i=0;i<n;i++){
        scanf("%d",&e);
        st.insert(e);
    }
    i=x;
    while(1){
        if(st.count(i)==0){
            cnd=1;rt=abs(x-i);anr=i;
            break;
        }
        else i++;
    }
    i=x-1;
    while(1){
        if(st.count(i)==0){
            cnd=2;lf=abs(x-i);anl=i;
            break;
        }
        else i--;
    }
    if(lf<=rt) printf("%d\n",anl);
    else printf("%d\n",anr);

}
*/
