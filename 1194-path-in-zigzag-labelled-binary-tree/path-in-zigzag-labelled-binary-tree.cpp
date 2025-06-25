class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<vector<int>> tree;//Each row contains values at that lvl
        //[[1],[3,2],[4,5,6,7]]
        int val=1;
        bool rev = false;//is reversed flag
        //build tree until label is found
        while (val <= label) {
            int len =1<<tree.size();//2^lvl
            vector<int> lvl;
            for(int i = 0; i < len;i++) {
                lvl.push_back(val++);
            }
            if(rev)
                reverse(lvl.begin(), lvl.end());//reverse alt
            tree.push_back(lvl);
            rev=!rev;
        }
        //find the path from root to label
        vector<int> path;
        int lvl=tree.size()-1;
        //start from label, go upward to root
        while (lvl >= 0) {
            path.push_back(label);
            vector<int>& row = tree[lvl];
            //find idx of label in curr lvl
            int idx=find(row.begin(),row.end(),label) - row.begin();
            //move to parent(idx-wise, parent of idx=idx/2)
            lvl--;
            if (lvl >= 0) {
                int parentIdx = idx / 2;
                label = tree[lvl][parentIdx];
            }
        }
        reverse(path.begin(), path.end());
        return path;
    }
};
