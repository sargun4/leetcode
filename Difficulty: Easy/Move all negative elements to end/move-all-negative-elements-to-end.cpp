//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
void segregateElements(vector<int>& arr) {
    vector<int> positive;
    queue<int> negative;

    // Separate positive and negative elements
    for (int num : arr) {
        if (num >= 0) {
            positive.push_back(num);
        } else {
            negative.push(num);
        }
    }
    // Combine positive and negative elements
    int index = 0;
    for (int num : positive) {
        arr[index++] = num;
    }
    while (!negative.empty()) {
        arr[index++] = negative.front();
        negative.pop();
    }
}
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        ob.segregateElements(nums);

        for (int x : nums)
            cout << x << " ";
        cout << endl;
    }
}
// } Driver Code Ends