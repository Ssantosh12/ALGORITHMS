//only the main part is here for understanding, same thinking as creating all the subsets
// For each element there are two choices , to choose or to not choose this element (for adding in sum in this case), and after that we move to the next element

vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> ans;
        int sum=0;
        subsum(0,sum,arr,ans);
        return ans;
    }
    void subsum(int ind,int &sum, vector<int> &arr, vector<int> &ans){
        if(ind==arr.size()){
            ans.push_back(sum);
            return;
        }
        
        sum=sum+arr[ind];
        subsum(ind+1,sum,arr,ans);
        sum=sum-arr[ind];
        subsum(ind+1,sum,arr,ans);
    }
