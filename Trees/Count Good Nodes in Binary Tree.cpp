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
    // subproblem/state defintion: number of good nodes in a subtree with 'root' as root node
    // and 'maxNodeRootToCurr' as the max node value from root to current node
    int goodNodesUptoSubtree(TreeNode* root, int maxNodeRootToCurr) {
        // base case:
        if(root==NULL)
            return 0;

        // transition:
        if(root->val>=maxNodeRootToCurr)
            return 1+goodNodesUptoSubtree(root->left,root->val)+goodNodesUptoSubtree(root->right,root->val);
        else
            return goodNodesUptoSubtree(root->left,maxNodeRootToCurr)+goodNodesUptoSubtree(root->right,maxNodeRootToCurr);
    }

    int goodNodes(TreeNode* root) {
        return goodNodesUptoSubtree(root,-1e4);
    }
};
