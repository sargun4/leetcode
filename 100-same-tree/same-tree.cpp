class Solution {
    public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL) return true;
        if(p==NULL || q==NULL) return false; 
        if(p->val!=q->val) return false;
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};
// //bfs
// class Solution {
//     public:
//     bool isSameTree(TreeNode* p, TreeNode* q) {
//         if(p==NULL && q==NULL) return true;
//         if(p==NULL || q==NULL) return false; 
//         queue<TreeNode*> q1;
//         queue<TreeNode*> q2;
//         q1.push(p);
//         q2.push(q);
//         while(!q1.empty() && !q2.empty()){
//             TreeNode* node1=q1.front();
//             q1.pop();
//             TreeNode* node2=q2.front();
//             q2.pop();
//             if(node1->val!=node2->val) return false;

//             if(node1->left!=NULL && node2->left!=NULL){
//                 q1.push(node1->left);
//                 q2.push(node2->left);
//             }else if(node1->left!=NULL || node2->left!=NULL){
//                 return false;
//             }

//             if(node1->right!=NULL && node2->right!=NULL){
//                 q1.push(node1->right);
//                 q2.push(node2->right);
//             }else if(node1->right!=NULL || node2->right!=NULL){
//                 return false;
//             }
//         }
//         return true;
//     }
// };