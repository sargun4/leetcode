class Solution{
public:
    bool count(Node*root,int&ctr){
        if(!root) return true;
        bool l=count(root->left,ctr);
        bool r=count(root->right,ctr);
        //if either l or r subtree is not singlevalued, then curr subtree is also not single values
        if(!l || !r){
            return false;
        }
        
        //if left child of curr node exists but their vals dont match-not
        if(root->left && root->left->data!=root->data){
            return false;
        }
        //if right child of curr node exists but their vals dont match-not
        if(root->right && root->right->data!=root->data){
            return false;
        }
        // if(!root->left && !root->right){//leaf node
        //     return true;// subtree for a leaf node is always singleValued
        // }
        //else it is singlevalue subtree
        ctr++;
        return true;
        
    }
    int singlevalued(Node*root){
        int ctr=0;
        count(root,ctr);
        return ctr;
    }
};
