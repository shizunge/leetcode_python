# http://traceformula.blogspot.com/2015/08/single-number-ii-how-to-come-up-with.html
class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        p=0
        q=0
        r=0
        old_p=0
        for i in nums:
            r=i
            old_p=p
            p= (p & (~q) & (~r)) | ((~p) & q & r)
            q= ((~old_p) & q & (~r)) | ((~old_p) & (~q) & r)
        return q
