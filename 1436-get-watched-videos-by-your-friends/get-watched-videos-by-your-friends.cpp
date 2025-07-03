// we want to find ONLY friends at the given level
// given level 1 - effectively means any people who are not the initial person
// level 2 means that we are inteansted only in the friend's friends, EXCLUDING friends of level 1 and the initial person
// level 3 means that we are inteansted only in the friend's friends's friends, EXCLUDING the initial person, friends of level 1 AND friends of level 2
// and so on...
class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        //from the starting id apply bfs to traverse frnds lvl wise
        //store the freq of watchedVideos at this lvl;
        //sort the videos by freq and lexicographically 
        int n=friends.size();
        vector<int> vis(n,0);
        queue<pair<int,int>> q;//{frnd_id,currlvl};
        q.push({id,0});//bfs frm given id at lvl 0
        vis[id]=1;
        vector<int> targetLvlFrnds;//frnds at target lvl='level'
        while(!q.empty()){//bfs
            auto curr=q.front(); q.pop();
            int idx=curr.first;
            int lvl=curr.second;
            if(lvl==level){//if currlvl matches the target lvl,store frnd idx
                targetLvlFrnds.push_back(idx);
                continue;//dont go deeper
            }
            for(int neigh_id:friends[idx]){//going to each frnd of curr person
                if(!vis[neigh_id]){
                    vis[neigh_id]=1;//mark as vis
                    q.push({neigh_id,lvl+1});
                }
            }
        }
        //get freq of watched videos from target lvl frnds
        unordered_map<string,int> map;//{vid_name:freq};
        for(int frnd_id:targetLvlFrnds){
            for(string &vid:watchedVideos[frnd_id]){
                map[vid]++;//freq of each vid wathced at that lvl 
            }
        }
        vector<pair<int,string>> temp;//{freq,vid_name};
        for(auto &[vid_name,freq] :map){//map to vector
            temp.push_back({freq,vid_name});
        }
        sort(temp.begin(),temp.end());//sort vids by freq
        vector<string> ans;
        for(auto &[freq,vid_name]:temp){
            ans.push_back(vid_name);
        }
        return ans;
    }
};