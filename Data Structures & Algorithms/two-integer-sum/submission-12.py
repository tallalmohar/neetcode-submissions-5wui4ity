class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        nmap = {}
        for i,n in enumerate(nums):
            diff = target - n
            if diff in nmap:
                return [nmap[diff],i]
            nmap[n] = i
        return []