# Dikjstra algorith - short path

Find the shortest path to one vertice to all other vertices using vertices and edges, using an analogy to reality, the vertices are the cities and the edges are te roads that connect they \
Every vertice had some attributes:

-   Vertice
    -   List<\*edge> paths
    -   edge \*prev_path
    -   unsigned float best_distance
    -   bool explored

List paths is all the connections that vertice had \
prev_path is a path between this vertice and another, one from the List. Is used to rebuild the path, it's basicaly reverse-engineering because only build the short_path when reach the end-vertice \
prev_path is used to rebuild the shortest path between two vertices, when code reach the end-vertice \
best_distance is the distance between this vertice and the start-vertice, from default is infinite (in code will be 0) \
explored only tell if the code alredy have been here, if the vertice alredy explored \

Edges had another structure:

-   Edge
    -   Vertice *A, *B
    -   unsigned float distance

Vertice *A and *B store the vertices that edge connect \
unsigned distance is the distance between vertice A and B \

To find the shortest path bether two points, diskjtra use best_estimative logical

## Best_estimative

The best_estimative can be divided into two steps:

1. estimate the distance between actualy vertice and connected vertices, to every edge do:
    1. lets say the actualy vertice A, and the other vertice on edge is B
    2. get A best_distance
    3. add with edge distance
    4. if result is minor than B best_distance then:
        1. B best_distance = result
        2. B prev_path = A
    5. else do nothing
    6. repet 1-5 to all other paths
2.  check what path vertice had the minor best_distance and go to him

Usually represented to find the path from start vertice to ALL others, but can be used to find between start and end vertices \

## References

<https://www.w3schools.com/dsa/dsa_algo_graphs_dijkstra.php> \
<https://youtu.be/EFg3u_E6eHU>