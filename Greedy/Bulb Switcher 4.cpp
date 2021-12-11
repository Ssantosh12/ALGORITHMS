class Solution {
public:
    int minFlips(string target) {
        int i,curr=0,cnt=0;
        for(i=0;i<target.size();i++){
            if(target[i]=='1'&&curr==0){
                cnt++;
                curr=1;
            }
            else if(target[i]=='0'&&curr==1){
                cnt++;
                curr=0;
            }
        }
        return cnt;
    }
};

/* old code for comaprison

class Solution {
public:
    int minFlips(string target) {
        int n,i,cnt=0,flip=0;
        vector<int> vc,ans;
        for(i=0;i<target.size();i++){
                if(target[i]=='1'&&vc.empty()){
                        vc.push_back(1);
                        cnt++;
                        if(i==target.size()-1){
                                ans.push_back(cnt);
                        }
                }
                else if(target[i]=='1'&&!vc.empty()){
                        vc.push_back(1);
                        cnt++;
                        if(i==target.size()-1){
                                ans.push_back(cnt);
                        }
                }
                else if(target[i]=='0'&&!vc.empty()){
                        ans.push_back(cnt);
                        cnt=0;
                        vc.clear();
                }
        }
        if(target[target.size()-1]=='1'){
                if(ans.size()>1)
                flip=(ans.size()-1)*2+1;
                else flip=1;
        }
        else{
                flip=ans.size()*2;
        }
            return flip;
    }
};

*/
