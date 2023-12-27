class Solution:
    def buddyStrings(self, s: str, goal: str) -> bool:
        if len(s) != len(goal):
            return False
        #differing chars bw s and goal
        diff_chars = []
        for i in range(len(s)):
            if s[i] != goal[i]:
                diff_chars.append((s[i], goal[i]))
        if s == goal:
            # if there are duplicate chars in s
            return len(set(s)) < len(s)
        # if there are exactly two differnces and they form a buddy pair
        return len(diff_chars) == 2 and diff_chars[0] == diff_chars[1][::-1]
