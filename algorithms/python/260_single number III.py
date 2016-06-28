class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        val1=0
        val2=0
        for i in nums:
            val1= val1^i
        mask = val1 & (~(val1-1))
        for i in nums:
            if (i & mask):
                val2= val2 ^ i
        return (val2, val1^val2)
