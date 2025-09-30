class Solution {
public:
    //check if two words differ in <= 2 positions
    bool isTwoEditsAway(string &a, string &b) {
        int diff = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                diff++;
                if (diff > 2) return false;
            }
        }
        return true;
    }

    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        for (auto &q : queries) {
            for (auto &w : dictionary) {
                if (isTwoEditsAway(q, w)) {
                    ans.push_back(q);
                    break; //no need to check other dictionary words
                }
            }
        }
        return ans;
    }
};
