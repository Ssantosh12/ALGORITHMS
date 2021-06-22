#include <bits/stdc++.h>
using namespace std;

int main(){
  
    // NOTE: This code needs to be corrected
  
    int n,i,j,ele,ans,dist=0,mn=INT_MAX,left,right,prv;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
        scanf("%d",&ele);
    map<int,int> mp;
    set<int> st;

    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        st.insert(a[i]);
    }
    prv=a[0];
    left=0;
    while(a[left]==prv)
        left++;
    left--;
    right=left;

    while(mp.size()!=st.size()){
        mp[a[right]]++;
        right++;
    }

    mn=right-left;

    cout<<left<<" "<<right<<endl;

    while(right<n){
        while(mp.size()>=(st.size()-1)){
            mp[a[left]]--;
            if(mp[a[left]]==0)
                mp.erase(a[left]);
            left++;
        }
        left--;

        while(mp.size()!=st.size()){
            mp[a[right]]++;
            right++;
        }
        cout<<left<<" "<<right<<endl;
        mn=min(mn,(right-left));
    }

    printf("%d\n",mn);
}
