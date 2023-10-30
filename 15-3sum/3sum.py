class Solution:
    def threeSum(self, l):
        res=[]
        l.sort()
        length=len(l)
        for i in range(length-2):
            if i>0 and l[i]==l[i-1]:
                continue
            left=i+1
            right=length-1
            while left<right:
                total=l[i]+l[left]+l[right]
                if total<0:
                    left+=1
                elif total>0:
                    right-=1
                else:
                    res.append([l[i],l[left],l[right]])
                    while left<right and l[left]==l[left+1]:
                        left+=1
                    while left<right and l[right]==l[right-1]:
                        right-=1
                    left+=1
                    right-=1
        return res