class Solution {
public:
    int n;
    int canmakeMbouqets(vector<int>& bloomDay, int mid, int k){
        n=bloomDay.size();
        int bouqctr=0;
        int consecctr=0;
        for(int i=0;i<n;i++){
            if(bloomDay[i]<=mid){
                consecctr++;
            }else{
                consecctr=0;
            }
            if(consecctr==k){
                bouqctr++;
                consecctr=0;
            }
        }
        return bouqctr;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        n=bloomDay.size();
        int startday=0;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(maxi,bloomDay[i]);
        }
        int endday=maxi;
        int mindays=-1;

        //bin search
        while(startday<=endday){
            int mid=(startday+endday)/2;
            if(canmakeMbouqets(bloomDay,mid,k)>=m){
                mindays=mid;
                endday=mid-1;
            }else{
                startday=mid+1;
            }
        }
        return mindays;
    }
};