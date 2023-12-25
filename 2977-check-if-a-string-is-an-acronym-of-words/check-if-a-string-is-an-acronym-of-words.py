class Solution:
    def isAcronym(self, words: List[str], s: str) -> bool:
        str=""
        for i in range(len(words)):
            str+=(words[i][0])
        if(s==str):
            return True
        else:
            return False
        