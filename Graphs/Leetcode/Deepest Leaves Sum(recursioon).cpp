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
    int deepestLeavesSum(TreeNode* root) {
        //first we find the max depth of the tree and traverse ing dfs 
        //and for each node which is a leaf and has depth equal to max depth we add it to sum
        int sum=0,mx=0,depth=0;
        dfs(root,mx,depth);
        dfs2(root,sum,mx,depth);
        return sum;
        
    }
    void dfs(TreeNode *ptr,int &mx,int depth){
        if(ptr==NULL)
            return;
        //we update he mx variable
        //mx is max between max depth upto now and depth of this node
        mx=max(mx,depth);
        dfs(ptr->left,mx,depth+1);
        dfs(ptr->right,mx,depth+1);
    }
    void dfs2(TreeNode *ptr,int &sum,int &mx,int depth){
        if(ptr==NULL)
            return;
        if(ptr->left==NULL&&ptr->right==NULL&&depth==mx)
            sum+=ptr->val;
        //call dfs on its neighbours/children
        dfs2(ptr->left,sum,mx,depth+1);
        dfs2(ptr->right,sum,mx,depth+1);
    }
    
};
