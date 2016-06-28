class Solution(object):
    def minimumTotal(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        """
        if (len(triangle)==1):
            return triangle[0][0]
        rt = [[triangle[0][0]]]
        rt_row_old = [triangle[0][0]]
        for row in triangle[1:]:
            rt_row = [rt_row_old[0]+row[0]]
            for i in range(1, len(row)-1,1):
                rt_row.append(min(rt_row_old[i-1], rt_row_old[i])+row[i])
            rt_row.append(rt_row_old[-1]+row[-1])
            rt_row_old = rt_row
        return min(rt_row_old)
