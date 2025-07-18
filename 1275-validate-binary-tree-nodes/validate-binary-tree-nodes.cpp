class Solution {
public:
    int findRoot(int n, vector<int>& leftChild, vector<int>& rightChild){
        unordered_set<int> children;
        children.insert(leftChild.begin(),leftChild.end());
        children.insert(rightChild.begin(),rightChild.end());
        for(int i=0;i<n;i++){
            if(children.find(i)==children.end()){//if node doesnt exist in children set- means it has no parent - so it is the root(i)
                return i;//root
            }
        }
        return -1;// No root found
    }
    // First of all, if we see a node multiple times during the DFS, it means a node has multiple parents (and there could be a cycle). We will use a set seen that keeps track of all the nodes we have seen so far during the traversal. When we move to a child, if child is already in seen, we can immediately return false since we would be visiting child for the second time.
    // Once the DFS finishes, every node we visited will be in seen. If the tree is connected, then the length of seen will be equal to n. If seen.length != n, it means that some nodes were not visited, and thus the tree must be disconnected. Thus, we can return seen.length == n at the end of the algorithm.
// This process is sufficient in validating a binary tree:
// If a binary tree does not have a root, then findRoot will return -1.
// If there is a node with more than one parent, then we will detect it with seen.
// If the tree is disconnected, then seen will hold less than n nodes at the end.
// If there is a cycle, then we will detect it with seen.
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int root=findRoot(n,leftChild,rightChild);
        if(root==-1) return false;//nor toor-invalid
        unordered_set<int> seen;
        stack<int> stack;
        seen.insert(root);
        stack.push(root);
        while(!stack.empty()){
            int node=stack.top();
            stack.pop();
            int children[]={leftChild[node],rightChild[node]};
            for(int child:children){
                if(child!=-1){
                    if(seen.find(child)!=seen.end()){
                        return false;//multiple paretns or cycle
                    }
                    stack.push(child);
                    seen.insert(child);
                }
            }
        }
        return seen.size()==n;//check if all nodes vis
    }
};