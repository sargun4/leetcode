class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        vector<pair<int,int>> posn_speed_pairs;
        for(int i=0;i<n;i++){
            posn_speed_pairs.push_back({position[i],speed[i]});
        }

        sort(posn_speed_pairs.begin(),posn_speed_pairs.end());

        stack<float> fleets;                
        for(int i=n-1;i>=0;i--){
            float time = static_cast<float>(target - posn_speed_pairs[i].first) / static_cast<float>(posn_speed_pairs[i].second);

            fleets.push(time);

            stack<float> s= fleets;

            if(fleets.size()>=2){
                float t1=s.top();
                s.pop();
                float t2=s.top();
                s.pop();

                if(t1<=t2){// If car in front reaches the target first, remove the current car from fleet
                    fleets.pop();
                }
            }
        }
        return fleets.size();
     }
};