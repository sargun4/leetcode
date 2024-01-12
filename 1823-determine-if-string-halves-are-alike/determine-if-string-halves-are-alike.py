class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        s = list(s)
        n = len(s)
        mid = n // 2
        s1 = s[:mid]
        s2 = s[mid:]
        vowels = set("aeiouAEIOU")

        ctr1 = 0
        for i in s1:
            if i in vowels:
                ctr1 += 1

        ctr2 = 0
        for j in s2:
            if j in vowels:
                ctr2 += 1

        return ctr1 == ctr2
