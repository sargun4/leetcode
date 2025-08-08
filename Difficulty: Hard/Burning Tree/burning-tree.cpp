class Solution {
public:
    int findMaxDist(map<Node*, Node*>& m, Node* target) {
        queue<Node*> q;
        q.push(target);
        map<Node*, int> vis;
        vis[target] = 1;
        int maxi = 0;
        while (!q.empty()) {
            int len = q.size();
            int flag = 0;
            for (int i = 0; i < len; i++) {
                auto node = q.front();
                q.pop();
                if (node->left && !vis[node->left]) {
                    flag = 1;
                    vis[node->left] = 1;
                    q.push(node->left);
                }
                if (node->right && !vis[node->right]) {
                    flag = 1;
                    vis[node->right] = 1;
                    q.push(node->right);
                }
                if (m[node] && !vis[m[node]]) {
                    flag = 1;
                    vis[m[node]] = 1;
                    q.push(m[node]);
                }
            }
            if (flag) maxi++;
        }
        return maxi;
    }

    Node* bfstoMapParents(Node* root, map<Node*, Node*>& m, int start) {
        queue<Node*> q;
        q.push(root);
        Node* res = NULL;
        while (!q.empty()) {
            Node* node = q.front();
            if (node->data == start){
                res=node;
            }
            q.pop();
            if (node->left) {
                m[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                m[node->right] = node;
                q.push(node->right);
            }
        }
        return res;
    }

    int minTime(Node* root, int target) {
        map<Node*, Node*> m;
        Node* start = bfstoMapParents(root, m, target);
        int maxi = findMaxDist(m,start);
        return maxi;
    }
};



