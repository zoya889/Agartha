#include <stdio.h>
#include <stdlib.h>

#define MAX 100 

int graph[MAX][MAX]; 
int visited[MAX];    
int n;               

void DFS(int vertex) {
    visited[vertex] = 1;
    printf("%d ", vertex); 

    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

int main() {
    int edges, src, dest;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
        visited[i] = 0;
    }

    printf("Enter the edges (source and destination pairs):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        graph[src][dest] = 1; 
        graph[dest][src] = 1;
    }

    printf("DFS traversal starting from vertex 0:\n");
    DFS(0);

    return 0;
}
