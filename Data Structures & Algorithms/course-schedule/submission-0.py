class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        # Build adjacency list
        graph = {i: [] for i in range(numCourses)}
        for course, prereq in prerequisites:
            graph[course].append(prereq)
        
        # 0 = unvisited, 1 = visiting, 2 = visited
        state = [0] * numCourses
        
        def hasCycle(course):
            if state[course] == 1:  # Currently visiting - cycle detected!
                return True
            if state[course] == 2:  # Already visited - no cycle from here
                return False
            
            # Mark as visiting
            state[course] = 1
            
            # Check all prerequisites
            for prereq in graph[course]:
                if hasCycle(prereq):
                    return True
            
            # Mark as visited
            state[course] = 2
            return False
        
        # Check each course
        for course in range(numCourses):
            if hasCycle(course):
                return False
        
        return True