class Solution {
public:
    vector<int> minOperations(string boxes) {
        int i,j,left=0,right=0,sum=0;
        for(i=0;i<boxes.size();i++){
            if(boxes[i]=='1'){
                right++;
                sum=sum+i+1;
            }
            
        }
        vector<int> vc;
        for(i=0;i<boxes.size();i++){
            sum=sum-right;
            sum=sum+left;
            vc.push_back(sum);
            if(boxes[i]=='1'){
                right--;
                left++;
            }
        }
        return vc;
    }
};
