PRACTICAL 1:

Summary :

This practical was used to implement and analyze five sorting algorithms: Bubble Sort, Selection Sort, Insertion Sort, Merge Sort, and Quick Sort. Each algorithm sorts the elements in ascending order, but their working methods and execution times are different.

Bubble Sort repeatedly compares and swaps adjacent elements.(Best Case: O(n)Average Case: O(n²)Worst Case: O(n²))

Selection Sort finds the smallest element and places it in the correct position.(Best Case: O(n²)Average Case: O(n²)Worst Case: O(n²))

Insertion Sort inserts each element into its proper place in the sorted part of the array.(Best Case: O(n) Average Case: O(n²)Worst Case: O(n²))

Merge Sort divides the array into smaller parts, sorts them, and merges them.(Best Case: O(n log n) Average Case: O(n log n)Worst Case: O(n log n))

Quick Sort selects a pivot element and partitions the array into smaller subarrays.(Best Case: O(n log n) Average Case: O(n log n)Worst Case: O(n²))

Conclusion :

From this practical, we learned that every sorting algorithm has its own advantages and disadvantages. Bubble Sort, Selection Sort, and Insertion Sort are simple but slower for large datasets. Merge Sort and Quick Sort are faster and more efficient for large datasets. We also understood that choosing the right sorting algorithm depends on the size of the data and the application requirements.

PRACTICAL 2 :

Summary :

In this practical, we implemented Linear Search and Binary Search algorithms and compared their execution time.

Linear Search checks each element one by one until the element is found.(Best Case: O(1)Average Case: O(n)Worst Case: O(n))

Binary Search searches by dividing the sorted array into two halves, so it is faster.(Best Case: O(1) Average Case: O(log n)Worst Case: O(log n))

Linear Search works on both sorted and unsorted arrays. Binary Search works only on sorted arrays.

Conclusion :

Linear Search is simple and works on both sorted and unsorted arrays. Binary Search is faster but works only on sorted arrays. The time analysis shows that Binary Search takes less time than Linear Search. Therefore, Binary Search is better for large sorted data, while Linear Search is suitable for small or unsorted data.

PRACTICAL-3

Summary

In this experiment, Heap Sort was implemented using Python. The algorithm first creates a Max Heap from the given elements and then repeatedly moves the largest element to the end of the list. The heap is adjusted after each step until the complete list is sorted. Execution time was also measured to observe the performance of the algorithm.

Conclusion

Heap Sort is an efficient sorting algorithm that provides O(n log n) time complexity in the best, average, and worst cases. It works in-place and is suitable for sorting large datasets. This experiment helped in understanding heap creation, heapify operations, element extraction, and sorting using a binary heap.

PRACTICAL-4

Summary

Factorial of a number was calculated using two methods: Iterative and Recursive. The iterative method uses a loop to multiply numbers from 1 to n, while the recursive method calls itself with n-1 until it reaches the base case of 0 or 1. Both methods produce the same factorial result.

Conclusion

The experiment helped understand the difference between iteration and recursion. The iterative method uses less memory, while the recursive method provides a simpler and more mathematical approach. Both methods have O(n) time complexity and can be used to calculate factorial effectively.

PRACTICAL-7

Summary

This practical involved implementing the Coin Change problem using a dynamic programming (tabulation) approach. The objective was to determine the minimum number of coin denominations required to construct a specific target currency amount. The program maintains a lookup array (dp) where each index represents an incremental amount up to the target, iteratively updating each state by evaluating available coin choices.Dynamic Programming Coin Change: Computes optimal coin sub-problems sequentially, avoiding redundant recalculations through bottom-up optimization.(Time Complexity: \(O(A \times N)\) | Space Complexity: O(A), where A is the target amount and N is the number of coin types)

Conclusion

This experiment successfully showcased the efficiency of Dynamic Programming over greedy algorithms, which can fail to find the optimal solution for non-standard coin denominations. By breaking the main currency problem down into smaller, overlapping sub-problems and storing their solutions, the program guarantees an absolute mathematically minimal coin count. This practical provided valuable insights into state transition tables, optimization bounds using INT_MAX, and array-driven memoization techniques.

PRACTICAL-5

Summary

This practical involved implementing the 0/1 Knapsack problem using a dynamic programming (tabulation) approach. The objective was to determine the maximum value achievable by selecting a subset of items without exceeding a specific weight capacity constraint. The program utilizes a two-dimensional lookup table (dp) where rows represent the subset of items and columns represent incremental weight capacities. By analyzing whether including or excluding the current item yields a higher profit, the algorithm iteratively builds up the optimal solution.Dynamic Programming 0/1 Knapsack: Computes optimal sub-problems sequentially, avoiding redundant recalculations through bottom-up optimization.Time Complexity: \((O(N \times W))\)Space Complexity: \((O(N \times W))\), where N is the total number of items and W is the maximum capacity of the knapsack.

Conclusion

