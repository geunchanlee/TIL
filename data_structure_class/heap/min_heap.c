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

HeapType* create_heap() 
{
    return (HeapType*)malloc(sizeof(HeapType));
}

void init_heap(HeapType* h)
{
    h->heap = NULL;
    h->heap_size = 0;
}

element* new_element(int key)
{
    element* e = (element*)malloc(sizeof(element));
    e->key = key;
    e->left = NULL;
    e->right = NULL;
    return e;
}

int is_empty(HeapType* h) // 힙이 비어있는지 검사하는 함수입니다.
{
    return h->heap_size == 0;
}

element* find_parent(HeapType* h, int size) // 부모 노드를 찾는 함수입니다.
// size를 기준으로 부모 노드를 찾습니다.
{
    element* parent = h->heap;
    int i = size / 2; // 힙이 완전 이진트리이기 때문에 2로 나누어서 부모노드를 찾습니다.
    while (i > 1) 
    { 
        if (i % 2 == 0) {
            parent = parent->left;
        } else {
            parent = parent->right;
        }
        i /= 2; // 순회하면서 방향에 맞춰 부모노드를 찾아갑니다.
    }
    return parent;
}

void insert_min_heap(HeapType* h, int key)
{
    element* e = new_element(key); // 새 노드 생성합니다.
    if (is_empty(h))  // 빈 힙일땐 루트노드로 만듭니다.
    { 
        h->heap = e;
        int i = ++(h->heap_size);
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
    while (parent != NULL && parent->key > current->key) // 부모노드의 값이 더 크면 교환합니다.
    {
        int temp = parent->key;
        parent->key = current->key;
        current->key = temp;

        current = parent;
        parent = find_parent(h, (i /= 2));
    }

    printf("힙에 추가: %d\n", key);
}

int delete_min_heap(HeapType* h) {
    if (is_empty(h)) {
        printf("힙이 비어있습니다.\n");
        return -1;
    }

    element* parent, * left, * right, * last, * last_parent;
    int min_key = h->heap->key;

    if (h->heap_size == 1) { // 힙의 크기가 1일땐 바로 루트노드를 반환합니다.
        free(h->heap);
        h->heap = NULL;
        h->heap_size--;
        return min_key;
    }

    int i = h->heap_size;
    last_parent = h->heap;
    int path = i / 2;

    // 마지막 노드의 부모를 찾습니다.
    while (path > 1) {
        if (path % 2 == 0) {
            last_parent = last_parent->left;
        } else {
            last_parent = last_parent->right;
        }
        path /= 2;
    }

    if (i % 2 == 0) {
        last = last_parent->left;
        last_parent->left = NULL;
    } else {
        last = last_parent->right;
        last_parent->right = NULL;
    }

    h->heap->key = last->key;
    free(last);
    h->heap_size--;

    parent = h->heap;
    while (1) {
        left = parent->left;
        right = parent->right;
        element* min = parent;

        if (left != NULL && left->key < min->key) {
            min = left;
        }
        if (right != NULL && right->key < min->key) {
            min = right;
        }

        if (min == parent) {
            break;
        }

        int temp = parent->key;
        parent->key = min->key;
        min->key = temp;

        parent = min;
    }

    return min_key;
}


int find(HeapType* h) // 현재 최소 힙의 루트노드를 반환합니다.
{ 
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

    for (int i = 0; i < 5; i++) {
        int e = delete_min_heap(h);
        printf("최소 힙 출력: %d\n", e);
    }
    return 0;
}