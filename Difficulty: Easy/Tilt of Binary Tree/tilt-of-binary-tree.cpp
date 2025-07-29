class Solution {
public:
    int ans=0;
    int tilt(Node*root){
        if(!root) return 0;
        int l=tilt(root->left);
        int r=tilt(root->right);
         ans+=abs(l-r);
        return l+r+root->data;
    }
    int tiltTree(Node *root) {
        tilt(root);
        return ans;
    }
};