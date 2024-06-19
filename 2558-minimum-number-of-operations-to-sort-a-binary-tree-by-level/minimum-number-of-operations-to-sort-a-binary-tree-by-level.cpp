class Solution {
public:
    int minimumOperations(TreeNode* root) {
        int ans = 0;
        if (!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            vector<int> v;
            while (n--) {
                root = q.front();
                q.pop();
                v.push_back(root->val);
                if(root->left)
                    q.push(root->left);
                if(root->right) 
                    q.push(root->right);
            }
            unordered_map<int, int> map;
            for (int i=0; i<v.size(); i++)
                map[v[i]] = i;
            sort(v.begin(), v.end());
            int i=0;
            while (i < v.size()) {
                if (map[v[i]] != i) {
                    swap(v[i], v[map[v[i]]]);
                    ans++;
                }
                else i++;
            }
        }
        return ans;
    }
};