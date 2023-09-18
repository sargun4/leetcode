class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        d={}
        for i in range(len(mat)):
            d[i]=mat[i].count(1)
        # print(d)
        a = sorted(d.items(), key=lambda x: x[1]) 
        l=[]   
        for i in range(k):
            l.append(a[i][0])
        return l