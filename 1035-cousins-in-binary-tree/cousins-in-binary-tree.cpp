/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        // at the same level and not same parent!
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            bool f1=false,f2=false;
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                //if values found
                if(node->val==x) f1=true;
                if(node->val==y) f2=true;
                //checking if parent is same
                if(node->left && node->right){
                if((node->left->val==x && node->right->val==y)|| 
                 (node->left->val==y && node->right->val==x))
                    return false;
                }
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            if(f1&&f2)
                return true;
        } 
        return false;
    }
};