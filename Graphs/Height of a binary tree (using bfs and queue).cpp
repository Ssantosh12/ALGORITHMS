
/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
    int height(Node* root) {
        // Write your code here.
        int ht=0;
        queue<Node *> q;
        queue<int> qht;
        q.push(root); 
        qht.push(0);
        while(!q.empty()){
            ht=max(ht,qht.front());
            if(q.front()->left!=NULL){
                q.push(q.front()->left);
                qht.push(qht.front()+1);
            }
            if(q.front()->right!=NULL){
                q.push(q.front()->right);
                qht.push(qht.front()+1);
            }
            q.pop();
            qht.pop();
        }
        return ht;
    }
