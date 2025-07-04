

from typing import Optional
class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        oldToNew={} #hashmap
        def dfs(node):
            if node in oldToNew:
                return oldToNew[node]
            copy=Node(node.val)
            oldToNew[node]=copy
            for nei in node.neighbors:
                copy.neighbors.append(dfs(nei))
            return copy
        return dfs(node) if node else None