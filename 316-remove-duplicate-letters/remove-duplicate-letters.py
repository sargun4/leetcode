class Solution:
    def removeDuplicateLetters(self, s):
        for c in sorted(set(s)):
            suffix = s[s.index(c):]
            if set(suffix) == set(s):
                return c + self.removeDuplicateLetters(suffix.replace(c, ''))
        return ''

def removeDuplicateLetters(self, s):
    result = ''
    while s:
        i = min(map(s.rindex, set(s)))
        c = min(s[:i+1])
        result += c
        s = s[s.index(c):].replace(c, '')
    return result

def removeDuplicateLetters(self, s):
    rindex = {c: i for i, c in enumerate(s)}
    result = ''
    for i, c in enumerate(s):
        if c not in result:
            while c < result[-1:] and i < rindex[result[-1]]:
                result = result[:-1]
            result += c
    return result