This experiment successfully demonstrated the application of Dynamic Programming over a simple brute-force recursive strategy, which would otherwise result in an inefficient exponential time complexity. By utilizing a state transition matrix, the program successfully tracks optimal value choices for varying sub-capacities, guaranteeing an absolute mathematically maximum profit. This practical provided valuable insights into multi-dimensional array memoization, constraint-bound decision making, and the operational breakdown of overlapping sub-problems.

PRACTICAL-6

Summary

This practical involved implementing the Matrix Chain Multiplication problem using a dynamic programming (tabulation) approach. The objective was to determine the most efficient order to multiply a sequence of matrices by minimizing the total number of scalar multiplications. The program utilizes a two-dimensional lookup table (dp) to sequentially compute and store the optimal split costs for chains of increasing lengths. By evaluating the split choices iteratively, the algorithm determines the global minimum parenthesization cost without redundant calculations.Dynamic Programming Matrix Chain Multiplication: Computes optimal matrix sub-problems sequentially, avoiding exponential recursive overhead through diagonal bottom-up optimization.Time Complexity: O(N³)Space Complexity: O(N²), where N is the total number of elements in the dimensions array.

Conclusion

This experiment successfully demonstrated the application of Dynamic Programming over an exhaustive recursive strategy, which would otherwise result in an inefficient exponential time complexity. By utilizing a state transition matrix to store sub-chain operations, the program successfully determines the absolute mathematically minimal scalar multiplication operations required. This practical provided valuable insights into multi-dimensional diagonal array tabulation, nested window-based iteration, and optimal split boundary selection techniques.

PRACTICAL-8

Summary:

BFS and DFS are fundamental graph traversal algorithms, each employing a distinct strategy to explore nodes within a graph. BFS systematically explores nodes level by level, utilizing a queue to ensure all neighbors at the current depth are visited before proceeding to the next level. This makes it ideal for finding the shortest path in unweighted graphs. DFS, conversely, explores as deeply as possible along one path before backtracking, typically using a stack (or recursion) to manage its search. DFS is often used for tasks like cycle detection, topological sorting, and navigating tree-like structures.

Conclusion:

Both BFS and DFS are powerful tools in algorithm design, with their choice depending heavily on the specific problem at hand. Understanding their underlying mechanics – the queue for BFS's breadth-first exploration and the stack for DFS's depth-first exploration – is crucial for efficiently solving a wide range of computational problems, from pathfinding and network analysis to artificial intelligence and puzzle-solving.

PRACTICAL-9

Summary:

We implemented Prim's algorithm, a greedy algorithm used to find the Minimum Spanning Tree (MST) of a weighted, undirected graph. The algorithm starts from an arbitrary node and iteratively adds the cheapest edge that connects a vertex in the MST to a vertex outside the MST, until all vertices are included.
Two different implementations were provided and tested:
First Implementation (prim function): This version used string labels for nodes (e.g., 'A', 'B', 'C') and correctly identified the MST for a connected graph, as well as the MST for the connected component of a disconnected graph. Second Implementation (prims_algorithm function): This version used integer labels for nodes (e.g., 0, 1, 2) and also successfully calculated the MST and its total weight for its example graph.

Conclusion:

Both implementations successfully demonstrated Prim's algorithm by correctly identifying the edges forming the Minimum Spanning Tree and calculating their total weights for the given example graphs. The outputs confirm that the algorithm efficiently finds the MST by progressively adding the lowest-cost edges without forming cycles, ensuring that all reachable vertices are connected with the minimum possible total edge weight.

PRACTICAL-10

Summary

This practical involved implementing Kruskal’s Algorithm using a greedy approach to find the Minimum Spanning Tree (MST) of a weighted, undirected connected graph. The objective was to select a subset of edges that connects all vertices without forming cycles while minimizing the total edge weight. The program processes edge structures globally by sorting them in ascending order of their weights. To ensure cycle prevention during iterative edge addition, the algorithm utilizes the Disjoint Set Union (DSU) data structure optimized with Union by Rank and Path Compression subroutines. By verifying component connectivity dynamically, the program constructs the absolute mathematically minimal backbone network grid.
• Greedy Edge Processing: Evaluates individual sorted edge items sequentially, prioritizing lower local weights to assemble global structural optimization.
• Time Complexity: \(\mathcal{O}(E \log E)\) or \(\mathcal{O}(E \log V)\) due to the initial edge sorting boundary.
• Space Complexity: \(\mathcal{O}(V + E)\) to allocate memory tracks for tracking edge arrays and disjoint tree ranks, where \(V\) represents vertices and \(E\) represents edges.

Conclusion

This experiment successfully demonstrated the application of Kruskal’s greedy strategy over alternative matrix-scanning procedures, showcasing how complex network routing operations can be resolved without exhaustive exponential scanning. By utilizing a optimized Disjoint Set architecture with path compression, the program avoids cyclic deadlocks efficiently, reducing component lookups to near-constant inverse Ackermann time complexity (\(\mathcal{O}(\alpha(V))\)). This practical provided valuable insights into structural edge array manipulation, dynamic component partitioning systems, quick-sort partitioning implementations, and cycle validation rules within graph-theory architectures.
