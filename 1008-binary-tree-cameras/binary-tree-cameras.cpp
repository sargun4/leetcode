 //a camera node can monitor 4nodes-itself,its parent & its left n right children; 
class Solution {
public:
    unordered_map<TreeNode*, vector<TreeNode*>> graph;
    unordered_map<TreeNode*, bool> visited;

    void buildGraph(TreeNode* node, TreeNode* parent) {
        if (!node) return;
        if (parent) {
            graph[node].push_back(parent);
            graph[parent].push_back(node);
        }
        buildGraph(node->left, node);
        buildGraph(node->right, node);
    }

    int dfs(TreeNode* node, TreeNode* parent, int &cameraCount) {
        visited[node] = true;
        bool hasChildNotCovered = false;
        bool hasChildWithCamera = false;

        for (TreeNode* neighbor : graph[node]) {
            if (neighbor == parent || visited[neighbor]) continue;

            int childState = dfs(neighbor, node, cameraCount);
            if (childState == 0) hasChildNotCovered = true;
            if (childState == 1) hasChildWithCamera = true;
        }

        if (hasChildNotCovered) {
            cameraCount++;
            return 1; // Place camera here
        }
        if (hasChildWithCamera) {
            return 2; // This node is covered
        }
        return 0; // This node is not covered
    }

    int minCameraCover(TreeNode* root) {
        if (!root) return 0;

        buildGraph(root, nullptr);
        int cameraCount = 0;

        int rootState = dfs(root, nullptr, cameraCount);
        if (rootState == 0) {
            cameraCount++; // Root needs camera
        }

        return cameraCount;
    }
};
