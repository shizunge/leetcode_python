# http://www.tangjikai.com/algorithms/leetcode-207-208-course-schedule-i-ii
# zeroInDegree stores nodes without in-degree and degree puts number of in-degree for each node.
# If all nodes have in-degree, the graph has a cycle, no solution.
# According the method of topological sort, remove the nodes without in-degree one by one.
class Solution(object):
    def canFinish(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: bool
        """
        zeroInDegree = set()
        degree = [0] * numCourses
        
        for pre in prerequisites:
            degree[pre[0]] += 1
        
        for i in range(len(degree)):
            if degree[i] == 0:
                zeroInDegree.add(i)
            
        if not zeroInDegree:
            return False
        
        while zeroInDegree:
            it = iter(zeroInDegree)
            course = it.next()
            zeroInDegree.remove(course)
            
            for i in range(len(prerequisites)):
                edge = prerequisites[i]
                if edge[1] == course:
                    degree[edge[0]] -= 1
                    if degree[edge[0]] == 0:
                        zeroInDegree.add(edge[0])
        
        return sum(degree) == 0
