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
    int averageOfSubtree(TreeNode* root) {
        if(root==NULL) return 0;
        
        int sum=subsum(root),count=subcount(root);
        if(root->val==(sum/count))
            return 1+averageOfSubtree(root->left)+averageOfSubtree(root->right);
        else return averageOfSubtree(root->left)+averageOfSubtree(root->right);
    }
    int subsum(TreeNode *ptr){ //recursive function to find each subtree
        if(ptr==NULL) return 0;
        return ptr->val+subsum(ptr->left)+subsum(ptr->right);
    }
    int subcount(TreeNode *ptr){  //recursive function to find the count of nodes in each subtree
        if(ptr==NULL) return 0;
        return 1+subcount(ptr->left)+subcount(ptr->right);
    }
};
