#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int left=0,right=0,i,mn=200000;  //Problem is similar as finding the min lemgth subarray with sum k (Edu section problem)
        bool cnd=false;
        map<char,int> mp;  //instead of sum that we used in above problem , here we use map to store frequncy, whenever size of map becomes 3 conditions become valid
        string s;
        cin>>s;
        while(right<s.size()){
            mp[s[right]]++;
            if(mp.size()==3){   //here subarray became valid 
                cnd=true;
                while(mp.size()==3){   //since we have to find the subarray of minimum length we reduce its length from the left side as much as we can
                    mp[s[left]]--;
                    if(mp[s[left]]==0)
                        mp.erase(s[left]);
                    left++;
                }
                mn=min(mn,right-left+2);
            }
            right++;
        }
        if(cnd)
            printf("%d\n",mn);
        else printf("0\n");

    }
}


