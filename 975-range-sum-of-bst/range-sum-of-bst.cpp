class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root) return 0;
        int sum=0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if (node->val >= low && node->val <= high) {
                sum += node->val;
            }
            if (node->left && node->val > low) {
                q.push(node->left);
            }
            if (node->right && node->val < high) {
                q.push(node->right);
            }
        }
        return sum;
        
    }
};
 
// class Solution {
// public:
//     int rangeSumBST(TreeNode* root, int low, int high) {
//         if(root==NULL) return 0;
//         if(root->val < low) return rangeSumBST(root->right,low,high);
//         if(root->val > high) return rangeSumBST(root->left,low,high);
//         return root->val+rangeSumBST(root->left,low,high)+rangeSumBST(root->right,low,high);
//     }
// };