class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> freeArr;//store duration of free gaps
        //gap before the 1st meeting added
        freeArr.push_back(startTime[0]);
        //ith event
        //ith start - (i-1)th end = free gap duration;
        for(int i=1;i<startTime.size();i++){//gaps bw meetings
            freeArr.push_back(startTime[i]-endTime[i-1]);
        }
        //gap after last meeting added
        freeArr.push_back(eventTime-endTime[endTime.size()-1]);
        int i=0;//l idx of sliding window
        int j=0;//r idx
        int maxsum=0;//stores max sum of any (k+1) free gaps
        int currsum=0;//curr window sum;
        int n=freeArr.size();
        // Sliding window to find the max sum of k+1 consecutive free gaps
        while(j<n){
            currsum+=freeArr[j]; //expand window
            //if window size>k+1 shrink frm left
            if(i<n && j-i+1>k+1){
                currsum-=freeArr[i];
                i++;
            }
            if(j-i+1 == k+1)//valid window size
                maxsum=max(maxsum,currsum);
            j++;
        }
        return maxsum;
    }
};