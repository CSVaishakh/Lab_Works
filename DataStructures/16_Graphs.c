#include <stdio.h>
#include <stdlib.h>

// Structure for adjacency list node
struct Node {
    int vertex;
    struct Node* next;
};

// Structure for the graph
struct Graph {
    int numVertices;
    struct Node** adjLists;
    int* visited;
};

// Create a new node
struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Create a graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(struct Node*));
    graph->visited = malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

// Add edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest) {
    if (src >= graph->numVertices || dest >= graph->numVertices) {
        printf("Invalid vertex numbers! Please enter vertices from 0 to %d\n", 
               graph->numVertices - 1);
        return;
    }

    // Add edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
    
    printf("Edge added between %d and %d\n", src, dest);
}

// Display the adjacency list
void displayGraph(struct Graph* graph) {
    printf("\nAdjacency List Representation of the Graph:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        printf("Vertex %d:", i);
        struct Node* temp = graph->adjLists[i];
        while (temp) {
            printf(" -> %d", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

// BFS implementation
void BFS(struct Graph* graph, int startVertex) {
    if (startVertex >= graph->numVertices) {
        printf("Invalid starting vertex! Please enter a vertex from 0 to %d\n", 
               graph->numVertices - 1);
        return;
    }

    // Create a queue for BFS
    int queue[1000];
    int front = 0, rear = 0;

    // Reset visited array
    for(int i = 0; i < graph->numVertices; i++) {
        graph->visited[i] = 0;
    }

    // Mark the start vertex as visited and enqueue it
    graph->visited[startVertex] = 1;
    queue[rear++] = startVertex;

    printf("BFS starting from vertex %d: ", startVertex);

    while (front < rear) {
        // Dequeue a vertex and print it
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        // Get all adjacent vertices of the dequeued vertex
        struct Node* temp = graph->adjLists[currentVertex];
        while (temp) {
            int adjVertex = temp->vertex;
            if (graph->visited[adjVertex] == 0) {
                graph->visited[adjVertex] = 1;
                queue[rear++] = adjVertex;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

// DFS utility function
void DFSUtil(struct Graph* graph, int vertex) {
    graph->visited[vertex] = 1;
    printf("%d ", vertex);

    struct Node* temp = graph->adjLists[vertex];
    while (temp) {
        int adjVertex = temp->vertex;
        if (graph->visited[adjVertex] == 0) {
            DFSUtil(graph, adjVertex);
        }
        temp = temp->next;
    }
}

// DFS implementation
void DFS(struct Graph* graph, int startVertex) {
    if (startVertex >= graph->numVertices) {
        printf("Invalid starting vertex! Please enter a vertex from 0 to %d\n", 
               graph->numVertices - 1);
        return;
    }

    // Reset visited array
    for(int i = 0; i < graph->numVertices; i++) {
        graph->visited[i] = 0;
    }

    printf("DFS starting from vertex %d: ", startVertex);
    DFSUtil(graph, startVertex);
    printf("\n");
}

// Main function with menu
int main() {
    struct Graph* graph = NULL;
    int choice, vertices, src, dest, startVertex;

    while (1) {
        printf("\nGraph Operations Menu:\n");
        printf("1. Create Graph\n");
        printf("2. Add Edge\n");
        printf("3. Display Graph\n");
        printf("4. Perform BFS\n");
        printf("5. Perform DFS\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (graph != NULL) {
                    printf("Graph already exists! Create a new one? (1:Yes/0:No): ");
                    int confirm;
                    scanf("%d", &confirm);
                    if (!confirm) continue;
                    // Free existing graph if user confirms
                    free(graph->visited);
                    free(graph->adjLists);
                    free(graph);
                }
                printf("Enter number of vertices: ");
                scanf("%d", &vertices);
                if (vertices <= 0) {
                    printf("Please enter a positive number of vertices!\n");
                    continue;
                }
                graph = createGraph(vertices);
                printf("Graph created with %d vertices\n", vertices);
                break;

            case 2:
                if (graph == NULL) {
                    printf("Please create a graph first!\n");
                    continue;
                }
                printf("Enter source vertex: ");
                scanf("%d", &src);
                printf("Enter destination vertex: ");
                scanf("%d", &dest);
                addEdge(graph, src, dest);
                break;

            case 3:
                if (graph == NULL) {
                    printf("Please create a graph first!\n");
                    continue;
                }
                displayGraph(graph);
                break;

            case 4:
                if (graph == NULL) {
                    printf("Please create a graph first!\n");
                    continue;
                }
                printf("Enter starting vertex for BFS: ");
                scanf("%d", &startVertex);
                BFS(graph, startVertex);
                break;

            case 5:
                if (graph == NULL) {
                    printf("Please create a graph first!\n");
                    continue;
                }
                printf("Enter starting vertex for DFS: ");
                scanf("%d", &startVertex);
                DFS(graph, startVertex);
                break;

            case 6:
                if (graph != NULL) {
                    free(graph->visited);
                    free(graph->adjLists);
                    free(graph);
                }
                printf("Thank you for using the program!\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}