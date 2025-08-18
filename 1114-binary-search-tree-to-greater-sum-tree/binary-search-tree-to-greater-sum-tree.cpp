class Solution {//bfs
public: 
    TreeNode* bstToGst(TreeNode* root) {
        vector<int> vals;
        queue<TreeNode*> q;
        q.push(root);
        //bfs to get all node vals;
        while(!q.empty()){
            TreeNode* node=q.front(); q.pop();
            vals.push_back(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        //sort to get inc order 
        sort(vals.begin(),vals.end());
        unordered_map<int,int> map;//{nodeval:greaterSumVal};
        int sum=0;
        for(int i=vals.size()-1;i>=0;i--){
            sum+=vals[i];
            map[vals[i]]=sum;
        }   
        //bfs again to update each nodes val with its greaterSumVal;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front(); q.pop();
            node->val=map[node->val];
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        return root;
    }
};
// class Solution {//dfs
// public: 
//     int sum=0;
//     void solve(TreeNode* root){ //rev inorder- r root vals
//         if(root==NULL) return;
//         solve(root->right);
//         sum+=root->val;
//         root->val=sum;
//         solve(root->left);
//     }
//     TreeNode* bstToGst(TreeNode* root) {
//         sum=0;
//         solve(root);
//         return root;
//     }
// };