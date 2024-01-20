class Solution: 
    def merge(self, a1, a2):
        len1 = len(a1)
        len2 = len(a2)
        merged = []
        i = 0
        j = 0
        while i < len1 and j < len2:
            if a1[i] < a2[j]:
                merged.append(a1[i])
                i += 1
            else:
                merged.append(a2[j])
                j += 1
        while i < len1:
            merged.append(a1[i])
            i += 1
        while j < len2:
            merged.append(a2[j])
            j += 1
        return merged
    def mergeKArrays(self, arr, K):
        if K == 1:
            return arr[0]
        mid = K // 2
        b1 = self.mergeKArrays(arr[:mid], mid)
        b2 = self.mergeKArrays(arr[mid:], K - mid)
        result = self.merge(b1, b2)
        return result

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__=="__main__":
    t=int(input())
    for _ in range(t):
        n=int(input())
        numbers=[[ 0 for _ in range(n) ] for _ in range(n) ]
        line=input().strip().split()
        for i in range(n):
            for j in range(n):
                numbers[i][j]=int(line[i*n+j])
        ob = Solution();
        merged_list=ob.mergeKArrays(numbers, n)
        for i in merged_list:
            print(i,end=' ')
        print()
# } Driver Code Ends