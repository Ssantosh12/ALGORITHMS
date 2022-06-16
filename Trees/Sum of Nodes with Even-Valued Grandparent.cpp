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
    int sumEvenGrandparent(TreeNode* root) {
        if(root==NULL)
            return 0;
        if(root->val%2==0){  //each node can have 4 grandchildren and if this node is even ,
                             //we add all 4 grandchildren values and return along with finding answer in left and right subtree 
                             // i.e.  SUM FROM THIS NODE + ALL SUMS(LEFT SUBTREE) + ALL SUMS(RIGHT SUBTREE ) , this is an important concept
            int sum=0;
            if(root->left!=NULL&&root->left->left!=NULL)
                sum+=root->left->left->val;
            if(root->left!=NULL&&root->left->right!=NULL)
                sum+=root->left->right->val;
            if(root->right!=NULL&&root->right->left!=NULL)
                sum+=root->right->left->val;
            if(root->right!=NULL&&root->right->right!=NULL)
                sum+=root->right->right->val;
            return sum+sumEvenGrandparent(root->left)+sumEvenGrandparent(root->right);
        }
        else return sumEvenGrandparent(root->left)+sumEvenGrandparent(root->right);
    }
};
