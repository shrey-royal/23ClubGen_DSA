#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define MAX_NODES 100

int graph[MAX_NODES][MAX_NODES];
int numNodes;

//function protos
void initializeGraph();
void addEdge(int, int, int);
void adjacencyMatrix(int);
void depthFirstSearch(int startNode);
void breadthFirstSearch(int startNode);
void dijkstra(int startNode);
void bellmenFord(int startNode);
void prim();
void krushkal();

int main() {
    int choice;

    initializeGraph();

    do {
        printf("\nGraph Operations Menu:\n");
        printf("\n1. Depth-First Search");
        printf("\n2. Breadth-First Search");
        printf("\n3. Dijkstra's Algorithm");
        printf("\n4. Bellmen-Ford Algorithm");
        printf("\n5. Prim's Algorithm");
        printf("\n6. Krushkal's Algorithm");
        printf("\n7. Adjacency Matrix");
        printf("\n8. Exit");
    
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the starting node for DFS: ");
                int dfsStart;
                scanf("%d", &dfsStart);
                depthFirstSearch(dfsStart);
                break;

            case 2:
                printf("\nEnter the starting node for BFS: ");
                int bfsStart;
                scanf("%d", &bfsStart);
                breadthFirstSearch(bfsStart);
                break;

            case 3:
                printf("\nEnter the starting node for Dijkstra's Algorithm: ");
                int dijkstraStart;
                scanf("%d", &dijkstraStart);
                dijkstra(dijkstraStart);
                break;

            case 4:
                printf("\nEnter the starting node for BellmanFord's Algorithm: ");
                int bellmanFordStart;
                scanf("%d", &bellmanFordStart);
                bellmenFord(bellmanFordStart);
                break;

            case 7:
                adjacencyMatrix(numNodes);
                break;
            
            case 8:
                printf("Exiting program. GoodBye!\n");
                break;

            default:
                printf("Invalid Choice. Please enter a valid option.\n");
        }
    } while (choice != 8);

    return 0;
}

void initializeGraph() {
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &numNodes);

    //initialize
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter the edges in the graph (from to weight, -1 to stop): \n");
    int from, to, weight;
    while(1) {
        scanf("%d %d %d", &from, &to, &weight);
        if(from == -1 || to == -1 || weight == -1) break;
        addEdge(from, to, weight);
    }
}

void addEdge(int from, int to, int weight) {
    graph[from][to] = weight;
    // graph[to][from] = weight;   //for undirected graph
}

void adjacencyMatrix(int numNodes) {
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            printf("%d  ", graph[i][j]);
        }
        printf("\n");
    }
}

void depthFirstSearchUtil(int node, int visited[]) {
    printf("%d ", node);
    visited[node] = 1;

    for(int i=0; i<numNodes; i++) {
        if(graph[node][i] != 0 && !visited[i]) {
            depthFirstSearchUtil(i, visited);
        }
    }
}

void depthFirstSearch(int startNode) {
    int visisted[MAX_NODES] = {0};

    printf("Depth-First Search Starting from node %d: ", startNode);
    depthFirstSearchUtil(startNode, visisted);
    printf("\n");
}

void breadthFirstSearch(int startNode) {
    int queue[MAX_NODES];
    int front = -1, rear = -1;
    int visited[MAX_NODES] = {0};

    printf("Breadth-First Search starting from node %d: ", startNode);

    visited[startNode] = 1;
    queue[++rear] = startNode;

    while(front != rear) {
        int currentNode = queue[++front];
        printf("%d ", currentNode);

        for(int i=0; i<numNodes; i++) {
            if(graph[currentNode][i] != 0 && !visited[i]) {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }

    printf("\n");
}

/*
Here's a brief breakdown of what the code does:

- Initializes arrays for distances and visited nodes.
- Sets the distance from the start node to itself as 0 and initializes distances to other nodes as infinity.
- Iterates through each node to find the shortest path.
- Within the loop, it selects the node `u` that hasn't been visited yet and has the shortest distance.
- Marks `u` as visited.
- Updates distances to adjacent nodes if a shorter path is found through `u`.
- Finally, it prints the shortest distances from the start node to all other nodes.

This implementation assumes that `numNodes` is the number of nodes in the graph, `graph[u][v]` holds the weight of the edge between nodes `u` and `v` (0 if there's no edge), and `INT_MAX` represents infinity for the distances.

Do you need any specific clarification or additional information about this algorithm?

*/


void dijkstra(int startNode) {
    int distance[MAX_NODES];
    int visited[MAX_NODES] = {0};

    for(int i=0; i<numNodes; i++) {
        distance[i] = INT_MAX;
    }

    distance[startNode] = 0;

    for(int count=0; count < numNodes-1; count++) {
        int u = -1;

        for(int i=0; i<numNodes; i++) {
            if(!visited[i] && (u == -1 || distance[i] < distance[u])) u=i;
        }

        visited[u] = 1;

        for(int v=0; v < numNodes; v++) {
            if(graph[u][v] != 0 && !visited[v] && distance[u] != INT_MAX 
            && distance[u] + graph[u][v] < distance[v]) {
                distance[v] = distance[u] + graph[u][v];
            }
        }

        printf("Shortest distance from node %d using Dijkstra's Algorithm: \n", startNode);
        for(int i=0; i<numNodes; i++) {
            printf("Node %d: %d\n", i, distance[i]);
        }
    } 
}

void bellmenFord(int startNode) {
    int distance[MAX_NODES];

    for(int i=0; i<numNodes; i++) {
        distance[i] = INT_MAX;
    }

    distance[startNode] = 0;

    for(int count=0; count < numNodes-1; ++count) {
        for (int u=0; u<numNodes; ++u) {
            for(int v=0; v < numNodes; ++v) {
                if(graph[u][v] != 0 && distance[u] != INT_MAX 
                && distance[u] + graph[u][v] < distance[v]) {
                    distance[v] = distance[u] + graph[u][v];
                }
            }
        }

        printf("Shortest distance from node %d using BellmenFord's Algorithm: \n", startNode);
        for(int i=0; i<numNodes; i++) {
            printf("Node %d: %d\n", i, distance[i]);
        }
    } 
}

/*

0 1 2
0 2 4
1 2 1
1 3 7
2 3 3
3 4 1
-1 -1 -1

0 1 2
0 2 -4
1 2 1
1 3 7
2 3 -3
3 4 1
-1 -1 -1

   0  1  2  3  4
0  0  2  4  0  0
1  0  0  1  7  0
2  0  0  0  3  0
3  0  0  0  0  1
4  0  0  0  0  0 


Big:
  0  1  2  3  4  5  6  7  8
0 0  4  0  0  0  0  0  8  0
1 4  0  8  0  0  0  0  11  0
2 0  8  0  7  0  4  0  0  2
3 0  0  7  0  9  14  0  0  0
4 0  0  0  9  0  10  0  0  0
5 0  0  4  14  10  0  2  0  0
6 0  0  0  0  0  2  0  1  6
7 8  11  0  0  0  0  1  0  7
8 0  0  2  0  0  0  6  7  0
*/