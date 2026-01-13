#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100 

typedef int element;
element stack[MAX_STACK_SIZE]; 
int top = -1;
// 공백 상태 검출 함수 
int is_empty()
{
     return (top == -1);
}
// 포화 상태 검출 함수 
int is_full()
{
return (top == (MAX_STACK_SIZE - 1)); 
}
// 삽입 함수
void push(element item) 
{
    if (is_full()) {
    fprintf(stderr, "스택 포화 에러\n"); return;
    }
    else stack[++top] = item;  
}
// 삭제 함수 
element pop() 
{
    if (is_empty()) {
        fprintf(stderr, "스택 공백 에러\n"); 
        exit(1);
    }
    else return stack[top--]; 
}

// 스택 기능 함수 끝 

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50
typedef struct GraphType {
    int n;
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int visited[MAX_VERTICES];

void init(GraphType* g) {
    int r, c;
    g->n = 0;
    for (r = 0; r < MAX_VERTICES; r++)
        for (c = 0; c < MAX_VERTICES; c++)
            g->adj_mat[r][c] = 0;
}

void insert_vertex(GraphType* g, int v)
{
    if ((g->n) + 1 > MAX_VERTICES) {
        fprintf(stderr, "Too many vertices\n");
        return;
    }
    g->n++;
}

void insert_edge(GraphType* g, int start, int end)
{
    if (start >= g->n || end >= g->n) {
        fprintf(stderr, "Wrong vertex number\n");
        return;
    }
    g->adj_mat[start][end] = 1;
    g->adj_mat[end][start] = 1;
}

void dfs_iterate(GraphType* g, int v) {
    push(v);
    while (!is_empty()) {
        v = pop();
        if (!visited[v]) {
            visited[v] = 1;
            printf("정점 %d -> ", v);
            for (int u = 0; u < g->n; u++) { // 인접 정점 탐색합니다.
                if (g->adj_mat[v][u] && !visited[u]) { // 인접 정점이면서 방문하지 않은 정점이면
                    push(u); // 스택에 넣습니다.
                }
            }
        }
    }
}

int main()
{
    GraphType* g;
    g = (GraphType*)malloc(sizeof(GraphType));
    init(g);
    for (int i = 0; i < 4; i++)
        insert_vertex(g, i);
    insert_edge(g, 0, 1);
    insert_edge(g, 0, 2);
    insert_edge(g, 0, 3);
    insert_edge(g, 1, 2);
    insert_edge(g, 2, 3);

    printf("깊이 우선 탐색\n");
    dfs_iterate(g, 0);
    printf("\n");
    free(g);
    return 0;
}