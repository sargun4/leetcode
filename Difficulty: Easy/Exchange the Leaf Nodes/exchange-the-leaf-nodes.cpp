class Solution {
public:
    void leaves(Node *root,vector<Node*>&l){
        if(!root) return;
        //if both left and right child are NULL- leaf node
        if(!root->left && !root->right){
            l.push_back(root);
            return;
        }
        leaves(root->left,l);
        leaves(root->right,l);
    }
    void pairwiseSwap(Node *root){
        vector<Node*> l;
        leaves(root,l);//all leaf nodes in order

        int n=l.size();
        // Loop through all leaves in steps of 2 for pairwise swap
        for(int i=0;i+1<n;i+=2){
            swap(l[i]->data,l[i+1]->data);
        }
    }
};