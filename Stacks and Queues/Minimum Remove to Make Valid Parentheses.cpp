class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int i;
        stack<char> stk;
        vector<bool> valid(s.size(),true);
        string ans;
        //first we traverse the string from left to right
        //whenever a closing a bracket asks for an opening barcket if there is no openeing bracket
        //then this closing bracket is invalid and we mark it as false
        for(i=0;i<s.size();i++){
            if(s[i]=='(')
                stk.push('(');
            else if(s[i]==')'){
                if(!stk.empty())
                    stk.pop();
                else valid[i]=false;
            }
        }
        while(!stk.empty())
            stk.pop();
        //now we do the same process from right to left
        //and now we consider opening bracket is ')' and closing bracket is '('
        
        for(i=s.size()-1;i>=0;i--){
            if(s[i]==')')
                stk.push(')');
            else if(s[i]=='('){
                if(!stk.empty())
                    stk.pop();
                else valid[i]=false;
            }
        }
        for(i=0;i<s.size();i++){
            if(valid[i])
                ans.push_back(s[i]);
        }
        return ans;
    }
};
