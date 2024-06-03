 
class RecentCounter {
public:
    unordered_map<int,int> map;
    RecentCounter() { 
    } 
    int ping(int t) {
        map[t]++;

        int ans = 0; 

        int lower = t - 3000, upper = t;
        for(auto &x : map){
            if(x.first >= lower && x.second <= upper){
                ans = ans + x.second;
            }
        }
        return ans;
    }
}; 