class Solution:
    def winner(self, arr, n):
        d = {}
        for i in arr:
            if i not in d:
                d[i] = 1
            else:
                d[i] += 1

        max_votes = max(d.values())
        winners = [k for k, v in d.items() if v == max_votes]
        
        # Sort the winners lexicographically and pick the first one
        winner_name = min(winners)
        
        return [winner_name, str(max_votes)]


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__=="__main__":
    T=int(input())
    for _ in range(T):
        
        n=int(input())
        arr=input().strip().split()
        
        result = Solution().winner(arr,n)
        print(result[0],result[1])
# } Driver Code Ends