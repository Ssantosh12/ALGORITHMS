/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        int i,mx=1;
        map<int,int> mp;//freq of each subtree sum
        subsum(root,mp);
        for(auto x :mp)
            mx=max(mx,x.second);
        vector<int> vc;
        for(auto x :mp){
            if(x.second==mx)
                vc.push_back(x.first);
        }
        return vc;
    }
    int subsum(TreeNode *node,map<int,int> &mp){
        if(node==NULL)
            return 0;
        int sum=node->val;  //for subtree sum from this node is um of its val of subtree sum of left node + subtree sum of right node
        sum=sum+subsum(node->left,mp);  //ask the left child its subtree sum
        sum=sum+subsum(node->right,mp);   //ask the right its subtree sum
        mp[sum]++;
        return sum;   //this whole subtree sum is returned to whoever asked about it
    }
};
