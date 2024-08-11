class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int i,n=arr.size(),removals=0,count=0;
        
        // store the frequency of each element
        map<int,int> freq;
        for(i=0;i<=n-1;i++)
            freq[arr[i]]++;
        
        vector<int> freqArr;
        for(auto x: freq)
            freqArr.push_back(x.second);
        
        // since map sorts data structure according to the key not according to the value
        // we wiil have to sort the array of frequencies we obtained
        sort(freqArr.begin(),freqArr.end());
        
        for(i=freqArr.size()-1;i>=0;i--){
            removals+=freqArr[i];
            count++;
            
            if((n&1)&&removals>=(n/2)+1)
                break;
            else if(!(n&1)&&removals>=(n/2))     // NOTE : Be careful here, as (!n&1 && condition2) was wrong and giving error, correct is !(n&1 && condition2)
                break;
        }
        
        return count;
    }
};

// OLDER Solution 
/*class Solution {
public:
    int minSetSize(vector<int>& arr) {
      
       // each time choose that element to remove which has the most frequency- greedy approach
      
        int siz=arr.size(),cnt=0,i;
        map<int,int> mp;
        for(i=0;i<arr.size();i++)
            mp[arr[i]]++;
        priority_queue<int> pq; //max heap
        for(auto x: mp){
            pq.push(x.second);
        }
        
        while(siz>(arr.size())/2){
            siz=siz-pq.top();
            pq.pop();
            cnt++;
        }
        return cnt;
    }
};
*/
