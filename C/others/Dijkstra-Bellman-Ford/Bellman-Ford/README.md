# Bellman-Ford
## ABOUT
### Introduction
- Imagine you have a map with different cities connected by roads, each road having a certain distance. The Bellman–Ford algorithm is like a guide that helps you find the shortest path from one city to all other cities, even if some roads have negative lengths. Useful for figuring out the quickest way to get from one point to another in a network.
### what`s Bellman-Ford 
- Bellman-Ford is a single source shortest path algorithm that, determines the shortest path between a given source vertex and every other vertex in a graph. This algorithm can be used on both weighted and unweighted graphs.
- A Bellman-Ford algorithm is also guaranteed to find the shortest path in a graph, similar to Dijkstra’s algorithm. Although Bellman-Ford is slower than Dijkstra’s algorithm, it is capable of handling graphs with negative edge weights. The shortest path cannot be found if there exists a negative cycle in the graph. If we continue to go around the negative cycle an infinite number of times, then the cost of the path will continue to decrease. As a result, Bellman-Ford is also capable of detecting negative cycles.
### The idea behind Bellman Ford Algorithm:
- The Bellman-Ford algorithm’s principle is starting with a single source and calculates the distance to each node. The distance is initially assumed to be infinite, the algorithm relaxes those paths by identifying a few shorter paths.
### Principle of Relaxation of Edges for Bellman-Ford:
- It states that for the graph having **N** vertices, all the edges should be relaxed **N-1** times to compute the single source shortest path.
- In order to detect whether a negative cycle exists or not, relax all the edge one more time and if the shortest distance for any node reduces then we can say that a negative cycle exists. If we relax the edges **N** times, and there is any change in the shortest distance of any node between the **N-1th** and **N**th relaxation, than a negative cycle exists, otherwise not exist.
### Why Relaxing Edges **N-1** times, gives us Single Source Shortest Path?
- In the worst-case scenario, a shortest path between two vertices can have at most **N-1** edges, where **N** is the number of vertices. This is because a simple path in a graph with **N** vertices can have at most **N-1** edges, as it’s impossible to form a closed loop without revisiting a vertex.
- By relaxing edges **N-1** times, the Bellman-Ford algorithm ensures that the distance estimates for all vertices have been updated to their optimal values, assuming the graph doesn’t contain any negative-weight cycles reachable from the source vertex. If a graph contains a negative-weight cycle reachable from the source vertex, the algorithm can detect it after N-1 iterations, since the negative cycle disrupts the shortest path lengths.
### Why Does the Reduction of Distance in the **N**’th Relaxation Indicates the Existence of a Negative Cycle?
- As previously discussed, achieving the single source shortest paths to all other nodes takes **N-1** relaxations. If the **N**’th relaxation further reduces the shortest distance for any node, it implies that a certain edge with negative weight has been traversed once more. It is important to note that during the **N-1** relaxations, we presumed that each vertex is traversed only once. However, the reduction of distance during the **N**’th relaxation indicates revisiting a vertex.
### Working of Bellman-Ford Algorithm to Detect the Negative cycle in the graph:
- [Tutorial here.](https://www.geeksforgeeks.org/bellman-ford   -algorithm-dp-23/#working-of-bellmanford-algorithm-to-detect-the-negative-cycle-in-the-graph)
### Algorithm to Find Negative Cycle in a Directed Weighted Graph Using Bellman-Ford:
- Initialize distance array dist[] for each vertex ‘v‘ as dist[v] = INFINITY.
- Assume any vertex (let’s say ‘0’) as source and assign dist = 0.
- Relax all the edges(u,v,weight) **N-1** times as per the below condition:
    - dist[v] = minimum(dist[v], distance[u] + weight)
- Now, Relax all the edges one more time i.e. the **N**th time and based on the below two cases we can detect the negative cycle:
    - Case 1 (Negative cycle exists): For any edge(u, v, weight), if dist[u] + weight < dist[v]
    - Case 2 (No Negative cycle) : case 1 fails for all the edges.
### Handling Disconnected Graphs in the Algorithm:
- The above algorithm and program might not work if the given graph is disconnected. It works when all vertices are reachable from source vertex 0.
- To handle disconnected graphs, we can repeat the above algorithm for vertices having distance = INFINITY, or simply for the vertices that are not visited.

### Bellman Ford’s Algorithm Applications:
- Network Routing: Bellman-Ford is used in computer networking to find the shortest paths in routing tables, helping data packets navigate efficiently across networks.
- GPS Navigation: GPS devices use Bellman-Ford to calculate the shortest or fastest routes between locations, aiding navigation apps and devices.
- Transportation and Logistics: Bellman-Ford’s algorithm can be applied to determine the optimal paths for vehicles in transportation and logistics, minimizing fuel consumption and travel time.
- Game Development: Bellman-Ford can be used to model movement and navigation within virtual worlds in game development, where different paths may have varying costs or obstacles.
- Robotics and Autonomous Vehicles: The algorithm aids in path planning for robots or autonomous vehicles, considering obstacles, terrain, and energy consumption.
### Complexity Analysis of Bellman-Ford Algorithm:
- Time Complexity when graph is connected:
    - Best Case: O(E), when distance array after 1st and 2nd relaxation are same , we can simply - stop further processing
    - Average Case: O(V*E)
    - Worst Case: O(V*E)
- Time Complexity when graph is disconnected:
    - All the cases: O(E*(V^2))
- Auxiliary Space: O(V), where V is the number of vertices in the graph.
### Drawback of Bellman Ford’s Algorithm:
- Bellman-Ford algorithm will fail if the graph contains any negative edge cycle.
- Related articles on single source shortest path algorithms:
    - Dijkstra’s Algorithm
    - Floyd-Warshall Algorithm
- "The DSA course helped me a lot in clearing the interview rounds. It was really very helpful in setting a strong foundation for my problem-solving skills. Really a great investment, the passion Sandeep sir has towards DSA/teaching is what made the huge difference." - Gaurav | Placed at Amazon
- Before you move on to the world of development, master the fundamentals of DSA on which every advanced algorithm is built upon. Choose your preferred language and start learning today: 

## Sources:
*(obs: y/m/d)*
- (2024/06/07) [greeksgeeksforgeeks](https://www.geeksforgeeks.org/bellman-ford-algorithm-dp-23/)