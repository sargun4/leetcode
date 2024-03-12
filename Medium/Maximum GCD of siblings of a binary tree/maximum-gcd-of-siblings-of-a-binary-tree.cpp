//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    int maxBinTreeGCD(vector<vector<int>> arr, int N) {
        unordered_map<int, pair<int, int>> map; // stores {parent, {leftchild, rightchild}}
        for (auto it : arr) {
            int parent = it[0];
            int child = it[1];
            if (map.find(parent) != map.end()) {
                if (map[parent].first == -1) {
                    map[parent].first = child;
                } else {
                    map[parent].second = child;
                }
            } else {
                map[parent] = {child, -1};
            }
        }

        int maxgcd = 0;
        for (auto it : map) {
            int parent = it.first;
            int lchild = it.second.first;
            int rchild = it.second.second;

            if (lchild != -1 && rchild != -1) {
                maxgcd = max(maxgcd, gcd(lchild, rchild));
            }
        } 
        return maxgcd;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,u,v;
        cin>>N;
        
        vector<vector<int>> arr;
        
        for(int i=0; i<N-1; i++)
        {
            cin>>u>>v;
            vector<int> edge;
            edge.push_back(u);
            edge.push_back(v);
            arr.push_back(edge);
        }

        Solution ob;
        cout << ob.maxBinTreeGCD(arr,N) << endl;
    }
    return 0;
}
// } Driver Code Ends