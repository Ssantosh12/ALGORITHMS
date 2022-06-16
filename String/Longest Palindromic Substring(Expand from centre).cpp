class Solution {
public:
    string longestPalindrome(string s) {   //NOTE : passed in gfg but giving tle on leetcode, needs debugging
        int left,right,i;
        string mx;
        mx.push_back(s[0]);
        for(i=0;i<s.size()-1;i++){
            //we will consider each letter as a middle of a palindromic substring
            //and from that middle we extend the palindrome from left and right (called Exapnd from centre)
            
            //case 1st : if middle is one element (odd length palindrome)
            left=i; right=i;
            string ans;
            while(left>=0&&right<s.size()&&s[left]==s[right]){
                if(left==i)
                    ans.push_back(s[right]);
                else{
                    ans.push_back(s[right]);
                    ans=s[left]+ans;
                }
                left--;
                right++;
            }
        
            if(ans.size()>mx.size())
                mx=ans;
            
            //case 2 : if middle is if 2 elements (even length palindrome)
            left=i; right=i+1;
            ans.clear();
            while(left>=0&&right<s.size()&&s[left]==s[right]){
                ans.push_back(s[right]);
                ans=s[left]+ans;
                left--;
                right++;
            }
            if(ans.size()>mx.size())
                mx=ans;
        }
        return mx;
    }
};
