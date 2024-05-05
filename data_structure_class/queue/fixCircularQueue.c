#include <stdio.h>
#include <stdlib.h>


typedef int element;

typedef struct {
    element *data; // 큐의 데이터를 저장할 포인터입니다
    int front, rear;
    int count; // count 변수 추가하여 큐의 원소 개수를 저장합니다
    int capacity; // 큐의 최대 크기를 저장할 변수입니다
} QueueType;

void init_queue(QueueType *q)
{
    q->front = q->rear = q->count = 0;
    q->capacity = 10; // 큐의 초기 크기를 10으로 설정합니다
    q->data = (element *)malloc(sizeof(element) * q->capacity); // 초기 큐의 크기를 10으로 동적할당합니다
}

void resize(QueueType *q)
{
    q->capacity *= 2; // 큐의 최대 크기를 2배로 늘려줍니다
    q->data = (element *)realloc(q->data, sizeof(element) * q->capacity); // realloc으로 큐의 크기를 늘려줍니다
    
    q->rear = q->count; // 새로 늘어난 큐의 마지막 자리는 count번째이기 때문에 rear를 count로 설정합니다
    // realloc으로 큐의 크기를 늘려줄 때 기존 큐를 빈칸없이 채웠기 때문에 front 자리엔 원래 큐의 끝자리 데이터가 있습니다
    // 그 데이터를 새로 늘어난 큐의 마지막에 옮겨줍니다
    q->data[q->rear] = q->data[q->front]; 
}

int is_empty(QueueType *q)
{
    return (q->count == 0); // count변수를 사용해 0일때 큐가 비어있다고 반환합니다
}

int is_full(QueueType *q)
{
    return (q->count == q->capacity); 
}

void enqueue(QueueType *q, element item)
{
    if (is_full(q))
        resize(q);
    q->rear = (q->rear + 1) % q->capacity; // rear를 1 증가시키고 큐의 크기로 나눈 나머지를 rear로 설정합니다
    q->data[q->rear] = item; // rear에 값을 넣습니다
    q->count++; // count를 1 증가시킵니다
    // printf("rear = %d, data = %d\n", q->rear, q->data[q->rear]);
    // printf("count = %d\n", q->count);
    // printf("capacity = %d\n", q->capacity);
}

element dequeue(QueueType *q)
{
    if (is_empty(q)) {
        fprintf(stderr, "큐가 비어있습니다\n");
        exit(1);
    }
    q->front = (q->front + 1) % q->capacity; // front를 1 증가시키고 큐의 크기로 나눈 나머지를 front로 설정합니다
    q->count--; // count를 1 감소시킵니다
    return q->data[q->front]; // front에 있는 값을 반환합니다
}

element peek(QueueType *q)
{
    if (is_empty(q)) {
        fprintf(stderr, "큐가 비어있습니다\n");
        exit(1);
    }
    return q->data[(q->front + 1) % q->capacity]; // 다음 dequeue시 나올 값을 반환합니다
}

void print_queue(QueueType *q)
{
    int count = q->count; //출력에 사용할 count 변수를 생성합니다
    printf("QUEUE(front=%d rear=%d, count=%d) = ", q->front, q->rear, q->count);
    if (!is_empty(q)) {
        int i = q->front;
        do {
            i = (i+1) % q->capacity;
            printf("%d | ", q->data[i]);
            if (i == q->rear)
                break;
        } while (i != q->front);
    }
    printf("\n");
}


int main()
{
    QueueType q;
    init_queue(&q);
    for(int i = 0; i < 100; i++)
        enqueue(&q, i);
    print_queue(&q);
    return 0;
}