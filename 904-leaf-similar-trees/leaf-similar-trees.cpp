 
class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1;
        vector<int> leaves2;
        dfs(root1,leaves1);
        dfs(root2,leaves2);
        return leaves1 == leaves2;
    }
    void dfs(TreeNode* node,vector<int>&leaves) {
        if(node==NULL) return;
        dfs(node->left,leaves);
        dfs(node->right,leaves); 
        if(!node->left && !node->right) leaves.push_back(node->val);
    }
};
 
// class Solution {
// public:
//     void inorder(TreeNode*root,string &s){
//         if(root==NULL) return;
//         //leaf node
//         if(root->left==NULL && root->right==NULL){
//             s+=to_string(root->val)+"_";
//             return; 
//         }
//         inorder(root->left,s);
//         inorder(root->right,s);
//     }
//     bool leafSimilar(TreeNode* root1, TreeNode* root2) {
//         string s1="";
//         string s2="";
//         inorder(root1,s1);
//         inorder(root2,s2);
//         // if(s1==s2) return true;
//         // return false;
//         return s1==s2;
//     }
// };