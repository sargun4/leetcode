// Time Complexity: O(N) -N is the no of nodes in the tree
// Space Complexity: O(M): M is the maximum no in the tree at any lvl
class Solution {
public:
    // The idea is to use BFS, which is a common way to traverse the tree lvl by lvl
    // For a standard BFS, we can use queue to push the first root node into a queue
    // Then remove the front of the queue, add its children to back of the queue
    // Do the above steps until the queue is empty
    // We can simply use `lvl` to store the values of the nodes at current lvl, 
    // and add it back to `ans` once we've processed all nodes at that lvl
    vector<vector<int>> levelOrder(Node* root) {
        // the total no of nodes is between [0, 10 ^ 4]
        // check if root is nullptr to cover 0 node case
        if(!root)  return {};
        vector<vector<int>> ans;
        // bfs 
        queue<Node*> q;
        q.push(root); 
        while(!q.empty()) {
            int n = q.size(); 
            // lvl is used to store all the node values at the current lvl
            vector<int> lvl;
            // for each element in the current queue
            for(int i = 0; i < n; i++){
                //get the first node from the queue
                Node* node = q.front();
                // pop it
                q.pop();
                // add it to lvl
                lvl.push_back(node->val);
                // this node may include other nodes, we add them all to the queue
                for(auto n : node->children) q.push(n); 
            }
            // we've processed this lvl, add it to ans
            ans.push_back(lvl);
        }
        // return final ans
        return ans;
    }
};
// class Solution {
// public:
//     vector<vector<int>> levelOrder(Node* root) {
//         vector<vector<int>> res;
//         if (!root) return res;
//         queue<Node*> q;
//         q.push(root);
//         while (!q.empty()) {
//             size_t size = q.size();
//             vector<int> lvl;
//             for (int i = 0; i < size; i++) {
//                 Node* curr = q.front(); q.pop();
//                 lvl.emplace_back(curr->val);
//                 for (Node*& child: curr->children) {
//                     q.push(child);
//                 }
//             }
//             res.emplace_back(lvl);
//         }
//         return res;
//     }
// };