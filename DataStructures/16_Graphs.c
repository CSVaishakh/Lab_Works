#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Structure for the graph
struct Graph {
    int numVertices;
    struct Node** adjLists;
    int* visited; // Array to track visited vertices
};

// Function to create a new adjacency list node
struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with a given number of vertices
struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(struct Node*));
    graph->visited = malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL; // Initialize each adjacency list as empty
        graph->visited[i] = 0; // Initialize visited array
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Since the graph is undirected, add an edge from dest to src also
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// BFS algorithm
void bfs(struct Graph* graph, int startVertex) {
    int queue[100], front = -1, rear = -1;

    // Mark the starting vertex as visited and enqueue it
    graph->visited[startVertex] = 1;
    queue[++rear] = startVertex;

    printf("BFS traversal: ");
    
    while (front != rear) {
        front++;
        int currentVertex = queue[front];
        printf("%d ", currentVertex);

        struct Node* temp = graph->adjLists[currentVertex];
        while (temp) {
            int adjVertex = temp->vertex;
            if (!graph->visited[adjVertex]) {
                graph->visited[adjVertex] = 1;
                queue[++rear] = adjVertex;
            }
            temp = temp->next;
        }
    }
}
// Function to display the graph structure
void displayGraph(struct Graph* graph) {
    printf("\nGraph adjacency list:\n");
    
    for (int i = 0; i < graph->numVertices; i++) {
        struct Node* temp = graph->adjLists[i];
        printf("%d: ", i);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}


// DFS algorithm using recursion
void dfs(struct Graph* graph, int vertex) {
    graph->visited[vertex] = 1;
    printf("%d ", vertex);

    struct Node* temp = graph->adjLists[vertex];
    while (temp) {
        int adjVertex = temp->vertex;
        if (!graph->visited[adjVertex]) {
            dfs(graph, adjVertex);
        }
        temp = temp->next;
    }
}

int main() {
    int vertices, choice, startVertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    struct Graph* graph = createGraph(vertices);

    printf("Enter edges (source destination), -1 -1 to stop:\n");
    
    while (1) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        if (src == -1 && dest == -1)
            break;
        addEdge(graph, src, dest);
    }

    do {
        printf("\nMenu:\n1. BFS\n2. DFS\n3. Display\nExit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                for (int i = 0; i < vertices; i++) 
                    graph->visited[i] = 0; // Reset visited array
                printf("Enter starting vertex for BFS: ");
                scanf("%d", &startVertex);
                bfs(graph, startVertex);
                break;

            case 2:
                for (int i = 0; i < vertices; i++) 
                    graph->visited[i] = 0; // Reset visited array
                printf("Enter starting vertex for DFS: ");
                scanf("%d", &startVertex);
                printf("DFS traversal: ");
                dfs(graph, startVertex);
                break;

            case 3:
                displayGraph(graph);
                break;
            case 4:
                ("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
        
    } while (choice != 4);

    return 0;
}