#include <stdio.h>
#include <stdlib.h>


#define MAX_VERTICES 100

typedef struct {
    int adj_matrix[MAX_VERTICES][MAX_VERTICES];
    int vertex_values[MAX_VERTICES];
    int edge_values[MAX_VERTICES][MAX_VERTICES];
    int num_vertices;
} Graph;

Graph* create_graph() {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->num_vertices = 0;
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            graph->adj_matrix[i][j] = 0;
            graph->edge_values[i][j] = 0;
        }
        graph->vertex_values[i] = 0;
    }
    return graph;
}

int adjacent(Graph* graph, int x, int y) {
    if (x < 0 || x >= graph->num_vertices || y < 0 || y >= graph->num_vertices) {
        return 0;
    }
    return graph->adj_matrix[x][y];
}

int* neighbors(Graph* graph, int x, int* num_neighbors) {
    if (x < 0 || x >= graph->num_vertices) {
        *num_neighbors = 0;
        return NULL;
    }
    int* neighbors = (int*) malloc(graph->num_vertices * sizeof(int));
    int count = 0;
    for (int i = 0; i < graph->num_vertices; i++) {
        if (graph->adj_matrix[x][i]) {
            neighbors[count++] = i;
        }
    }
    *num_neighbors = count;
    return neighbors;
}

void add_vertex(Graph* graph, int x) {
    if (graph->num_vertices == MAX_VERTICES) {
        return;
    }
    graph->num_vertices++;
    graph->vertex_values[x] = 0;
}

void remove_vertex(Graph* graph, int x) {
    if (x < 0 || x >= graph->num_vertices) {
        return;
    }
    for (int i = 0; i < graph->num_vertices; i++) {
        graph->adj_matrix[x][i] = 0;
        graph->adj_matrix[i][x] = 0;
        graph->edge_values[x][i] = 0;
        graph->edge_values[i][x] = 0;
    }
    graph->vertex_values[x] = 0;
    graph->num_vertices--;
}

void add_edge(Graph* graph, int x, int y, int z) {
    if (x < 0 || x >= graph->num_vertices || y < 0 || y >= graph->num_vertices) {
        return;
    }
    graph->adj_matrix[x][y] = 1;
    graph->edge_values[x][y] = z;
}

void remove_edge(Graph* graph, int x, int y) {
    if (x < 0 || x >= graph->num_vertices || y < 0 || y >= graph->num_vertices) {
        return;
    }
    graph->adj_matrix[x][y] = 0;
    graph->edge_values[x][y] = 0;
}

int get_vertex_value(Graph* graph, int x) {
    if (x < 0 || x >= graph->num_vertices) {
        return 0;
    }
    return graph->vertex_values[x];
}

void set_vertex_value(Graph* graph, int x, int v) {
    if (x < 0 || x >= graph->num_vertices) {
        return;
    }
    graph->vertex_values[x] = v;
}

int get_edge_value(Graph *graph, int x, int y) {
    if (x < 0 || x >= graph->num_vertices || y < 0 || y >= graph->num_vertices) {
        return -1; // retorna -1 caso a aresta não exista
    }
    return graph->edge_values[x][y];
}

// Define o valor associado à aresta (x, y) para v
void set_edge_value(Graph *graph, int x, int y, int v) {
    if (x < 0 || x >= graph->num_vertices || y < 0 || y >= graph->num_vertices) {
        return;
    }
    graph->edge_values[x][y] = v;
}

int main() {
    Graph* graph = create_graph();
    add_vertex(graph, 0);
    add_vertex(graph, 1);
    add_vertex(graph, 2);
    add_edge(graph, 0, 1, 10);
    add_edge(graph, 1, 2, 20);
    add_edge(graph, 2, 0, 30);
    printf("Vertex values: %d %d %d\n", get_vertex_value(graph, 0), get_vertex_value(graph, 1), get_vertex_value(graph, 2));
    printf("Edge values: %d %d %d\n", get_edge_value(graph, 0, 1), get_edge_value(graph, 1, 2), get_edge_value(graph, 2, 0));
    remove_vertex(graph, 1);
    printf("Num vertices: %d\n", graph->num_vertices);
    free(graph);
    return 0;
}


