class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> expected = heights;
        sort(expected.begin(), expected.end());
                int n=heights.size();
        int ctr=0;
        int i=0; int j=0;
        while(i<n && j<n){
            if(heights[i]!=expected[j]){
                ctr++;
            }
            i++;
            j++;
        }
        return ctr;
    }
};