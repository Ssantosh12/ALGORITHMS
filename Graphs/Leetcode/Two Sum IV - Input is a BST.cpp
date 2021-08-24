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
    bool findTarget(TreeNode* root, int k) {
        int target,i;
        map<int,int> mp;
        inorder(root,mp);
        vector<int> vc;
        in(root,mp,k,vc);
        if(!vc.empty())
           return true;
        else return false;
    }
    void inorder(TreeNode *root,map<int,int> &mp){
        if(root==NULL)
            return;
        inorder(root->left,mp);
        mp[root->val]=1;
        inorder(root->right,mp);
    }
    void in(TreeNode *root,map<int,int> &mp,int &k, vector<int> &vc){
        if(root==NULL)
            return;
        in(root->left,mp,k,vc);
        int target=k-(root->val);
        if(mp[target]==1&&target!=(root->val)){
            vc.push_back(target);
            vc.push_back(root->val);
        }
        in(root->right,mp,k,vc);
    }
};
