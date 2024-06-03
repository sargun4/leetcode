// //O(N)
// class Solution {
// public:
//     int maxDepth(TreeNode* root) {
//         if(root==NULL) return 0;
//         int lh=maxDepth(root->left);
//         int rh=maxDepth(root->right);
//         return 1+max(lh,rh);
//     }
// };

// // BFS
class Solution {
public:
int maxDepth(TreeNode *root){
    if(root == NULL)
        return 0;
    int res = 0;
    queue<TreeNode *> q;
    q.push(root);
    while(!q.empty()){
        res++;
        int n = q.size();
        for(int i=0; i < n; i++){
            TreeNode *node = q.front();
            q.pop();
            if(node -> left != NULL)
                q.push(node -> left);
            if(node -> right != NULL)
                q.push(node -> right);
        }
    }
    return res;
}
};