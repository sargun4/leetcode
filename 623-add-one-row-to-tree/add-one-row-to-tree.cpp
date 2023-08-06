class Solution { //DFS
public:
    TreeNode* add(TreeNode* root,int val,int depth,int currdepth){
        if(root==NULL) return NULL;
        if(currdepth==depth-1){
            TreeNode*lefttemp=root->left;
            TreeNode*righttemp=root->right;
            root->left=new TreeNode(val);
            root->right=new TreeNode(val);
            root->left->left=lefttemp;
            root->right->right=righttemp;
            return root;
        }
        root->left=add(root->left,val,depth,currdepth+1);
        root->right=add(root->right,val,depth,currdepth+1);
        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* newroot=new TreeNode(val);
            newroot->left=root;
            return newroot;
        }
        int currdepth=1;
        return add(root,val,depth,currdepth);
    }
};
// // DFS
// class Solution {
// public:  
//     TreeNode* add(TreeNode* root, int val, int depth, int curr) {
//         if(!root)
//             return NULL; 
//         if(curr == depth-1) {
//             TreeNode* lTemp = root->left;
//             TreeNode* rTemp = root->right;
//             root->left  = new TreeNode(val);
//             root->right = new TreeNode(val);
//             root->left->left = lTemp;
//             root->right->right = rTemp;
//             return root;
//         }
//         root->left  = add(root->left, val, depth, curr+1);
//         root->right = add(root->right, val, depth, curr+1);
//         return root;
//     }    
//     TreeNode* addOneRow(TreeNode* root, int val, int depth) {
//         if(depth == 1) {
//             TreeNode* newRoot = new TreeNode(val);
//             newRoot->left = root;
//             return newRoot;
//         }   
//         return add(root, val, depth, 1);
//     }
// };

// // BFS
// class Solution {
// public:
//     TreeNode* addOneRow(TreeNode* root, int v, int d) {
//         if(d == 1) {
//             TreeNode* newRoot = new TreeNode(v);
//             newRoot->left = root;
//             return newRoot;
//         }
//         queue<TreeNode*> q;
//         q.push(root);
//         int level = 0;
//         bool rowAdded = false;
//         while(!q.empty()) {
//             int n = q.size();
//             level++;
//             while(n--) {
//                 TreeNode* curr = q.front();
//                 q.pop();
//                 TreeNode* tempL = curr->left;
//                 TreeNode* tempR = curr->right;
//                 if(level == d-1) {
//                     curr->left  = new TreeNode(v);
//                     curr->right = new TreeNode(v);
//                     curr->left->left   = tempL;
//                     curr->right->right = tempR;
//                     rowAdded = true;
//                 }
//                 if(tempL)
//                     q.push(tempL);
//                 if(tempR)
//                     q.push(tempR);
//             }
//             if(rowAdded)
//                 break;
//         }
//         return root;
//     }
// };