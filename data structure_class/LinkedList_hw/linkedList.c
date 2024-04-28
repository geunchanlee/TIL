#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define WORD_CNT 7

typedef struct
{
    char name[100];
} element;

typedef struct ListNode
{
    element data;
    struct ListNode *link;
} ListNode;

typedef struct
{
    ListNode *pre;
    ListNode *p;
} FindNode;

// 삭제할 단어 기준으로 앞 뒤로 나누기 위한 구조체입니다
typedef struct
{
    ListNode *List1;
    ListNode *List2;
} SplitList;

// 오류 검출을 위한 함수입니다
void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

// 맨 앞에 값을 추가하는 함숩입니다
ListNode *insert_first(ListNode *head, element value)
{
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p->data = value;
    p->link = head;
    head = p;
    return head;
}

// 리스트 출력 함수입니다
void print_list(ListNode *head)
{
    for (ListNode *p = head; p != NULL; p = p->link)
        printf("%s -> ", p->data.name);
    printf("NULL\n");
}

ListNode *search(ListNode *head, element x)
{
    ListNode *p = head;
    if (strcmp(x.name, "head")) // 찾는 단어가 head가 아닐 때 단어를 찾습니다
    {
        while (p != NULL)
        {
            if (!strcmp(p->data.name, x.name))
                return p;
            p = p->link;
        }
    }
    return NULL;
}

// 단어 삭제 함수와 리스트 쪼개기 함수에서 모두 기준 단어 위치 노드의 이전 노드(pre)를 사용하기 때문에
// 이를 찾는 기능을 함수로 분리했습니다
FindNode find(ListNode *head, element x)
{
    ListNode *p = head;
    ListNode *pre = NULL;
    FindNode result = {NULL, NULL}; // 이전 노드, 대상 노드 두개를 결과로 반환하기 위해 구조체로 선언했습니다

    while (p != NULL)
    {
        if (!strcmp(p->data.name, x.name))
        {
            result.p = p;
            result.pre = pre;
            break;
        }
        pre = p;
        p = p->link;
    }

    return result;
}

// 단어 삭제를 위한 함수입니다
ListNode *delete(ListNode *head, element x)
{
    FindNode result = find(head, x); // find함수를 사용해 삭제 단어와 이전 노드 위치를 찾습니다

    ListNode *p = result.p;
    ListNode *pre = result.pre;

    if (p != NULL)
    {
        if (pre == NULL)
            head = p->link;
        else
            pre->link = p->link;
        free(p);
    }

    return head;
}

// 입력 단어 기준으로 리스트를 두개로 쪼개는 함수 입니다
SplitList split_list(ListNode *head, element x)
{
    FindNode result = find(head, x); // find함수로 쪼갤 기준 단어와 이전 노드위치를 찾습니다
    ListNode *p = result.p;
    ListNode *pre = result.pre;
    SplitList split = {NULL, NULL}; // 두개의 쪼개진 리스트 반환을 위한 구조체입니다

    if (p != NULL)
    {
        if (pre == NULL) // 삭제할 입력 단어가 맨 앞에 있을 때입니다
        {
            split.List1 = NULL;
        }
        else
        {
            pre->link = NULL;   // 앞 리스트의 끝을 NULL로 설정합니다
            split.List1 = head; // head부터 기준 단어까지 List1로 만들어줍니다
        }
        split.List2 = p->link; // 삭제할 단어 뒤부터 끝까지 List2로 만들어줍니다
        free(p);               // 삭제한 단어는 free로 메모리를 해제합니다
    }
    return split;
}

int main()
{
    ListNode *head = NULL;

    element data;
    element word;

    // 최초 리스트를 만들기 위한 포인터 배열입니다
    char *s[WORD_CNT] = {
        "PEACH",
        "MELON",
        "MANGO",
        "LEMON",
        "BANANA",
        "KIWI",
        "APPLE",
    };
    // 반복문으로 링크드 리스트에 단어를 넣어주는 코드입니다
    for (int i = 0; i < WORD_CNT; i++)
    {
        strcpy(data.name, s[i]);
        head = insert_first(head, data);
    };

    printf("head -> ");
    print_list(head);

    printf("삭제 단어: ");
    // 삭제할 단어의 사용자 입력을 처리하는 부분입니다
    fgets(word.name, sizeof(word.name), stdin); // 사용자 입력을 받고
    word.name[strcspn(word.name, "\n")] = '\0'; // 개행문자를 제거합니다

    if (search(head, word) != NULL) // 입력한 삭제 단어가 리스트에 존재하는지 검사합니다
    {
        // 만든 함수들을 이용해 두개로 리스트를 쪼개서 반환해줍니다.
        SplitList split = split_list(head, word);
        ListNode *List1 = split.List1;
        ListNode *List2 = split.List2;

        printf("list1: ");
        printf("head1 -> ");
        print_list(List1);

        printf("list2: ");
        printf("head2 -> ");
        print_list(List2);
    }
    else
        printf("삭제할 단어가 없습니다.\n");

    return 0;
}
