class Solution {
public:
    void inorder(TreeNode* root, vector<int>& nodes) {
        if (root == nullptr) return;
        inorder(root->left, nodes);
        nodes.push_back(root->val);
        inorder(root->right, nodes);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> nodes;
        inorder(root, nodes);
        int n = nodes.size();
        vector<vector<int>> res;
        for (int q : queries) {
            vector<int> arr(2, -1);

            // bin search for closest pred and succ
            int low = 0, high = n - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (nodes[mid] == q) {
                    arr[0] = arr[1] = q;
                    break;
                } else if (nodes[mid] < q) {
                    arr[0] = nodes[mid];
                    low = mid + 1;
                } else {
                    arr[1] = nodes[mid];
                    high = mid - 1;
                }
            }
            res.push_back(arr);
        }
        return res;
    }
};

//TLE
// class Solution {
// public:
//     TreeNode* search(TreeNode* root, int val) {
//         while (root != NULL && root->val != val) {
//             if (val < root->val) root = root->left;
//             else root = root->right;
//         }
//         return root;
//     }
//     TreeNode* inPred(TreeNode* root){
//         TreeNode* curr=root->left;
//         while(curr!=NULL && curr->right!=NULL){
//             curr=curr->right;
//         }
//         return curr;
//     }
//     TreeNode* inSucc(TreeNode* root){
//         TreeNode* curr=root->right;
//         while(curr!=NULL && curr->left!=NULL){
//             curr=curr->left;
//         }
//         return curr;
//     }
//     vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
//         int n=queries.size();
//         vector<vector<int>> res;
//         for(int i=0;i<n;i++){
//             int q=queries[i];
//             vector<int> arr(2, -1);
//             TreeNode* node = search(root, q);
//             if (node != nullptr) { //then mini=maxi=q;
//                 // Exact match found
//                 arr[0] = arr[1] = q;
//             } else {
//                 // Find closest pred
//                 TreeNode* pred = root;
//                 while (pred != nullptr) {
//                     if (q <= pred->val) {
//                         pred = pred->left;
//                     } else {
//                         arr[0] = pred->val;
//                         pred = pred->right;
//                     }
//                 }
//                 // Find closest succ
//                 TreeNode* succ = root;
//                 while (succ != nullptr) {
//                     if (q >= succ->val) {
//                         succ = succ->right;
//                     } else {
//                         arr[1] = succ->val;
//                         succ = succ->left;
//                     }
//                 }
//             }
//             res.push_back(arr);
//         }
//         return res;
//     }
// };