class Solution {
public:
    bool backspaceCompare(string s, string t) {
        // we can use stack for this problem (TODO: use Recursion)
        // we insert elements of the string in stack one by one and if we encounter '#' we remove the current/top element
        int i,n=s.size(),m=t.size();
        stack<int> stkS,stkT;
      
        // insert elements for string s
        for(i=0;i<=n-1;i++){
            if(s[i]!='#')
                stkS.push(s[i]);
            else if(s[i]=='#'&&!stkS.empty()){
                stkS.pop();
            }
        }
        
        // insert elements for string t
        for(i=0;i<=m-1;i++){
            if(t[i]!='#')
                stkT.push(t[i]);
            else if(t[i]=='#'&&!stkT.empty()){
                stkT.pop();
            }
        }
        
        string typedS,typedT;
        while(!stkS.empty()){
            typedS+=stkS.top();
            stkS.pop();
        }
        
        while(!stkT.empty()){
            typedT+=stkT.top();
            stkT.pop();
        }
        
        if(typedS==typedT)
            return true;
        
        return false;
    }
};

// OLD Solution : for comparing and learning
/*
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        
        string::iterator pre;
        pre=S.begin();
        while(pre!=S.end()){
            if(*pre=='#'){
                if(pre==S.begin()) S.erase(pre);
                else{
                pre--;
                S.erase(pre);
                S.erase(pre);
                }
            }
            else pre++;
        }
        pre=T.begin();
        while(pre!=T.end()){
            if(*pre=='#'){
                if(pre==T.begin()) T.erase(pre);
                else{
                pre--;
                T.erase(pre);
                T.erase(pre);
                }
            }
            else pre++;
        }
        if(T==S) return true;
        else return false;
    }
};
*/
