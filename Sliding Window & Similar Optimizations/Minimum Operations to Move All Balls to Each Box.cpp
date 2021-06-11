class Solution {
public:                                         // V.V.V IMPORTANT OPTIMIZATION
    vector<int> minOperations(string boxes) { //same kind of thinking applied in Hackwithinfy problem
                                              //THINKING: no need to calculate no of moves for each posn again (that would result in O(n^2) time complexity)
                                              //just calculate it first time in O(n) for 1st posn and then for each posn the moves are  modified
                                             //  in O(1) time complexity for other posns
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
