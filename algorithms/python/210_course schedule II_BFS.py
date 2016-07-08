# http://www.tangjikai.com/algorithms/leetcode-207-208-course-schedule-i-ii
# zeroInDegree stores nodes without in-degree and degree puts number of in-degree for each node.
# If all nodes have in-degree, the graph has a cycle, no solution.
# According the method of topological sort, remove the nodes without in-degree one by one.
class Solution(object):
    def findOrder(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: List[int]
        """
        res = []
        zeroInDegree = set()
        degree = [0] * numCourses
        
        for course, pre in prerequisites:
            degree[course] += 1
        
        for i in range(len(degree)):
            if degree[i] == 0:
                zeroInDegree.add(i)
        
        if not zeroInDegree:
            return []
        
        queue = list(zeroInDegree)
        while queue:
            course = queue.pop(0)
            res.append(course)
            
            for cur, pre in prerequisites:
                if pre == course:
                    degree[cur] -= 1
                    if degree[cur] == 0:
                        queue.append(cur)
                        
        if sum(degree) == 0:
            return res
        return []
