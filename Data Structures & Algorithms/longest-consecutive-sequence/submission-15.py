class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        numHash = set(nums)
        longest = 0
        for n in numHash:
            if (n-1) not in numHash:
                length = 1
                while (n+length) in numHash:
                    length+= 1
                longest = max(length,longest)
        return longest