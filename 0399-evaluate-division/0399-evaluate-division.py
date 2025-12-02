from collections import defaultdict, deque
class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:

        # Build graph: variable -> list of (neighbor, weight)
        graph = defaultdict(list)
        
        for (u, v), k in zip(equations, values):
            graph[u].append((v, k))       # u / v = k
            graph[v].append((u, 1.0 / k)) # v / u = 1/k

        def bfs(start, end):
            # If either variable not present, can't compute
            if start not in graph or end not in graph:
                return -1.0
            # Trivial case
            if start == end:
                return 1.0
            
            # BFS queue: (node, accumulated_product_from_start)
            queue = deque([(start, 1.0)])
            visited = set([start])
            
            while queue:
                node, value = queue.popleft()
                if node == end:
                    return value
                for neighbor, weight in graph[node]:
                    if neighbor not in visited:
                        visited.add(neighbor)
                        queue.append((neighbor, value * weight))
            
            # Not reachable
            return -1.0

        # Answer each query
        return [bfs(x, y) for x, y in queries]
