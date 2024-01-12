//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends

/*
struct Item{
    int value;
    int weight;
};
*/
class Solution{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n){
        //per unit
        vector<pair<double,int>> perkg;  //{perunitvalofitem,idx}
        for (int i=0;i<n;i++){
            // if (arr[i].weight != 0)
            int val=arr[i].value;
            int wt=arr[i].weight;
            perkg.push_back({static_cast<double>(val)/wt,i});
        }
        // sort based on per kg val
        sort(perkg.begin(),perkg.end());
        int i=n-1;
        double totalprofit=0.0;
        while(i>=0 && W>0){
            int idx=perkg[i].second;
            int v=arr[idx].value;
            int w=arr[idx].weight;
            if(W>=w){
                totalprofit+=v;
                W-=w;
            }else{
                totalprofit+=(static_cast<double>(v)/w)*W;
                W=0;
            }
            i--;
        }
        return totalprofit;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(6)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends