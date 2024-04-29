#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 교재의 링크드 리스트, 괄호 검사 코드를 참고했습니다

typedef struct element { // 연산자와 피연산자를 저장할 구조체입니다
    char op;     // 연산자 +,-,*,/,() 를 저장할 변수입니다
    double num;  // 피연산자를 저장할 변수입니다
} element;

typedef struct StackNode{           // 스택의 노드 구조체입니다 
    element data;          // 연산자와 피연산자를 저장하는 element 구조체로 데이터를 저장합니다
    struct StackNode *link; // 링크드 리스트의 다음 노드를 찾아가기 위해 자기참조 구조체로 구성합니다
} StackNode;

typedef struct {
    StackNode *top; // 스택의 맨 위 top을 가리키는 포인터입니다
} LinkedStack;      // 링크드 리스트 스택 구조체입니다


void init(LinkedStack *s) // 스택을 초기화하는 함수입니다
{
    s->top = NULL; // 링크드 리스트 스택이기 때문에 top이 -1이 아닌 NULL로 시작합니다
}

int is_empty(LinkedStack *s) // 스택이 비어있는지 확인하는 함수입니다
{
    return (s->top == NULL); // top이 NULL일땐 스택이 비어있습니다
}

int is_full(LinkedStack *s) // 스택이 가득 찼는지 확인하는 함수입니다
{
    return 0; // 링크드 리스트를 이용한 스택이기 때문에 스택이 가득 차는 일이 없습니다
}

void push(LinkedStack *s, element item) // 스택에 값을 추가하는 함수입니다
{
    StackNode *temp = (StackNode *)malloc(sizeof(StackNode)); // 추가할 노드를 생성합니다
    temp->data = item;                                        // 새 노드에 값을 넣습니다
    temp->link = s->top;                                      // 새 노드의 링크를 top으로 설정합니다 (스택 맨 위에 새로 들어갑니다)
    s->top = temp;                                            // top을 새로 추가된 노드로 설정합니다
}

element pop(LinkedStack *s) // 스택 맨 윗 값을 반환 함수입니다
{
    if (is_empty(s)) // 스택이 비어있을 때는 오류 메세지를 출력하고 종료합니다
    {
        fprintf(stderr, "스택이 비어있음\n");
        exit(1);
    }
    else
    {
        StackNode *temp = s->top;  // top을 temp에 할당합니다
        element data = temp->data; // temp의 데이터를 data에 할당합니다
        s->top = s->top->link;     // top을 현재 top의 다음 노드로 설정합니다
        free(temp);                // temp 메모리 할당을 해제합니다
        return data;
    }
}

element peek(LinkedStack *s) // 스택의 맨 위 값을 확인하는 함수입니다
{
    if (is_empty(s)) // 스택이 비었을 때는 오류 메세지를 출력하고 종료합니다
    {
        fprintf(stderr, "스택이 비어있음\n");
        exit(1);
    }
    else return s->top->data; // 스택의 맨 위 값을 반환합니다 값을 스택에서 제거하지 않고 반환만 합니다
}


int check_match(const char *in) // 괄호 검사 함수입니다 
{
    LinkedStack s; // 괄호 검사용 스택을 생성합니다
    init(&s);      // 생성한 스택을 초기화합니다
    int n = strlen(in); // 문자열의 길이를 구하고

    for (int i = 0; i < n; i++) // 문자열의 길이만큼 반복합니다
    { 
        if (in[i] == '(') // 반복하면서 여는 괄호일 때
        {
            element e;
            e.op = '('; // 여는 괄호를 스택에 넣습니다
            push(&s, e);
        }
        else if (in[i] == ')') // 닫는 괄호일 때 스택 안에 짝이 맞는 여는 괄호가 있어야 합니다
        {
            if (is_empty(&s)) return 0; // 스택 안에 여는 괄호 짝이 없으므로 오류입니다
            else pop(&s); // 스택에 여는 괄호만 push 했으므로 비어있지 않다면 안에 있는 괄호는 짝이 되는 괄호이기 때문에 pop 합니다 
        }
    }
    if (!is_empty(&s)) return 0; // 반복문이 끝나고 스택이 비어있지 않으면 짝이 안맞는 것입니다 
    return 1; // 모든 경우를 통과하면 짝이 맞기 때문에 1을 반환합니다
}

int main()
{
    char *str = "(3+5)*8-6/2"; // 괄호 검사를 할 문자열입니다
    if (check_match(str)) printf("괄호 검사 성공\n"); // 괄호 검사 함수를 호출하고 성공하면 성공 메세지를 출력합니다
    else printf("괄호 검사 실패\n"); // 실패하면 실패 메세지를 출력합니다
    return 0;
} 