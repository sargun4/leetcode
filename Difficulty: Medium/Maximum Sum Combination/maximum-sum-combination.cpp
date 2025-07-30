//T- O(n log n + k log k)
// Sorting both arrays: O(n log n)
// Heap operations (each insertion/extraction takes O(log k)): O(k log k)
//S- O(n + k) heap and visited set can store up to O(k) elements.
using p=pair<int,pair<int,int>>;
class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k){
        int n=a.size();
        sort(a.begin(),a.end());//sort both arrs in asc
        sort(b.begin(),b.end());
        //maxheap
        priority_queue<p> pq;//{sum(a[i]+b[j]),{i,j}};
 // vis[i][j] = whether we have considered the sum a[i]+b[j] or not
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        //push largest poss sum (a[n-1]+b[n-1]);
        pq.push({a[n-1]+b[n-1],{n-1,n-1}});
        vis[n-1][n-1]=true;
        vector<int> ans;
        //extract top k sums;
        //extracts the largest sum, adds it to ans,
        // n explores adjacent pairs (i-1, j) and (i, j-1).
        while(k>0 && !pq.empty()){
            auto curr=pq.top(); pq.pop();
            int sum=curr.first;
            int i=curr.second.first;
            int j=curr.second.second;
            //add sum to ans;
            ans.push_back(sum);
         //as we have found one sum, decrement the value of k
            k--;
            //explore (i-1,j) if not yet vis
            if(i-1>=0 && !vis[i-1][j]){
                pq.push({a[i-1]+b[j],{i-1,j}});
                vis[i-1][j]=true;
            }
            //explore (i,j-1) if not vis
            if(j-1>=0 && !vis[i][j-1]){
                pq.push({a[i]+b[j-1],{i,j-1}});
                vis[i][j-1]=true;
            }
        }
        return ans;
    }
};