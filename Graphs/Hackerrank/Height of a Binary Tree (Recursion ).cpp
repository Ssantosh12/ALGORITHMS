#include <bits/stdc++.h>

using namespace std;

/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};
//only the height function here

*/
    int height(Node* root) {
        // using bfs to find the height
        if(root==NULL)
        return -1;   //we return -1 because we initially supposed that there is a node there and we added its length (thats why we called fn with +1) 
        return 1+max(height(root->left),height(root->right));
        
    }
