class Solution:
    def buildMap(self, node, parent_val, graph): #create undirected graph
        if not node:
            return
        if node.val not in graph:
            graph[node.val] = []
            if parent_val is not None:
                graph[node.val].append(parent_val)
                graph[parent_val].append(node.val)
            self.buildMap(node.left, node.val, graph)
            self.buildMap(node.right, node.val, graph)
    def amountOfTime(self, root: Optional[TreeNode], start: int) -> int:
        graph = defaultdict(list) 
        self.buildMap(root, None, graph)
        # Print the created graph
        print("Graph:")
        for node, neighbors in graph.items():
            print(f"{node}: {neighbors}")
        if start not in graph:
            print("start node not in graph")
            return -1
        vis = set([start])
        q = deque([start])
        time = 0
        while q:
            size = len(q)
            for i in range(size):
                node = q.popleft()
                for neighbor in graph[node]:
                    if neighbor in vis:
                        continue
                    vis.add(neighbor)
                    q.append(neighbor)
            time += 1
        return time-1
 

# class Solution: 		
#     def amountOfTime(self, root: Optional[TreeNode], start: int) -> int:
#         graph = defaultdict(list)
#         q = [(root, None)]
#         while q: 
#             n, p = q.pop()
#             if p: 
#                 graph[p.val].append(n.val)
#                 graph[n.val].append(p.val)
#             if n.left: q.append((n.left, n))
#             if n.right: q.append((n.right, n))
#         ans = -1
#         vis = {start}
#         q = deque([start])
#         while q: 
#             for _ in range(len(q)): 
#                 u = q.popleft()
#                 for v in graph[u]: 
#                     if v not in vis: 
#                         vis.add(v)
#                         q.append(v)
#             ans += 1
#         return ans 