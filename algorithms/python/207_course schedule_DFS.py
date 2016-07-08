# http://www.tangjikai.com/algorithms/leetcode-207-208-course-schedule-i-ii
# If node v has not been visited, then mark it as 0.
# If node v is being visited, then mark it as -1. If we find a vertex marked as -1 in DFS, then there is a cycle.
# If node v has been visited, then mark it as 1. If a vertex was marked as 1, then no cycle contains v or its successors.
class Solution(object):
    def canFinish(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: bool
        """
        graph = [[] for x in range(numCourses)]
        visited = [0] * numCourses
        
        for course, pre in prerequisites:
            graph[course].append(pre)
        
        for i in range(numCourses):
            if not self.dfs(i, visited, graph):
                return False
        return True
    
    def dfs(self, i, visited, graph):
        if visited[i] == -1:
            return False
        elif visited[i] == 1:
            return True
        
        visited[i] = -1
        for j in graph[i]:
            if not self.dfs(j, visited, graph):
                return False
        visited[i] = 1
        return True
