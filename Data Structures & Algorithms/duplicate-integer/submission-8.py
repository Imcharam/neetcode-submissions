class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        dupl = set()
        for num in nums:
            if num in dupl:
                return True
            else:
                dupl.add(num)
        return False
        