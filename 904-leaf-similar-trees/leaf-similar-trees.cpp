class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1 = getLeafSequence(root1);
        vector<int> leaves2 = getLeafSequence(root2);
        return leaves1 == leaves2;
    }
private:
    vector<int> getLeafSequence(TreeNode* root) {
        vector<int> leaves;
        if (!root)
            return leaves;
        stack<TreeNode*> stack;
        stack.push(root);
        while (!stack.empty()) {
            TreeNode* node = stack.top();
            stack.pop();
            if (!node->left && !node->right) {
                leaves.push_back(node->val);
            }
            if (node->right) {
                stack.push(node->right);
            }
            if (node->left) {
                stack.push(node->left);
            }
        }
        return leaves;
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