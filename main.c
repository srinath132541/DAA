#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;
    bool* visited;
};

struct Queue {
    int* items;
    int front;
    int rear;
    int capacity;
};

struct Node* createNode(int v);
struct Graph* createGraph(int vertices);
void addEdge(struct Graph* graph, int src, int dest);
void resetVisited(struct Graph* graph);
void DFS(struct Graph* graph, int vertex);
void BFS(struct Graph* graph, int startVertex, int maxVertices);
void freeGraph(struct Graph* graph);

struct Queue* createQueue(int capacity) {
    struct Queue* q = malloc(sizeof(struct Queue));
    q->capacity = capacity;
    q->items = malloc(capacity * sizeof(int));
    q->front = -1;
    q->rear = -1;
    return q;
}

bool isEmpty(struct Queue* q) {
    return q->front == -1 || q->front > q->rear;
}

void enqueue(struct Queue* q, int value) {
    if (q->rear == q->capacity - 1) return;
    if (q->front == -1) q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(struct Queue* q) {
    if (isEmpty(q)) return -1;
    int item = q->items[q->front];
    q->front++;
    return item;
}

void freeQueue(struct Queue* q) {
    free(q->items);
    free(q);
}

struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(struct Node*));
    graph->visited = malloc(vertices * sizeof(bool));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = false;
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void resetVisited(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        graph->visited[i] = false;
    }
}

void freeGraph(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        struct Node* temp = graph->adjLists[i];
        while (temp) {
            struct Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph->adjLists);
    free(graph->visited);
    free(graph);
}

void DFS(struct Graph* graph, int vertex) {
    graph->visited[vertex] = true;
    printf("%d ", vertex);

    struct Node* adjList = graph->adjLists[vertex];
    while (adjList != NULL) {
        int connectedVertex = adjList->vertex;
        if (!graph->visited[connectedVertex]) {
            DFS(graph, connectedVertex);
        }
        adjList = adjList->next;
    }
}

void BFS(struct Graph* graph, int startVertex, int maxVertices) {
    struct Queue* q = createQueue(maxVertices);

    graph->visited[startVertex] = true;
    enqueue(q, startVertex);

    while (!isEmpty(q)) {
        int currentVertex = dequeue(q);
        printf("%d ", currentVertex);

        struct Node* adjList = graph->adjLists[currentVertex];
        while (adjList != NULL) {
            int adjVertex = adjList->vertex;
            if (!graph->visited[adjVertex]) {
                graph->visited[adjVertex] = true;
                enqueue(q, adjVertex);
            }
            adjList = adjList->next;
        }
    }
    freeQueue(q);
}

int main() {
    int vertices, edges;
    int src, dest, startVertex;

    printf("Enter the total number of vertices: ");
    if (scanf("%d", &vertices) != 1 || vertices <= 0) {
        printf("Invalid number of vertices.\n");
        return 1;
    }

    struct Graph* graph = createGraph(vertices);

    printf("Enter the total number of edges: ");
    if (scanf("%d", &edges) != 1 || edges < 0) {
        printf("Invalid number of edges.\n");
        freeGraph(graph);
        return 1;
    }

    printf("Enter edges format (source destination) using 0 to %d:\n", vertices - 1);
    for (int i = 0; i < edges; i++) {
        printf("Edge %d: ", i + 1);
        if (scanf("%d %d", &src, &dest) != 2) {
            printf("Invalid edge input syntax.\n");
            freeGraph(graph);
            return 1;
        }
        
        if (src >= vertices || dest >= vertices || src < 0 || dest < 0) {
            printf("Error: Vertex out of bounds! Must be between 0 and %d.\n", vertices - 1);
            i--;
            continue;
        }
        addEdge(graph, src, dest);
    }

    printf("\nEnter the starting vertex for traversal (0 to %d): ", vertices - 1);
    if (scanf("%d", &startVertex) != 1 || startVertex < 0 || startVertex >= vertices) {
        printf("Invalid starting vertex.\n");
        freeGraph(graph);
        return 1;
    }

    printf("\n--- Depth-First Search (DFS) ---\n");
    DFS(graph, startVertex);
    printf("\n");

    resetVisited(graph);

    printf("\n--- Breadth-First Search (BFS) ---\n");
    BFS(graph, startVertex, vertices);
    printf("\n");

    freeGraph(graph);
    return 0;
}
