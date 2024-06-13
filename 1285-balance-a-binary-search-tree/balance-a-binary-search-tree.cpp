 
class Solution {
private:
    void inorder(TreeNode* root, vector<int>& in){
        if(root == NULL){
            return ;
        }
        inorder(root->left, in);
        in.push_back(root->val);
        inorder(root->right, in); 
    } 
    TreeNode* inorderToBst(int s, int e, vector<int>& inorderVal){
        if(s>e){
            return NULL; 
        } 
        int mid  = (s+e)/2; 
        TreeNode* root = new TreeNode(inorderVal[mid]);
        root->left = inorderToBst(s, mid-1, inorderVal);
        root->right = inorderToBst( mid +1, e, inorderVal); 
        return root; 
    }
public:
    TreeNode* balanceBST(TreeNode* root) { 
        vector<int> inorderVal;
        inorder(root , inorderVal); 
        return inorderToBst(0, inorderVal.size()-1, inorderVal);

    }
};