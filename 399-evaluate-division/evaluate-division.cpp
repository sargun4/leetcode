// Evaluate queries: For each query (x, y), perform a BFS starting from node x and searching for node y. During the BFS traversal, keep track of the product of the edge values encountered. If y is reached, return the product as the division result. If y is not reached or either x or y is not present in the adj, return -1.
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries){
        //make directed adj frm the nodes in equations
      //for each equation (a/b=k), add edges (a,b) & (b,a)to the adj with edge values k & 1/k, respectively
        unordered_map<string,unordered_map<string,double>> adj;
        //{node:{neigh,wt}};
        for(int i=0;i<equations.size();i++){
            string dividend=equations[i][0];//num
            string divisor=equations[i][1];//denom
            double val=values[i];//division val
            adj[dividend][divisor]=val;// a->b = k
            adj[divisor][dividend]=1/val;// b->a = 1/k
        }

        vector<double> res;

        for (auto& query : queries) {
            string dividend = query[0];
            string divisor = query[1];
            if (adj.find(dividend) == adj.end() || adj.find(divisor) == adj.end()) {//if either x or y is not present in adj, return -1.
                res.push_back(-1.0);
            } else {
                res.push_back(bfs(dividend, divisor, adj));
            }
        }
        return res;
    }
    //bfs to get path frm start to end
    double bfs(string&start,string&end,unordered_map<string,unordered_map<string,double>> &adj){
        queue<pair<string,double>> q; //{node,prod_till_this_node};
        unordered_set<string> vis;//to avoid cycles
        q.push({start,1.0});//start node,prod=1;
        while(!q.empty()){
            auto curr=q.front(); q.pop();
            string node=curr.first;
            double val=curr.second;
            if(node==end) return val;//found target node
            vis.insert(node);
            for(auto&neigh:adj[node]){
                string neighNode=neigh.first;
                double neighVal=neigh.second;
                if(vis.find(neighNode)==vis.end()){//neighNode not yet vis
                    q.push({neighNode,val*neighVal});
                }
            }
        }
        return -1.0;
    }
};