from collections import deque
 
class Solution:
    def nodeLevel(self, num_nodes, adjacency_list, target_node):
        # Initialize the queue with the starting node and its level
        queue = [[0, 0]] # Format: [node, level]
        current_position, queue_length = 0, 1 # Track current position in the queue and its length
        visited_nodes = set() # Keep track of visited nodes

        while current_position < queue_length:
            # Get the current node and its level from the queue
            current_node, current_level = queue[current_position]
            visited_nodes.add(current_node) # Mark the node as visited

            # Explore adjacent nodes
            for neighbor in adjacency_list[current_node]:
                if neighbor == target_node:
                    return current_level + 1 # Target node found, return its level
                elif neighbor not in visited_nodes:
                    queue.append([neighbor, current_level + 1]) # Add unvisited neighbors to the queue
                    queue_length += 1 # Increment the queue length

            current_position += 1 # Move to the next node in the queue

        return -1 # Target node not found within the graph
            

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        V,E = list(map(int, input().strip().split()))
        adj = [[] for i in range(V)]
        for i in range(E):
            a,b = map(int,input().strip().split())
            adj[a].append(b)
            adj[b].append(a)
        X=int(input())
        ob = Solution()
        
        print(ob.nodeLevel(V, adj, X))
# } Driver Code Ends