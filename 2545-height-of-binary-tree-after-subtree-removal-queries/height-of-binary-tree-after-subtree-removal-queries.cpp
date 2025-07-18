class Solution {
public:
    unordered_map<int,int> ht;//ht of each node
    unordered_map<int,int> ans;//stores max ht after removing node
    
    int getHeight(TreeNode* root) {
        if(!root) return 0;
        int lht=getHeight(root->left);
        int rht=getHeight(root->right);
        return ht[root->val]=1+max(lht,rht);
    }
    //dfs to compute max ht after removal
    void dfs(TreeNode* root, int depthAbove, int maxAbove) {
        if(!root) return;
        //max ht excluding curr node = max from above path
        ans[root->val] = maxAbove;
        
        //get children's hts
        int lht = root->left ? ht[root->left->val] : 0;
        int rht = root->right ? ht[root->right->val] : 0;
        
        //for left child, max above includes right child's ht
        if(root->left)
            dfs(root->left,depthAbove+1,max(maxAbove,depthAbove+rht));
        
        //for right child, max above includes left child's ht
        if(root->right)
            dfs(root->right,depthAbove+1,max(maxAbove,depthAbove+lht));
    }
    
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        getHeight(root);//compute ht of each subtree
        dfs(root,0,0);//compute max ht after removal
        vector<int> res;
        for(int q:queries){
            res.push_back(ans[q]);
        }
        return res;
    }
};
// // 1. Perform DFS first to compute ht[node] (subtree heights).
// // 2. Then perform BFS level-order traversal:
// //  - For each level, compute prefix and suffix maximums of children's heights.
// //  - This allows us to compute the best alt height for every child excluding its own subtree.

// class Solution {
// public:
//   unordered_map<int,int> ht;//stores subtree ht
//   unordered_map<int,int> ans;//stores ans for each node

//   int getHeight(TreeNode* root){
//       if(!root) return 0;
//       int lht = getHeight(root->left);
//       int rht = getHeight(root->right);
//       return ht[root->val] = 1 + max(lht, rht);
//   }
//   void bfs(TreeNode* root){
//       queue<TreeNode*> q;
//       q.push(root);
//       ans[root->val] = 0;  // root removal → tree ht = 0
//       while(!q.empty()){
//           TreeNode* node = q.front(); q.pop();
//           vector<TreeNode*> children;
//           if(node->left) children.push_back(node->left);
//           if(node->right) children.push_back(node->right);
//           int n = children.size();
//           vector<int> pref(n+2,0), suff(n+2,0);
//           //build prefix max excluding child's own subtree
//           for(int i=0;i<n;i++)
//               pref[i+1] = max(pref[i], ht[children[i]->val]);
//           for(int i=n-1;i>=0;i--)
//               suff[i] = max(suff[i+1], ht[children[i]->val]);
//           for(int i=0;i<n;i++){
//               TreeNode* child = children[i];
//               //ht excluding this child = max(ans[node], prefix max, suffix max) + 1
//               int excludeChild = max(pref[i], suff[i+1]);
//               ans[child->val] = max(ans[node->val], excludeChild) + 1;
//               q.push(child);
//           }
//       }
//   }
//   vector<int> treeQueries(TreeNode* root, vector<int>& queries){
//       getHeight(root);
//       bfs(root);
//       vector<int> res;
//       for(int q: queries) res.push_back(ans[q]);
//       return res;
//   }
// };

