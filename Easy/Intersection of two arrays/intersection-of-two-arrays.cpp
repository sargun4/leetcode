//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Function to return the count of the number of elements in
    // the intersection of two arrays.
    int NumberofElementsInIntersection(int a[], int b[], int n, int m) {
        unordered_set<int> s;
        for (int i = 0; i < n; i++){
            s.insert(a[i]);
        }
        int ctr=0;
        for (int j = 0; j < m; j++){
            int key=b[j];
            if (s.find(key) != s.end()){
                ctr++;
                s.erase(key);
            }
        }
        return ctr;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n], b[m];
        for (int i = 0; i < n; i++) cin >> a[i];

        for (int i = 0; i < m; i++) cin >> b[i];
        Solution ob;
        cout << ob.NumberofElementsInIntersection(a, b, n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends