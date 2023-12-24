class Solution:
    def minimumAddedCoins(self, nums: List[int], target: int) -> int:
        nums.sort()
        current_max = 0
        additions = 0
        index = 0

        while current_max < target:
            if index < len(nums) and nums[index] <= current_max + 1:
                current_max += nums[index]
                index += 1
            else:
                current_max += current_max + 1
                additions += 1

        return additions
# Approach
# Check Contribution of Each Coin:

# For each coin in the sorted array, check whether it can contribute to the current maximum value current_max.

# If the current coin is less than or equal to current_max + 1, it means this coin can contribute to the next value in the sequence. Increment the current_max by the value of the coin, and move to the next coin.

# Extend Reach by Adding a New Coin:

# If the current coin cannot contribute to the next value coins[index] > current_max + 1, add a new coin to the array to extend the reach.
# Increment the current_max by doubling its current value and then incrementing it by 1.
# Increment the additions counter to keep track of the number of coins added.
# Complexity
# Time complexity : O (NlogN)

# Space complexity: O(1)