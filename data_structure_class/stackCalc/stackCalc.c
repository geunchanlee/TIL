#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct element { // 연산자와 피연산자를 저장할 구조체입니다
    char op;     // 연산자 +,-,*,/,() 를 저장할 변수입니다
    double num;  // 피연산자(숫자)를 저장할 변수입니다
} element;

typedef struct StackNode{   // 스택의 노드 구조체입니다 
    element data;           // 연산자와 피연산자를 저장하는 element 구조체로 데이터를 저장합니다
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
    temp->data = item; // 새 노드에 값을 넣습니다
    temp->link = s->top; // 새 노드의 링크를 top으로 설정합니다 (스택 맨 위에 새로 들어갑니다)
    s->top = temp; // top을 새로 추가된 노드로 설정합니다
}

element pop(LinkedStack *s) // 스택 맨 윗 값을 반환 함수입니다
{
    if (is_empty(s)) // 스택이 비어있을 때는 오류 메세지를 출력하고 종료합니다
    {
        fprintf(stderr, "Error, empty pop\n"); // 오류 발생 함수를 출력합니다
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
        fprintf(stderr, "Error, empty peek"); // 오류 발생 함수를 출력합니다
        exit(1);
    }
    else return s->top->data; // 스택의 맨 위 값을 반환합니다 값을 스택에서 제거하지 않고 반환만 합니다
}


int check_match(const char *in) // 수식을 입력으로 받아 괄호의 짝이 올바른지 검사하는 함수입니다
{
    LinkedStack s;      // 괄호 검사용 링크드 스택을 생성합니다
    init(&s);           // 생성한 스택을 초기화합니다
    int n = strlen(in); // 문자열의 길이를 구하고

    for (int i = 0; i < n; i++) // 수식 길이만큼 반복해면서
    { 
        if (in[i] == '(') // in[i]가 여는 괄호일 때
        {
            element e;
            e.op = '(';   // 여는 괄호를 스택에 집어넣습니다
            push(&s, e);
        }
        else if (in[i] == ')') // 닫는 괄호일 때는 스택 안에 짝 맞는 여는 괄호가 있는지 확인합니다
        {
            if (is_empty(&s)) return 0; // 스택 안에 여는 괄호 짝이 없으므로 오류입니다
            else pop(&s); // 앞에서 스택에 여는 괄호만 push 했으므로 비어있지 않다면 안에 있는 괄호는 짝이 되는 괄호이기 때문에 pop 합니다 
        }
    }
    if (!is_empty(&s)) return 0; // 반복문이 끝나고 스택이 비어있지 않으면 여는 괄호가 닫는 괄호보다 많아 짝이 맞지 않는 경우이기 때문에 오류입니다
    return 1; // 모든 경우를 통과하면 짝이 맞기 때문에 1을 반환합니다
}

int check_expr(const char *in) // 수식을 입력으로 받아 올바른지 검사하는 함수입니다
{
    int n = strlen(in); // 문자열의 길이를 구합니다
    int i = 0;
    while (i < n) {
        if ('0' <= in[i] && in[i] <= '9') { // 숫자인 경우, 아스키코드 48(0)~57(9) 사이의 값인 경우 넘어갑니다
            i++;
            continue;
        }
       else if (in[i] == '+' || in[i] == '-') { // 부호인 경우
                if (i == 0 || (!('0' <= in[i-1] && in[i-1] <= '9') && in[i-1] != ')')) {
                    printf("%c\n", in[i]);
                    printf("%c\n", in[i-1]);
                    printf("부호 앞에 숫자나 닫는 괄호가 없습니다\n");
                    return 0; // 부호가 맨 앞에 오거나 앞에 숫자나 닫는 괄호가 없는 경우 잘못된 식이므로 0을 반환합니다
                }
                i++;
                continue;
            }
            else if (in[i] == '.') { // 소수점인 경우
                if (i == 0 || !('0' <= in[i-1] && in[i-1] <= '9')) {
                    printf("%c\n", in[i]);
                    printf("%c\n", in[i-1]);
                    printf("소수점 앞에 숫자가 없습니다\n");
                    return 0; // 소수점이 맨 앞에 오거나 앞에 숫자가 없는 경우 잘못된 식이므로 0을 반환합니다
                }
                i++;
                continue;
            }
        else if (in[i] == '*' || in[i] == '/') { // 연산자인 경우
            if (i == 0 || !(('0' <= in[i-1] && in[i-1] <= '9') || in[i-1] == ')')) {// 연산자가 맨 앞인 경우, 연산자 앞에 숫자가 없는 경우, 연산자 앞에 닫는 괄호가 없는 경우
                printf("연산자 앞에 숫자가 없거나 닫는 괄호가 없습니다\n");
                return 0; // 올바르지 않은 식이므로 0을 반환합니다
            }
            i++;
            continue;
        }
        else if (in[i] == '(' || in[i] == ')') { // 괄호인 경우
            i++;
            continue;
        }
        else {
            printf("올바르지 않은 문자가 있습니다\n");
            return 0; // 그 외의 문자인 경우 올바르지 않은 식이므로 0을 반환합니다
        }  
    }
    return 1;  // 모든 문자를 검사한 후에도 문제가 없으면 1을 반환합니다
}

int prec(char op) // 연산자들의 우선순위를 반환하는 함수입니다
{
    switch(op) {
        case '(': case ')': return 0;
        case '+': case '-': return 1;
        case '*': case '/': return 2;
    }
    return -1;
}

