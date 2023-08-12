class Solution {
public:
    vector<vector<int>> lvlorder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res; // Added to handle empty tree case
        queue<TreeNode*> q;
        q.push(root); // Push the root node into the queue
        while (!q.empty()) {
            vector<int> lvl;
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                lvl.push_back(node->val);
                if (node->left != NULL) q.push(node->left);
                if (node->right != NULL) q.push(node->right);
            }
            res.push_back(lvl);
        }
        return res;
    }
    int maxLevelSum(TreeNode* root) {
        vector<vector<int>> lvls = lvlorder(root);
        int maxSum = INT_MIN;
        int maxLevel = -1;     
        for (int i = 0; i < lvls.size(); i++) {
            int sum = 0;
            for (int j = 0; j < lvls[i].size(); j++) {
                sum += lvls[i][j];
            }
            if (sum > maxSum) {
                maxSum = sum;
                maxLevel = i + 1; // Levels are 1-based
            }
        }       
        return maxLevel;
    }
};

// class Solution {
// public:
//     int maxLevelSum(TreeNode* root) {
//         //bfs
//         queue<TreeNode*> q;
//         q.push(root);
//         int ans = -1, maxSum = INT_MIN, level= 0;
//         while(!q.empty()){
//             level++;    //increase one level every time
//             int size = q.size(), sum = 0;
//             while(size--){
//                 auto node = q.front();
//                 q.pop();
//                 //sum the level's node
//                 sum += node->val;
//                 if(node->left) q.push(node->left);
//                 if(node->right) q.push(node->right);
//             }
//             //if the sum is greater than before store the level number
//             if(sum> maxSum){
//                 maxSum = sum;
//                 ans = level;
//             }
//         }
//         return ans;
//     }
// };