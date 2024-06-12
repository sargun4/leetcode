class Solution {
public:
    TreeNode* search(TreeNode* root, int target) {
        if (root == NULL) return NULL;
        if (root->val == target) return root;
        TreeNode* left = search(root->left, target);
        if (left) return left;
        TreeNode* right = search(root->right, target);
        return right;
    }
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parents) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) {
                q.push(node->left);
                parents[node->left] = node;
            }
            if (node->right) {
                q.push(node->right);
                parents[node->right] = node;
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {        
        unordered_map<TreeNode*, TreeNode*> parents; // store {node: parent}
        markParents(root, parents);
        unordered_map<TreeNode*, bool> vis;
        queue<TreeNode*> q;
        TreeNode* targetNode = search(root, target->val);
        if (targetNode == NULL) return {}; //empty vector if targetNode is not found
        vis[targetNode] = true;
        q.push(targetNode);
        int currlvl = 0;
        vector<int> ans;
        while (!q.empty()) {
            int n = q.size();
            if (currlvl == k) { // Add the nodes at distance k to the result
                for (int i = 0; i < n; i++) {
                    TreeNode* node = q.front();
                    q.pop();
                    ans.push_back(node->val);
                }
                break;
            }
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left && !vis[node->left]) {
                    q.push(node->left);
                    vis[node->left] = true;
                }
                if (node->right && !vis[node->right]) {
                    q.push(node->right);
                    vis[node->right] = true;
                }
                if (parents[node] && !vis[parents[node]]) {
                    q.push(parents[node]);
                    vis[parents[node]] = true;
                }
            }
            currlvl++;
        }
        return ans;
    }
};

  
// class Solution {
// public:
//     unordered_map<TreeNode*, TreeNode*> parent;
//     void inorder(TreeNode* root) {
//         if(!root) return;
//         if(root->left) 
//             parent[root->left] = root;
//         inorder(root->left);
//         if(root->right)
//             parent[root->right] = root;
//         inorder(root->right);
//     }

//     void bfs(TreeNode* target, int k, vector<int>& res) {
//         queue<TreeNode*> q;
//         q.push(target);
//         unordered_set<int> vis;
//         vis.insert(target->val);
//         int lvl = 0;
//         while (!q.empty()) {
//             int n=q.size();
//             if(lvl==k){
//                 for(int i=0;i<n;i++) {
//                     TreeNode* curr=q.front();
//                     q.pop();
//                     res.push_back(curr->val);
//                 }
//                 return;
//             }
//             for (int i=0;i<n;i++) {
//                 TreeNode* curr=q.front();
//                 q.pop();
//                 if (curr->left && !vis.count(curr->left->val)) {
//                     q.push(curr->left);
//                     vis.insert(curr->left->val);
//                 }
//                 if (curr->right && !vis.count(curr->right->val)) {
//                     q.push(curr->right);
//                     vis.insert(curr->right->val);
//                 }
//                 if (parent.count(curr) && !vis.count(parent[curr]->val)) {
//                     q.push(parent[curr]);
//                     vis.insert(parent[curr]->val);
//                 }
//             }
//             lvl++;
//         }
//     }
//     vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
//         vector<int> res;
//         inorder(root);
//         bfs(target, k, res);
//         return res;
//     }
// };
