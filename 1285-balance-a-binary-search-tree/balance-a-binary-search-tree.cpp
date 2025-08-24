class Solution {
private:
    void inorder(TreeNode* root, vector<int>& in){
        if(root==NULL){
            return ;
        }
        inorder(root->left, in);
        in.push_back(root->val);
        inorder(root->right, in); 
    } 
    TreeNode* inorderToBst(int s, int e, vector<int>& inorderArr){
        if(s>e){
            return NULL; 
        } 
        int mid= (s+e)/2; 
        TreeNode* root = new TreeNode(inorderArr[mid]);
        root->left = inorderToBst(s,mid-1,inorderArr);
        root->right = inorderToBst(mid+1,e,inorderArr); 
        return root; 
    }
public:
    TreeNode* balanceBST(TreeNode* root) { 
        vector<int> inorderArr;
        inorder(root,inorderArr); 
        return inorderToBst(0, inorderArr.size()-1, inorderArr);
    }
};