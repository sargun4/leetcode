 class Solution {
public:
TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q) {
        //if curr node is NULL, return NULL
        if (root == NULL) {
            return NULL;
        }
        //if curr node is p or q, return the curr node
        if (root == p || root == q) {
            return root;
        }
        //recur for the left and right subtrees
        TreeNode* left = lca(root->left, p, q);
        TreeNode* right = lca(root->right, p, q);
        // If both left and right are non-NULL, the curr node is the LCA
        if (left != NULL && right != NULL) {
            return root;
        }
        //if only one of them is non-NULL, return the non-NULL node
        return left != NULL ? left : right;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if (!root) return 0; 
        //lvl order
        vector<vector<TreeNode*>>res;
        queue<TreeNode*> q;//bfs to get nodes at each depth
        q.push(root);
        while(!q.empty()){
            int n=q.size();//no of nodes at that lvl
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
        vector<TreeNode*> lastlvl = res[n - 1];//get the deepest/last lvl
        //if only one deepest node exists, it is the answer
        if (lastlvl.size() == 1) return lastlvl[0];

        //find LCA of all nodes in the last level
        TreeNode* lcaNode = lastlvl[0];
        //get LCA of all deepest nodes
        for (int i = 1; i < lastlvl.size(); i++){
            lcaNode = lca(root, lcaNode, lastlvl[i]);
        }
        return lcaNode;
    }
}; 