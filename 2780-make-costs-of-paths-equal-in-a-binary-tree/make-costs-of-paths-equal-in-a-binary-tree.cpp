class Solution {
public:
    int dfs(int n,vector<int> &cost,int i,int &ans) {
        if(i>n) return 0; 
        int lcost = dfs(n,cost,2*i,ans); //lchild
        int rcost = dfs(n,cost,2*i+1,ans); //rchild
        ans += abs(lcost - rcost);
        return max(lcost,rcost)+cost[i - 1];
    }
    int minIncrements(int n, vector<int>& cost) {
        int ans=0;
        dfs(n,cost,1,ans); //start idx i=1
        return ans;
    }
};

// We can move level by level from the the leaves and make sure that the adjacent nodes have equal cost. First make the cost of adjacent leaves equal. Then move one level up. Make sure that the cost of the two children are equal and so on. If they are not equal just increment the node with the lower cost to make it equal to the other node.