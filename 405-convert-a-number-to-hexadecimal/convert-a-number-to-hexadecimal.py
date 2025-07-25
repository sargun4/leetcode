# class Solution:
    # def toHex(self, num):
    #     if num==0: return '0'
    #     mp = '0123456789abcdef'  # like a map
    #     ans = ''
    #     for i in range(8):
    #         n = num & 15       # this means num & 1111b
    #         c = mp[n]          # get the hex char 
    #         ans = c + ans
    #         num = num >> 4
    #     return ans.lstrip('0')  #strip leading zeroes
class Solution:
    def toHex(self, num: int) -> str:
        if num < 0: num = num + 2**32
        ret = ''
        d = '0123456789abcdef'
        while num >= 16:
            a = num % 16
            ret += str(d[a])
            num //= 16
        ret += d[num]
        return ret[::-1]

    # Main ideal is to flip the negative number to positive by using following code:
    # num = num + 2**32