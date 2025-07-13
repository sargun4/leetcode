// count the pair of nodes that are at even distance(number of edges) from each other.
/*
  1) If we root the tree at any arbitrary node (say 1), each node can be classified into 
    two categories based on its depth (distance from the root):
        Even-depth nodes (distance from the root is even)
        Odd-depth nodes (distance from the root is odd)
    2) Any two nodes at even depths will have an even distance.
    3) Any two nodes at odd depths will also have an even distance.
    4) If one node is at even depth and another at odd depth, the distance is odd.
    
    If there are even_count nodes at even depth, the number of ways to choose 2 nodes from 
    them (i.e., the number of pairs) is given by the combination formula:

    even_count C 2 = even_count * (even_count - 1)/2
    
    Similarly, if there are odd_count nodes at odd depth, the number of pairs is :
    
    odd_count C 2 = odd_count * (odd_count - 1)/2*/
class Solution {
  public:
    int countOfNodes(vector<int> graph[], int n){
        vector<int>vis(n + 1, 0);
        vector<int>level(n + 1, 0);
        queue<int>q;
        q.push(1);
        vis[1] = 1;
        int even_count = 0, odd_count = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            if(level[node] % 2 == 0) even_count++;
            else odd_count++;
            for(auto neighbor : graph[node]) {
                if(!vis[neighbor]) {
                    vis[neighbor] = 1;
                    level[neighbor] = level[node] + 1;
                    q.push(neighbor);
                }
            }
        }
        // Compute valid pairs using nC2 = (n * (n - 1)) / 2
        int even_pairs = (even_count * (even_count - 1)) / 2;
        int odd_pairs = (odd_count * (odd_count - 1)) / 2;
        return even_pairs + odd_pairs;
    }
};