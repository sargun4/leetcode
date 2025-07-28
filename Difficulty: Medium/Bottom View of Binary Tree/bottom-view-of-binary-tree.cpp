// Start BFS with the root node and HD = 0
// For each node dequeued:
// Overwrite the value in the map for its HD (m[HD] = node->data) because the latest node at that HD will be bottom-most due to BFS
// Push the left and right children into the queue with HD - 1 and HD + 1 respectively
// After traversal, extract values from the map in order (sorted by HD) to get the bottom view
// Time: O(N log N) — due to insertion in map for N nodes
// Space: O(N) — for queue and map storage
class Solution {
  public:
    vector<int> bottomView(Node *root) {
        vector<int> ans;
        if(root==NULL) return ans;
        map<int,int> m;//{horiz_dist:node_data}, horiz_dist=vertline
        queue<pair<Node*,int>>q;//{node:vertline it is at}
        q.push({root,0});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            Node* node=it.first;
            int vertline=it.second;
            //for bottom view, always update the map with the curr node's val
            //it overwrites prev vals at this vertical level from higher lvls
            m[vertline]=node->data;
            if(node->left!=NULL){
                q.push({node->left,vertline-1});
            }if(node->right!=NULL){
                q.push({node->right,vertline+1});
            }
        }
        //map now contains the bottom-most node at each vertical distance
        //traverse map from leftmost to rightmost and add to answer
        for(auto it:m){
            ans.push_back(it.second);
        }
        return ans;
    }
};

