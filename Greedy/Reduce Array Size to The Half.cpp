class Solution {
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
