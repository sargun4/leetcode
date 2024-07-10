class Solution {
public:
    TreeNode* search(TreeNode* root, int target){ //to search node w target val in bt
        if(root==NULL) return NULL;
        if(root->val==target) return root;
        TreeNode* left=search(root->left,target);
        if(left) return left;
        TreeNode* right=search(root->right,target);
        return right;
    }
    void markParents(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parents){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node->left){
                q.push(node->left);
                parents[node->left]=node;
            }
            if(node->right){
                q.push(node->right);
                parents[node->right]=node;
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parents; // stores {node: parent}
        unordered_map<TreeNode*,bool>vis;
        markParents(root,parents);
        queue<TreeNode*> q;
        TreeNode* targetNode = search(root, target->val);
        if (targetNode == NULL) return {}; //empty vector if targetNode is not found
        vis[targetNode] = true;
        q.push(targetNode);//since we r starting bfs frm targetNode and traversing frm there
        int currlvl = 0;
        vector<int> ans;
        while(!q.empty()){
            int n=q.size();
            if (currlvl == k) { // Add the nodes at distance k to the result
                for(int i=0;i<n;i++){
                    TreeNode* node = q.front();
                    q.pop();
                    ans.push_back(node->val);
                }
                break;
            }
            for(int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left && !vis[node->left]) { //if lchild exists & not yet vis
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