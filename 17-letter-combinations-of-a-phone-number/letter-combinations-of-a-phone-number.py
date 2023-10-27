class Solution: 
    def letterCombinations(self, digits: str) -> List[str]:
        res=[]
        digitstoChar={
            "2":"abc",
            "3":"def",
            "4":"ghi",
            "5":"jkl",
            "6":"mno",
            "7":"pqrs",
            "8":"tuv",
            "9":"wxyz"
        }
        def backtrack(i,currstr):
            if(len(currstr)==len(digits)):
                res.append(currstr)
                return
            for c in digitstoChar[digits[i]]:
                backtrack(i+1,currstr+c)
        if len(digits)>0:
            backtrack(0,"")
        return res