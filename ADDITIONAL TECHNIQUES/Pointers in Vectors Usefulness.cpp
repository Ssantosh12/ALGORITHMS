#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,t,i,ele,sum=0,mx=0,pro;
    scanf("%d",&n);
    vector<int> nums;
    for(i=0;i<n;i++){
        scanf("%d",&ele);
        nums.push_back(ele);
    }
  
    //although this is an attempt greedy solution to a leetcode hard problem(Bursting Ballons)(whici is wrong, use dp)
    //but the way vectors has been used is useful to learn
  
    while(!nums.empty()){
            mx=0;
            for(auto it=nums.begin();it!=nums.end();it++){
                pro=*it;
                if((it-1)!=nums.begin()-1)
                    pro=pro*(*(it-1));
                if((it+1)!=nums.end())
                    pro=pro*(*(it+1));
                mx=max(mx,pro);
            }
            sum=sum+mx;
            cout<<sum<<endl;
            for(auto it=nums.begin();it!=nums.end();it++){
                pro=*it;
                if((it-1)!=nums.begin()-1)
                    pro=pro*(*(it-1));
                if((it+1)!=nums.end())
                    pro=pro*(*(it+1));
                if(pro==mx){
                    nums.erase(it);
                    break;
                }

            }
        }
        cout<<sum;
}
