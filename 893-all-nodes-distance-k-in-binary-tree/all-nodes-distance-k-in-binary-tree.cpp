 
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;
    void inorder(TreeNode* root) {
        if(!root) return;
        if(root->left) 
            parent[root->left] = root;
        inorder(root->left);
        if(root->right)
            parent[root->right] = root;
        inorder(root->right);
    }

    void bfs(TreeNode* target, int k, vector<int>& res) {
        queue<TreeNode*> q;
        q.push(target);
        unordered_set<int> vis;
        vis.insert(target->val);
        int lvl = 0;
        while (!q.empty()) {
            int n=q.size();
            if(lvl==k){
                for(int i=0;i<n;i++) {
                    TreeNode* curr=q.front();
                    q.pop();
                    res.push_back(curr->val);
                }
                return;
            }
            for (int i=0;i<n;i++) {
                TreeNode* curr=q.front();
                q.pop();
                if (curr->left && !vis.count(curr->left->val)) {
                    q.push(curr->left);
                    vis.insert(curr->left->val);
                }
                if (curr->right && !vis.count(curr->right->val)) {
                    q.push(curr->right);
                    vis.insert(curr->right->val);
                }
                if (parent.count(curr) && !vis.count(parent[curr]->val)) {
                    q.push(parent[curr]);
                    vis.insert(parent[curr]->val);
                }
            }
            lvl++;
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> res;
        inorder(root);
        bfs(target, k, res);
        return res;
    }
};
