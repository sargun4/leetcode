//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

 
class Solution{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n){
        vector<pair<int,int>> meetings;
        for(int i=0;i<n;i++){
            meetings.push_back({start[i],end[i]});
        }
        //sort based on end time
        sort(meetings.begin(),meetings.end(),[](pair<int,int> &a,pair<int,int> &b){
            return (a.second < b.second);
        });
        int maxmeetings=1,ending=meetings[0].second;
        for(int i=1;i<n;i++){
            if(meetings[i].first > ending){
                maxmeetings++;
                ending = meetings[i].second;
            }
        }
        return maxmeetings;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends