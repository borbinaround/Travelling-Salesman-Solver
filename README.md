# Travelling-Salesman-Solver
This travelling salesman problem solver takes in a list of points, and calculates the shortest path between each point through a simple heuristic.
This heuristic consists of creating a path of just the first element. In each iteration, it takes the next point and adds the element which is closest to it into the path until the final point, where it connects it to the first point.

If the names of each point are 1 character and the points are no larger than (20,20), the program can display a visual representation of just the points.
