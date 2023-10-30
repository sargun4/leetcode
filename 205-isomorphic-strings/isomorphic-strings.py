# Time Complexity : O(n)
class Solution(object):
    def isIsomorphic(self, s, t):
        map1 = []
        map2 = []
        for i in s:
            map1.append(s.index(i))
        for i in t:
            map2.append(t.index(i))
        if map1 == map2:
            return True
        # print(map1)
        # print(map2)
        return False