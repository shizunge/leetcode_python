class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        if (n==1):
            return 1
        dp1 = 1
        dp2 = 2
        for i in range(2,n,1):
            dp2, dp1 = (dp1+dp2), dp2
        return dp2
