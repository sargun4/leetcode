// class Solution {
// public:
//     int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
//         int ans=0;
//         unordered_set<int> vis;
//         unordered_set<int> foundBoxes;

//         for(int &box:initialBoxes){
//             ans+=dfs(box,status,candies,keys,containedBoxes,vis,foundBoxes);
//         }
//         return ans;
//     }
//     int dfs(int box,vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes,unordered_set<int>&vis,unordered_set<int> &foundBoxes){
//         if(vis.count(box)){//if that box is alr visited, no more candies frm this box
//             return 0;
//         }
//         if(status[box]==0){//if the box is closed, we cant get candies frm here,but we mark it for future that we found this box
//             foundBoxes.insert(box);
//             return 0;
//         }
//         vis.insert(box);
//         int candiesFrmBox=candies[box];

//         for(int &insideBox:containedBoxes[box]){
//             candiesFrmBox+=dfs(insideBox,status,candies,keys,containedBoxes,vis,foundBoxes);
//         }
//         for(int &boxKey:keys[box]){//check for keys found in box that can open up other closed boxes(status==0)
//             status[boxKey]=1;//mark it as opend
//             if(foundBoxes.count(boxKey)){//if we alr seen this box earlier, we open it an get more candies frm it
//                 candiesFrmBox+=dfs(boxKey,status,candies,keys,containedBoxes,vis,foundBoxes);
//             }
//         }
//         return candiesFrmBox;
//     }
// };

//BFS
class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int ans=0;
        unordered_set<int> vis;
        unordered_set<int> foundBoxes;
        
        queue<int> q;//insert thsoe boxes which we hv now n can open
        for(int &box:initialBoxes){
            foundBoxes.insert(box);
            if(status[box]==1){
                q.push(box);
                vis.insert(box);
                ans+=candies[box];
            }
        }
        while(!q.empty()){
            int box=q.front();
            q.pop();

            for(int &insideBox:containedBoxes[box]){
                foundBoxes.insert(insideBox);
                if(status[insideBox]==1 && !vis.count(insideBox)){
                    q.push(insideBox);
                    vis.insert(insideBox);
                    ans+=candies[insideBox];
                }
            }
            for(int &boxKey:keys[box]){
                status[boxKey]=1;//can be opend in future if we reah this box;
                if(foundBoxes.count(boxKey) && !vis.count(boxKey)){
                    q.push(boxKey);
                    vis.insert(boxKey);
                    ans+=candies[boxKey];
                }
            }
        }
        return ans;
    }
};