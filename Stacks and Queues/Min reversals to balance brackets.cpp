#include <bits/stdc++.h>
using namespace std;

int main(){
   int t=1,i,cnt;

   string s;
   while(1){
        cin>>s;
        if(s[0]!='-'){
            stack<char> stk;
            cnt=0;
            for(i=0;i<s.size();i++){
                if(s[i]=='{')
                    stk.push('{');
                else{
                    if(stk.empty()){
                        cnt++;
                        stk.push('{');
                    }
                    else
                        stk.pop();
                }
            }
            cnt=cnt+stk.size()/2;
            printf("%d. %d\n",t,cnt);
            t++;
        }
        else break;
   }
}
