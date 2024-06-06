class Solution {
public:
    long long dividePlayers(vector<int>& skillLevels) {
        sort(skillLevels.begin(), skillLevels.end());

        int n = skillLevels.size(); // no of players
        int sumfirstnlast = skillLevels[0] + skillLevels[n - 1];
        long long ans = 0;// sum of product of skills
      
        for (int left = 0, right = n - 1; left < right; left++, right--) {
            // If the pair doesn't add up to the sumfirstnlast, teams can't be balanced
            if (skillLevels[left] + skillLevels[right] != sumfirstnlast) {
                return -1;
            }
            // Add up product of the skills of the two players
            ans += static_cast<long long>(skillLevels[left]) * skillLevels[right];
        }
        return ans;
    }
};