// 중위표기식을 후위표기식으로 변환하는 함수입니다
// 
char* infix_to_postfix(char *expr) {
    LinkedStack s; // 후위 표기식으로 변환할 때 사용할 스택입니다
    init(&s);      // 생성한 스택을 초기화합니다
    int n = strlen(expr); // 문자열의 길이를 구합니다
    char* postfix = (char*)malloc(sizeof(char) * (strlen(expr) + 1)); // 함수 결과 반환을 위해 동적 메모리 할당합니다
    int idx = 0; // 후위 표기법으로 변환한 문자열의 인덱스를 저장할 변수를 생성합니다

    for (int i = 0; i < n; i++) // 문자열의 길이만큼 반복합니다
    {
        if ('0' <= expr[i] && expr[i] <= '9')
        {
            postfix[idx++] = expr[i]; // 숫자일 경우엔 바로 후위 표기식 문자열에 추가합니다
        }
        else if (expr[i] == '(')
        {
            element e;
            e.op = '('; // 여는 괄호는 스택에 push 합니다
            push(&s, e);
        }
        else if (expr[i] == ')') // 닫는 괄호인 경우
        {
            while (!is_empty(&s) && peek(&s).op != '(') // 스택이 비어있지 않고 top이 여는 괄호가 아닐 때
            {
                postfix[idx++] = pop(&s).op; // 스택의 top을 후위 표기식으로 변환한 문자열에 추가합니다
            }
            if (is_empty(&s) || peek(&s).op != '(') // 스택이 비어있거나 top이 여는 괄호가 아닌 경우 == 오류
            {
                free(postfix); // 동적 메모리 할당을 해제합니다
                fprintf(stderr, "Error, 후위 표기식 변환 오류 발생\n");
                exit(1); // 오류 메세지를 출력하고 프로그램을 종료합니다
            }
            pop(&s); // 여는 괄호를 스택에서 제거합니다
        }
        else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/') // 연산자인 경우
        {
            while (!is_empty(&s) && prec(peek(&s).op) >= prec(expr[i])) // 스택이 비어있지 않고 top의 우선순위가 더 높거나 같은 경우
            {
                postfix[idx++] = pop(&s).op; // top을 후위 표기식으로 변환한 문자열에 추가합니다
            }
            element e;
            e.op = expr[i]; // 현재 연산자를 스택에 push 합니다
            push(&s, e);
        }
    }
    while (!is_empty(&s)) // 스택에 남아있는 연산자들을 후위 표기식으로 변환한 문자열에 추가합니다
    {
        postfix[idx++] = pop(&s).op;
    }
    return postfix; // 후위 표기식으로 변환한 문자열을 반환합니다
}

int eval(char *expr){
    LinkedStack s; // 후위 표기식을 계산할 때 사용할 스택입니다
    init(&s);      // 생성한 스택을 초기화합니다
    int n = strlen(expr); // 문자열의 길이를 구합니다

    for (int i = 0; i < n; i++) // 문자열의 길이만큼 반복합니다
    {
        if ('0' <= expr[i] && expr[i] <= '9') // 숫자인 경우
        {
            element e;
            e.num = expr[i] - '0'; // 문자를 숫자로 변환하여 element 구조체에 저장합니다
            push(&s, e); // 스택에 push 합니다
        }
        else // 연산자인 경우
        {
            element e1 = pop(&s); // 스택에서 피연산자를 pop 합니다
            element e2 = pop(&s); // 스택에서 피연산자를 pop 합니다
            element e;
            switch (expr[i]) // 연산자에 따라 연산을 수행하고 결과를 저장합니다
            {
                case '+': e.num = e2.num + e1.num; break;
                case '-': e.num = e2.num - e1.num; break;
                case '*': e.num = e2.num * e1.num; break;
                case '/': e.num = e2.num / e1.num; break;
            }
            push(&s, e); // 연산 결과를 스택에 push 합니다
        }
    }
    return pop(&s).num; // 최종 결과값을 반환합니다

}


int main()
{ 
    char *expr = (char *)malloc(sizeof(char) * 100);
    printf("중위식을 입력하세요: ");
    fgets(expr, 100, stdin); // 사용자로부터 문자열을 입력받습니다
    expr[strlen(expr) - 1] = '\0'; // fgets로 입력받은 문자열의 마지막에 개행문자가 들어가므로 개행문자를 '\0'로 바꿔줍니다

    if (!check_match(expr) || !check_expr(expr)) // 수식이 올바른지 확인합니다
    {
        printf("수식이 올바르지 않습니다\n"); // 올바르지 않은 수식일 경우 오류 메세지를 출력합니다
        free(expr); // 입력받은 문자열의 동적 할당을 해제합니다
        return 0; //
    }

    char *postfix = infix_to_postfix(expr); // 중위 표기법을 후위 표기식으로 변환하는 함수를 호출합니다
    printf("후위식: %s\n", postfix); // 변환한 후위 표기법을 출력합니다
    printf("계산 결과: %d\n", eval(postfix)); // 후위 표기법으로 변환한 식을 계산하는 함수를 호출하고 결과를 출력합니다
    free(postfix); // 후위 표기식 문자열의 동적 메모리 할당을 해제합니다
    free(expr); // 입력받은 문자열의 동적 메모리 할당을 해제합니다
    return 0;
} 