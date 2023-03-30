# exTeoriaComputacaoCaio

Título: Implementação de grafo em C

Objetivos: Implementar as operações básicas de um grafo utilizando a linguagem C, como adicionar e remover vértices e arestas, obter o valor de um vértice ou aresta, entre outras.

Instalação: Para executar o código, é necessário ter um compilador C instalado na máquina, como o GCC, CodeBlocks.

Como usar: O código implementa as seguintes funções:

Graph* create_graph(): Cria um novo grafo vazio e retorna um ponteiro para ele.
void add_vertex(Graph* graph, int x): Adiciona um vértice com valor x ao grafo.
void remove_vertex(Graph* graph, int x): Remove o vértice com valor x do grafo, bem como todas as arestas que o conectam a outros vértices.
void add_edge(Graph* graph, int x, int y, int z): Adiciona uma aresta com valor z entre os vértices x e y.
void remove_edge(Graph* graph, int x, int y): Remove a aresta entre os vértices x e y.
int adjacent(Graph* graph, int x, int y): Retorna 1 se existe uma aresta entre os vértices x e y, ou 0 caso contrário.
int* neighbors(Graph* graph, int x, int* num_neighbors): Retorna um ponteiro para um vetor com os valores dos vértices adjacentes a x, e atualiza a variável apontada por num_neighbors com o número de vértices adjacentes.
int get_vertex_value(Graph* graph, int x): Retorna o valor associado ao vértice x.
void set_vertex_value(Graph* graph, int x, int v): Define o valor associado ao vértice x como v.
int get_edge_value(Graph* graph, int x, int y): Retorna o valor associado à aresta entre os vértices x e y.
void set_edge_value(Graph* graph, int x, int y, int v): Define o valor associado à aresta entre os vértices x e y como v.
