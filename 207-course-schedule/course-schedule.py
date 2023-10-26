class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        #map each cousre to prereq list
        preMap={i:[] for i in range(numCourses)}
        for course,prereq in prerequisites:
            preMap[course].append(prereq)
        #visitSet=all courses along the curr dfs path
        visitSet=set()
        def dfs(course):
            if(course in visitSet):
                return False
            if preMap[course]==[]:
                return True
            visitSet.add(course)
            for prereq in preMap[course]:
                if not dfs(prereq):
                    return False
            visitSet.remove(course)
            preMap[course]=[]
            return True
        for course in range(numCourses):
            if not dfs(course): return False
        return True