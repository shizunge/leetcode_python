# http://blog.csdn.net/xudli/article/details/45886721
# House Robber I的升级版. 因为第一个element 和最后一个element不能同时出现. 则分两次call House Robber I. case 1: 不包括最后一个element. case 2: 不包括第一个element. 两者的最大值即为全局最大值
class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if (len(nums)==0):
            return 0
        if (len(nums)==1):
            return nums[0]
        dp1 = dp0 = 0
        for n in nums[0:-1]:
            dp = max(dp1, dp0+n)
            dp0 = dp1
            dp1 = dp
        case1 = dp1
        dp1 = dp0 = 0
        for n in nums[1:]:
            dp = max(dp1, dp0+n)
            dp0 = dp1
            dp1 = dp
        case2 = dp1
        return max(case1, case2)
# http://bookshadow.com/weblog/2015/05/20/leetcode-house-robber-ii/
# https://leetcode.com/discuss/36586/6-lines-function-body
"""
class Solution:
    def rob(self, nums):
        def rob(nums):
            now = prev = 0
            for n in nums:
                now, prev = max(now, prev + n), now
            return now
        return max(rob(nums[len(nums) != 1:]), rob(nums[:-1]))
"""
