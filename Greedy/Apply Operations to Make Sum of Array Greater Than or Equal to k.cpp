class Solution {
public:
    int minOperations(int k) {
        // initially I thought this solution won't work and this is some lengthy type of problem
        // but this is correct so MAJOR LEARNING : Always Trust your intuition and never be afraid
        int num,diff,count=0,mnCount=k-1;
        for(num=1;num<=k;num++){
            count=num-1;
            diff=k-num;
            if(diff%num==0)
                count+=diff/num;
            else count+=(diff/num)+1;
            if(count<mnCount)
                mnCount=count;
        }
        return mnCount;
    }
};
