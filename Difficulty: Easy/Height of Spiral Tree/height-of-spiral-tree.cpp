
// Return the height of the givn special binary tree
int findTreeHeight(Node* root){
    if(!root) return -1;
    if(root->left && root->right){
//Leaf Nodes are connected in Circular Doubly LinkedList Form
// Every leaf node right will point to next leaf node to form doubly linked list
        if(root->left->right==root && root->right->left==root){
            return 0;
        }
    }
    int lht=findTreeHeight(root->left);
    int rht=findTreeHeight(root->right);
    return 1+max(lht,rht);
}