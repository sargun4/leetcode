// - Mark each node to its parent to traverse upwards
// - We will do a BFS traversal starting from the target node
// - As long as we have not seen our node previously, Traverse up, left, right until reached Kth distance
// - when reached Kth distance, break out of BFS loop and remaining node's values in our 
// queue is our result

class Solution {
    Node* findNode(Node* root, int target) {//find target node rec
        if(root==NULL){
            return NULL;
        }
        if (root->data ==target) {
            return root;
        }
        Node* leftResult=findNode(root->left, target);
        if (leftResult) {
            return leftResult;
        }
        return findNode(root->right, target);
    }
    void markParents(Node* root, unordered_map<Node*,Node*>&parent_track){
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            Node* curr=q.front();
            q.pop();
            if(curr->left){
                parent_track[curr->left]=curr;
                q.push(curr->left);
            }if(curr->right){
                parent_track[curr->right]=curr;
                q.push(curr->right);
            }
        }
    }
public:
    vector<int> KDistanceNodes(Node* root, int target, int k) {
        // return the sorted vector of all nodes at k dist
        unordered_map<Node*,Node*> parent_track; //stores {node:parent}
        markParents(root,parent_track);
        unordered_map<Node*,bool> vis;
        queue<Node*>q;

        Node* targetNode = findNode(root, target);
        if (targetNode == NULL) {
            return {};//target not found in the tree
        }
        q.push(targetNode);
        vis[targetNode] = true;
        int currlvl = 0;
        while(!q.empty()){//bfs to go upto k lvl frm target node and using our map
            int size=q.size();
            if(currlvl++ == k) break; //reched kth lvl
            for(int i=0;i<size;i++){
                Node* curr=q.front(); 
                q.pop();
                if(curr->left && !vis[curr->left]){ //check left
                    q.push(curr->left);
                    vis[curr->left]=true;
                }
                if(curr->right && !vis[curr->right]){ //check right
                    q.push(curr->right);
                    vis[curr->right]=true;
                }
                if(parent_track[curr] && !vis[parent_track[curr]]){ //check parent node
                    q.push(parent_track[curr]);
                    vis[parent_track[curr]]=true;
                }
            }
        }
        vector<int> res;
        while(!q.empty()){
            Node*curr=q.front();
            q.pop();
            res.push_back(curr->data);
        }
        sort(res.begin(), res.end());
        return res;
    }
}; 
 


