class Solution:
    def countTestedDevices(self, batteryPercentages: List[int]) -> int:
        n=len(batteryPercentages)
        td=0
        for i in range(n):
            if(batteryPercentages[i]>0):
                td+=1
                for j in range(i+1,n):
                    batteryPercentages[j]= max(0, batteryPercentages[j] - 1)
            else:
                pass 
        # print(td)  
        return td    