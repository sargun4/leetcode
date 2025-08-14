class Solution {
public:
    //rec dfs to find and return target 
    TreeNode* search(TreeNode* root, int target){ //to search node w target val in bt
        if(root==NULL) return NULL;
        if(root->val==target) return root;
        TreeNode* left=search(root->left,target);
        if(left) return left;
        TreeNode* right=search(root->right,target);
        return right;
    }
//bfs to map each child to its parent for all nodes in tree
    void markParents(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parents){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node->left){
                q.push(node->left);
                parents[node->left]=node;//map lchild to parent
            }
            if(node->right){
                q.push(node->right);
                parents[node->right]=node;//map rchild to parent
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parents; //stores {node: parent}
        unordered_map<TreeNode*,bool>vis;//{node:T/F}
        markParents(root,parents);
        queue<TreeNode*> q;
        TreeNode* targetNode = search(root, target->val);
        if (targetNode == NULL) return {}; //empty vector if targetNode is not found
        vis[targetNode] = true;
        q.push(targetNode);//since we r starting bfs frm targetNode and traversing frm there
        int currlvl = 0;
        vector<int> ans;
        while(!q.empty()){
            int n=q.size();//no of nodes at curr lvl
            if (currlvl == k) { //add the nodes at dist k to the result
                for(int i=0;i<n;i++){
                    TreeNode* node = q.front();
                    q.pop();
                    ans.push_back(node->val);//collect all node vals
                }
                break;//dont go deeper
            }
            for(int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left && !vis[node->left]) { //if lchild exists & not yet vis
                    q.push(node->left);
                    vis[node->left] = true;
                }
//rchild
                if (node->right && !vis[node->right]) {
                    q.push(node->right);
                    vis[node->right] = true;
                }
//trav parent node
                if (parents[node] && !vis[parents[node]]) {
                    q.push(parents[node]);
                    vis[parents[node]] = true;
                }
            }
            currlvl++;//move to nxt lvl
        }
        return ans;//all nodes at dist k
    }
};