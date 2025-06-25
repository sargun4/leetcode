class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<vector<int>> tree;//each row contains vals at that lvl
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
                reverse(lvl.begin(), lvl.end());
            tree.push_back(lvl);
            rev=!rev;//reverse alt
        }
        //find the path from root to label
        vector<int> path;//ans
        int lvl=tree.size()-1;//no of rows-1
        //start from label, go upward to root
        while (lvl >= 0) {
            path.push_back(label);
            vector<int>& row = tree[lvl];
            //find idx of label in curr lvl
            int idx=find(row.begin(),row.end(),label) - row.begin();
            //move to parent(idx-wise, parent of idx=idx/2)
            lvl--;
            if (lvl >= 0) {
                int parentIdx=idx/2;
                label=tree[lvl][parentIdx];//label found
            }
        }
        reverse(path.begin(), path.end());//rev the l
        return path;
    }
};
