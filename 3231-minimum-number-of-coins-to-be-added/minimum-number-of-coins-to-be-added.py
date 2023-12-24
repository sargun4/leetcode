# class Solution:
#     def minimumAddedCoins(self, nums: List[int], target: int) -> int:
#         nums.sort()
#         current_max = 0
#         additions = 0
#         index = 0

#         while current_max < target:
#             if index < len(nums) and nums[index] <= current_max + 1:
#                 current_max += nums[index]
#                 index += 1
#             else:
#                 current_max += current_max + 1
#                 additions += 1

#         return additions
# # Approach
# # Check Contribution of Each Coin:

# # For each coin in the sorted array, check whether it can contribute to the current maximum value current_max.

# # If the current coin is less than or equal to current_max + 1, it means this coin can contribute to the next value in the sequence. Increment the current_max by the value of the coin, and move to the next coin.

# # Extend Reach by Adding a New Coin:

# # If the current coin cannot contribute to the next value coins[index] > current_max + 1, add a new coin to the array to extend the reach.
# # Increment the current_max by doubling its current value and then incrementing it by 1.
# # Increment the additions counter to keep track of the number of coins added.
# # Complexity
# # Time complexity : O (NlogN)

# # Space complexity: O(1)
class Solution:
    def minimumAddedCoins(self, coins: List[int], target: int) -> int:
        res = 0
        num = 0
        i = 0
        coins.sort()
        while num < target:
            if i < len(coins) and coins[i] <= num + 1:
                num += coins[i]
                i += 1
            else:
                res += 1
                num += num + 1
        return res

# Approach
# We will start with a range we can make of 0 and also sort the coins in increasing order to check for the smallest available coin, because that will be the easiest to add to our range. We are done when the range we can make includes the target.
# While our range is less than the target and we can add a coin from coins to it (any coin that is n + 1 or less where n is the rightbound of the range we can make), lets add the coin and extend the range. If we can no longer add any coins but still need some number, that coin will have to be created. The best coin to add will always be n + 1 if the range we can make is [0,n] because that coin extends our range the most. Then our new range will be n + n + 1.
# Keep doing this until the range we can make covers the target and return the coins we added.