#include <stdio.h>
#include <stdlib.h>

typedef struct element{
    int key;
    struct element* left;
    struct element* right;
} element;
typedef struct HeapType {
    element* heap;
    int heap_size;
} HeapType;

HeapType* create_heap()  // 힙을 생성하는 함수입니다.
{
    return (HeapType*)malloc(sizeof(HeapType));
}

void init_heap(HeapType* h) // 힙을 초기화하는 함수입니다.
{
    h->heap = NULL;
    h->heap_size = 0;
}

element* new_element(int key) // 새로운 노드를 생성하는 함수입니다.
{
    element* e = (element*)malloc(sizeof(element));
    e->key = key;
    e->left = NULL;
    e->right = NULL;
    return e;
}

int is_empty(HeapType* h) // 힙이 비었는지 검사하는 함수입니다.
{
    return h->heap_size == 0;
}

element* find_parent(HeapType* h, int size) {
    element* parent = h->heap;
    // 루트 노드에서 시작합니다.
    int path = size >> 1; // size를 오른쪽 시프트해서 부모 노드의 경로를 찾습니다.

    // 루트에서 목표 노드의 부모까지 경로를 탐색합니다.
    while (path > 1) {
        if (path & 1) { // 1이면 오른쪽으로 이동합니다.
            parent = parent->right;
        } else { // 0이면 왼쪽 자식으로 이동합니다.
            parent = parent->left;
        }
        path >>= 1; // 다음 비트를 검사합니다.
    }
    return parent;
}

void insert_min_heap(HeapType* h, int key)
{
    element* e = new_element(key); // 새 노드 생성합니다.
    if (is_empty(h)) { // 빈 힙일땐 루트노드로 만듭니다.
        h->heap = e;
        h->heap_size++;
        printf("힙에 추가: %d\n", key);
        return;
    }

    int i = ++(h->heap_size); //힙 사이즈 증가시키고 
    element* parent = find_parent(h, i); // 새로 들어갈 위치의 부모노드를 찾습니다.

    // 새로운 노드를 부모노드의 자식으로 넣습니다.
    if (i % 2 == 0) {
        parent->left = e;
    } else {
        parent->right = e;
    }

    // 새로운 노드의 자리를 찾아 옮겨 최소 힙을 만듭니다.
    element* current = e;
    while (parent != NULL && parent->key > current->key) { // 부모노드의 값이 더 크면 교환합니다.
        int temp = parent->key; // parent노드랑 current노드를 swap해줍니다
        parent->key = current->key;
        current->key = temp;

        current = parent; // current를 부모노드로 바꿔주고 다시 반복합니다.
        parent = find_parent(h, (i /= 2));
    }
    printf("힙에 추가: %d\n", key);
}

int delete_min_heap(HeapType* h) {
    if (is_empty(h)) {
        printf("힙이 비어있습니다.\n");
        return -1;
    }

    element* parent, * left, * right, * last;
    int min_key = h->heap->key;

    if (h->heap_size == 1) { // 힙의 크기가 1일땐 바로 루트노드를 반환합니다.
        free(h->heap);
        h->heap = NULL;
        h->heap_size--;
        return min_key;
    }

    int i = h->heap_size;
    element* last_parent = find_parent(h, i); // 끝 노드의 부모를 찾습니다.

    // 끝 노드의 부모노드 last_parent에서 왼쪽, 오른쪽인지 찾아서 last에 마지막 노드를 넣습니다.
    if (i % 2 == 0) {
        last = last_parent->left;
        last_parent->left = NULL;
    } else {
        last = last_parent->right;
        last_parent->right = NULL;
    }

    // 마지막 노드를 루트노드로 이동시키고 힙 크기를 줄입니다.
    h->heap->key = last->key;
    h->heap_size--;
    free(last);

    parent = h->heap; // 루트노드부터 시작해서
    while (1) { 
        left = parent->left;
        right = parent->right;
        element* min = parent;

        // 자식노드중 더 작은 값을 찾아서 min에 넣습니다.
        if (left != NULL && left->key < min->key) min = left;
        if (right != NULL && right->key < min->key) min = right;
        if (min == parent) break;

        // 부모노드와 자식노드의 값을 바꿔줍니다.
        int temp = parent->key;
        parent->key = min->key;
        min->key = temp;

        parent = min; // 부모노드를 min으로 바꿔주고 다시 반복합니다.
    }
    return min_key;
}

int find(HeapType* h) { // 현재 힙의 루트노드를 반환합니다.
    if (is_empty(h)) {
        printf("현재 힙이 비었습니다.\n");
        return -1;
    }
    return h->heap->key;
}

int main()
{
    HeapType* h = create_heap();
    init_heap(h);

    insert_min_heap(h, 30);
    insert_min_heap(h, 50);
    insert_min_heap(h, 10);
    insert_min_heap(h, 20);
    insert_min_heap(h, 5);

    printf("-----------------\n");

    for (int i = 0; i < 5; i++) {
        int e = delete_min_heap(h);
        printf("최소 힙 출력: %d\n", e);
    }
    return 0;
}