#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int src, dest, weight;
};

struct Subset {
    int parent;
    int rank;
};

int compareEdges(const void* a, const void* b) {
    struct Edge* aEdge = (struct Edge*)a;
    struct Edge* bEdge = (struct Edge*)b;
    return aEdge->weight - bEdge->weight;
}

int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

void Union(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    } else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    } else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

void KruskalMST(struct Edge edges[], int vertices, int totalEdges) {
    struct Edge* result = malloc((vertices - 1) * sizeof(struct Edge));
    int e = 0; 
    int i = 0; 

    qsort(edges, totalEdges, sizeof(struct Edge), compareEdges);

    struct Subset* subsets = malloc(vertices * sizeof(struct Subset));
    for (int v = 0; v < vertices; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < vertices - 1 && i < totalEdges) {
        struct Edge nextEdge = edges[i++];

        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        if (x != y) {
            result[e++] = nextEdge;
            Union(subsets, x, y);
        }
    }

    if (e < vertices - 1) {
        printf("\nError: The graph is disconnected. A single MST cannot span all vertices.\n");
    } else {
        printf("\n--- Minimum Spanning Tree (Kruskal's Algorithm) ---\n");
        printf("Edge \tWeight\n");
        int minimumCost = 0;
        for (i = 0; i < e; ++i) {
            printf("%d - %d \t%d\n", result[i].src, result[i].dest, result[i].weight);
            minimumCost += result[i].weight;
        }
        printf("Minimum Cost Spanning Tree: %d\n", minimumCost);
    }

    free(subsets);
    free(result);
}

int main() {
    int vertices, totalEdges;

    printf("Enter the total number of vertices: ");
    if (scanf("%d", &vertices) != 1 || vertices <= 0) {
        printf("Invalid number of vertices.\n");
        return 1;
    }

    printf("Enter the total number of edges: ");
    if (scanf("%d", &totalEdges) != 1 || totalEdges < 0) {
        printf("Invalid number of edges.\n");
        return 1;
    }

    struct Edge* edges = malloc(totalEdges * sizeof(struct Edge));

    printf("Enter edges format (source destination weight) using 0 to %d:\n", vertices - 1);
    for (int i = 0; i < totalEdges; i++) {
        printf("Edge %d: ", i + 1);
        if (scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight) != 3) {
            printf("Invalid edge input syntax.\n");
            free(edges);
            return 1;
        }

        if (edges[i].src >= vertices || edges[i].dest >= vertices || edges[i].src < 0 || edges[i].dest < 0) {
            printf("Error: Vertex out of bounds! Must be between 0 and %d.\n", vertices - 1);
            i--; 
            continue;
        }
    }

    KruskalMST(edges, vertices, totalEdges);

    free(edges);
    return 0;
}
