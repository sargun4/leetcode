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
TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q) {
        // If the current node is NULL, return NULL
        if (root == NULL) {
            return NULL;
        }

        // If the current node is p or q, return the current node
        if (root == p || root == q) {
            return root;
        }

        // Recur for the left and right subtrees
        TreeNode* left = lca(root->left, p, q);
        TreeNode* right = lca(root->right, p, q);

        // If both left and right are non-NULL, the current node is the LCA
        if (left != NULL && right != NULL) {
            return root;
        }

        // If only one of them is non-NULL, return the non-NULL node
        return left != NULL ? left : right;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
                if (!root) return 0; 
        //lvl order
        vector<vector<TreeNode*>>res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<TreeNode*> lvl;
            for(int i=0;i<n;i++){
                TreeNode*node=q.front();
                q.pop();
                if(node) lvl.push_back(node);
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            res.push_back(lvl);
        }
        int n=res.size();
        vector<TreeNode*> lastlvl = res[n - 1];
        // Find the LCA of all nodes in the last level
        TreeNode* lcaNode = lastlvl[0];
        for (int i = 1; i < lastlvl.size(); i++) {
            lcaNode = lca(root, lcaNode, lastlvl[i]);
        }
        return lcaNode;
    }
};