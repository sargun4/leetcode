//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to find common elements in three arrays.
    vector<int> commonElements(vector<int> &arr1, vector<int> &arr2,
                               vector<int> &arr3) {
       unordered_map<int,int>m1,m2,m3;
       vector<int> v;
       int n1=arr1.size();
       int n2=arr2.size();
       int n3=arr3.size();
       for(int i=0;i<n1;i++) m1[arr1[i]]++;
       for(int i=0;i<n2;i++) m2[arr2[i]]++;
       for(int i=0;i<n3;i++) m3[arr3[i]]++;
       
       for(int i=0;i<n1;i++){
           if(m1[arr1[i]]>0 && m2[arr1[i]]>0 && m3[arr1[i]]>0 ) {
               v.push_back(arr1[i]);
               //Stopping to print the duplicates
               m1[arr1[i]]=0;
           }
       }
       
       return v;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, brr, crr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            brr.push_back(number2);
        }
        string input3;
        getline(cin, input3);
        stringstream ss3(input3);
        int number3;
        while (ss3 >> number3) {
            crr.push_back(number3);
        }
        Solution ob;
        vector<int> res = ob.commonElements(arr, brr, crr);
        if (res.size() == 0)
            cout << -1;
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
}
// } Driver Code Ends