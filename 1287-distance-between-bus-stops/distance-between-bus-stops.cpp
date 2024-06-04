class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int clockwisedist=0;
        int totaldist=0;
        int n=distance.size();
        for(int i=0;i<n;i++){
            if(start<destination && (i>=start && i<destination)){
                clockwisedist+=distance[i];
            }
            if(start>destination && (i>=start|| i<destination)){
                clockwisedist+=distance[i];
            }
            totaldist+=distance[i];
        }
        return min(clockwisedist,totaldist-clockwisedist);
    }
};