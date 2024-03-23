//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

#define MAX 1000

class Solution{
public:
    int largestRect(vector<int>& hist){
        stack<int> st;
        int maxarea = 0;
        int n = hist.size();
        for(int i = 0; i <= n; i++){
            while(!st.empty() && (i == n || hist[i] < hist[st.top()])){
                int ht = hist[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxarea = max(maxarea, width * ht); 
            }
            st.push(i);
        }
        return maxarea;
    }

    int maxArea(int M[MAX][MAX], int n, int m) { 
        int maxarea = 0;
        vector<int> ht(m, 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(M[i][j] == 1) ht[j]++;
                else ht[j] = 0;
            }
            int area = largestRect(ht);
            maxarea = max(area, maxarea);
        }
        return maxarea;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends