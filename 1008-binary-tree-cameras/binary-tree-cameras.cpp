 //a camera node can monitor 4nodes-itself,its parent & its left n right children; 

class Solution {
public:
    enum State { NOT_COVERED, HAS_CAMERA, COVERED };

    void buildGraph(TreeNode* node, TreeNode* parent,
                    unordered_map<TreeNode*, vector<TreeNode*>>& graph) {
        if (!node) return;
        if (parent) {
            graph[node].push_back(parent);
            graph[parent].push_back(node);
        }
        buildGraph(node->left, node, graph);
        buildGraph(node->right, node, graph);
    }

    int minCameraCover(TreeNode* root) {
        if (!root) return 0;

        unordered_map<TreeNode*, vector<TreeNode*>> graph;
        buildGraph(root, nullptr, graph);

        unordered_map<TreeNode*, int> state;
        unordered_set<TreeNode*> visited;

        function<int(TreeNode*, TreeNode*)> dfs = [&](TreeNode* node, TreeNode* parent) -> int {
            int childrenCameraCount = 0;
            bool childNotCovered = false;

            for (TreeNode* neighbor : graph[node]) {
                if (neighbor == parent) continue;
                int childState = dfs(neighbor, node);
                if (childState == NOT_COVERED) childNotCovered = true;
                if (childState == HAS_CAMERA) childrenCameraCount++;
            }

            if (childNotCovered) {
                state[node] = HAS_CAMERA;
                return HAS_CAMERA;
            }
            if (childrenCameraCount > 0) {
                state[node] = COVERED;
                return COVERED;
            }
            state[node] = NOT_COVERED;
            return NOT_COVERED;
        };

        int cameras = 0;
        if (dfs(root, nullptr) == NOT_COVERED) {
            cameras++;
        }

        for (auto& [node, val] : state) {
            if (val == HAS_CAMERA) cameras++;
        }

        return cameras;
    }
};
