class Solution {
public:
    string arrangeWords(string text) {
        // we can use a hash map to store key value pairs
        // where word sizes will be keys and array of words of key size as values
        int i,n=text.size();
        string ans="",word="";
        
        // make first letter small of given 'text' string
        text[0]=text[0]+32;
        
        map<int,vector<string>> mp;
        
        // we iterate the text string and obtains words
        // each word is obtained after we meet a 'space' or end of the 'text' string
        for(i=0;i<=n-1;i++){
            if(text[i]==' '){
                mp[word.size()].push_back(word);
                word="";
            }
            else{
                word+=text[i];
            }
            
            // edge case : a word is also obtained at the end of 'text' string
            if(i==n-1)
                mp[word.size()].push_back(word);
        }
        
        // form the answer string using the sorted size of words strored in map
        for(auto x: mp){
            for(auto y: x.second){
                ans+=y;
                ans+=" ";
            }
        }
        
        // make first letter capital and remove last extra space
        ans[0]=ans[0]-32;
        ans.pop_back();
        
        return ans;
    }
};
