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

// 단어 삭제를 위한 함수입니다
ListNode *delete(ListNode *head, ListNode *pre)
{
    ListNode *removed;
    removed = pre->link;
    pre->link = removed->link;
    free(removed);
    return head;
}

int main()
{
    ListNode *head = NULL;
    element data;
    element find;

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
    fgets(find.name, sizeof(find.name), stdin);
    find.name[strcspn(find.name, "\n")] = '\0'; // 개행문자를 제거합니다

    if (search(head, find) != NULL) // 입력한 삭제 단어가 리스트에 존재하는지 검사합니다
    {
        head = delete (head, search(head, find));
        printf("head -> ");
        print_list(head);
    }
    else
        printf("삭제할 단어가 없습니다.\n");

    return 0;
}