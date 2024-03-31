
def bfs(graph, start):
    visited = set()                 # Set to keep track of visited nodes
    queue = []                      # Initialize a queue

    visited.add(start)             # Mark the start node as visited
    queue.append(start)            # Enqueue the start node

    while queue:
        node = queue.pop(0)        # Dequeue a node from the queue
        print(node, end=" ")       # Process the node
        for neighbor in graph[node]:  # Visit all neighbors of the current node
            if neighbor not in visited:
                visited.add(neighbor)  # Mark neighbor as visited
                queue.append(neighbor)  # Enqueue neighbor

# Depth-First Search (DFS) using a dictionary
def dfs(graph, start, visited=None):
    if visited is None:
        visited = set()                 # Set to keep track of visited nodes
    visited.add(start)                 # Mark the current node as visited
    print(start, end=" ")               # Process the node
    for neighbor in graph[start]:       # Visit all neighbors of the current node
        if neighbor not in visited:
            dfs(graph, neighbor, visited)  # Recursively call dfs for unvisited neighbors

# Example graph represented as a dictionary
graph = {
    'A': ['B', 'C'],
    'B': ['A', 'D', 'E'],
    'C': ['A', 'F', 'G'],
    'D': ['B'],
    'E': ['B'],
    'F': ['C'],
    'G': ['C']
}

print("BFS traversal:")
bfs(graph, 'A')
print("\nDFS traversal:")
dfs(graph, 'A')
