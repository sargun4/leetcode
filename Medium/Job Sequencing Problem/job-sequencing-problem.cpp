//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

//T-O(Nlogn)
//S-O(N)
class Solution {
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n){ 
        //comparator func-sort jobs in desc order of profit
        sort(arr,arr+n,[](Job &a,Job &b){
            return (a.profit > b.profit);
        });
        vector<int> time(n+1,0);
        int totaljobs=0,totalprofit = 0;
        for(int i=0;i<n;i++){
            int id=arr[i].id;
            int deadline=arr[i].dead;
            int money=arr[i].profit;
            int hour=deadline;
            while(hour>=1){
                if(time[hour]==0){
                    time[hour]=1;
                    totaljobs+=1;
                    totalprofit+=money;
                    break;
                }else{
                    hour--;
                }
            }
        }
        return {totaljobs,totalprofit};
    } 
};



//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends