//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends


class Solution {
public:
    vector<int> merge(vector<int>& a1, vector<int>& a2) {
        int len1 = a1.size();
        int len2 = a2.size();
        int i = 0, j = 0;
        vector<int> merged;
        while (i < len1 && j < len2) {
            if (a1[i] < a2[j]) {
                merged.push_back(a1[i]);
                i++;
            } else {
                merged.push_back(a2[j]);
                j++;
            }
        }
        while (i < len1) {
            merged.push_back(a1[i]);
            i++;
        }
        while (j < len2) {
            merged.push_back(a2[j]);
            j++;
        }
        return merged;
    }
    vector<int> mergeKArraysHelper(vector<vector<int>>& arr, int start, int end) {
        if (start == end) {
            return arr[start];
        }
        int mid = (start + end) / 2;
        vector<int> arr1 = mergeKArraysHelper(arr, start, mid);
        vector<int> arr2 = mergeKArraysHelper(arr, mid + 1, end);
        return merge(arr1, arr2);
    }
    vector<int> mergeKArrays(vector<vector<int>>& arr, int K) {
        if (K == 0) return vector<int>();
        return mergeKArraysHelper(arr, 0, K - 1);
    }
};


//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends