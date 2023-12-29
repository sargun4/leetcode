class Solution {
public:
    vector < vector < int >> verticalTraversal(TreeNode * root) {
        map < int, map < int, multiset < int >>> nodes;
        queue < pair < TreeNode * , pair < int, int >>> q;
        q.push({root,{0,0}});//initial vertical and level
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            TreeNode * temp = p.first;
            //x -> vertical , y->level
            int x = p.second.first, y = p.second.second;
            nodes[x][y].insert(temp -> val); //inserting to multiset
            if (temp -> left) {
            q.push({temp -> left,{x - 1,y + 1}});
            }
            if (temp -> right) {
                q.push({temp -> right,{x + 1,y + 1}});
            }
        }
        vector < vector < int >> ans;
        for (auto p: nodes) {
            vector < int > col;
            for (auto q: p.second) {
            col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
        }
};

// //dfs
// class Solution {
// public:
//     vector<vector<int>> verticalTraversal(TreeNode* root) {
//         map<int, map<int, set<int>>> nodes;
//         traverse(root, 0, 0, nodes);
//         vector<vector<int>> ans;
//         for (auto p : nodes) {
//             vector<int> col;
//             for (auto q : p.second) {
//                 col.insert(col.end(), q.second.begin(), q.second.end());
//             }
//             ans.push_back(col);
//         }
//         return ans;
//     }
// private:
//     void traverse(TreeNode* root, int x, int y, map<int, map<int, set<int>>>& nodes) {
//         if (root) {
//             nodes[x][y].insert(root -> val);
//             traverse(root -> left, x - 1, y + 1, nodes);
//             traverse(root -> right, x + 1, y + 1, nodes);
//         }
//     }
// };