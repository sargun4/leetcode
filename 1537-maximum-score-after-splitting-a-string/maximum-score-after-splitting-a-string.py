class Solution:
    def maxScore(self, s: str) -> int:
        # s = "011101"
        n=len(s)
        subarrs=[]
        arr=[]
        for i in range(n-1):
            zero_ctr=0
            one_ctr=0
            lstr=s[:i+1]
            rstr=s[i+1:]
            subarrs.append([lstr,rstr])
            for j in lstr:
                if j=='0':
                    zero_ctr+=1
                else:
                    pass
            for j in rstr:
                if j=='1':
                    one_ctr+=1
                else:
                    pass
            ctr=zero_ctr+one_ctr
            arr.append(ctr)
        a=(max(arr))
        return a
        # print(a)
        # print(subarrs)
