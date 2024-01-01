//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#include <bits/stdc++.h>
using namespace std; 
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        int n=nums.size();
        if(n%2==1){ //odd szie
            return false;
        }
        unordered_set<int> set;//store remainders
        for(int i=0;i<n;i++){
            int r1=nums[i]%k;
            int r2=k-r1;
            if(set.find(r2)!=set.end()){
                set.erase(r2);
            }else if (r1==0 && set.find(0)!=set.end()){
                set.erase(0);
           }else{
              set.insert(r1);
           }
        }
        return set.size()==0; //all matches found and removed frm set
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends