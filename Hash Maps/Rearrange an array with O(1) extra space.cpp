class Solution{
    public:
   
    // just store the previous values of indices in the map if they gets updated 
  
    void arrange(long long arr[], int n) {
        // Your code here
        int i,j,temp;
        map<int,int> mp;
        for(i=0;i<n;i++){
            if(mp[arr[i]]==0){
                temp=arr[i];
                arr[i]=arr[arr[i]];
                mp[i]=temp+1;
            }
            else{
                temp=arr[i];
                arr[i]=mp[arr[i]]-1;
                mp[i]=temp+1;
            }
        }
    }
};
