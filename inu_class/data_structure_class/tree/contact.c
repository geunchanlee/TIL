#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_SIZE 15
#define MAX_PHONE_SIZE 15

// 이름과 전화번호를 저장하는 구조체 element입니다.
typedef struct {
    char name[MAX_NAME_SIZE];
    char phone[MAX_PHONE_SIZE];
} element;
// 노드의 구조체 정의
typedef struct TreeNode {
    element key;
    struct TreeNode* left, *right;
} TreeNode;

// 이름을 비교해서 순서를 반환하는 함수 compare입니다.
// e1 < e2: -1, e1 = e2: 0, e1 > e2: 1
int compare(element e1, element e2)
{
    return strcmp(e1.name, e2.name);
}

// 출력함수는 (1) 전체 노드 개수와 (2) 전체 노드 정보(중위순회 사용) 출력합니다.
// (1)을 위해 전체 노드 개수를 반환하는 함수 get_node_cnt 입니다.
int get_node_count(TreeNode* node)
{
    int count = 0;
    // 루트 노드 1개와 왼쪽 서브트리 노드 개수와 오른쪽 서브트리 노드 개수를 더합니다.
    // 왼쪽 서브트리 + 오른쪽 서브트리 + 루트 노드 후위 순회 방식으로 노드 개수를 구합니다.
    if (node != NULL){
        count = get_node_count(node->left) + get_node_count(node->right) + 1;
    }
    return count;
}
// (2)를 위해 중위순회로 출력하는 함수 inorder입니다.
void inorder(TreeNode* node)
{
    if (node) {
        inorder(node->left);
        printf("[이름: %s, 전화번호: %s]\n", node->key.name, node->key.phone);
        inorder(node->right);
    }
}
// 출력기능 (1)과 (2)를 출력하는 함수 display입니다.
void display(TreeNode* node)
{
    printf("전체 노드 개수: %d\n", get_node_count(node));
    inorder(node);
}

TreeNode* search(TreeNode* root, element key)
{
    TreeNode* p = root;
    while (p != NULL) {
        if (compare(key, p->key) == 0)
            return p;
        else if (compare(key, p->key) < 0)
            p = p->left;
        else
            p = p->right;
    }
    return p;
}

TreeNode* new_node(element item)
{
    TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

TreeNode* insert_node(TreeNode* node, element key)
{
    if (node == NULL) return new_node(key);
    if (compare(key, node->key) == 0) return new_node(key); // 중복된 이름이 있을 경우 새로운 노드를 생성해 덮어쓰기 합니다.

    if (compare(key, node->key) < 0) 
        node->left = insert_node(node->left, key);
    else if (compare(key, node->key) > 0)
        node->right = insert_node(node->right, key);
    return node;
}

// 삭제함수의 3번째 경우 (왼쪽 오른쪽 서브트리가 모두 존재하는 경우) 
// max value를 찾아 사용하는 함수이기 때문에 right로 이동하면서 가장 큰 값을 찾습니다.
// 파라미터로 받을 때는 왼쪽 서브트리를 받아서 가장 큰 값을 찾습니다.
TreeNode* max_value_node(TreeNode* node)
{
    TreeNode* current = node;
    while (current->right != NULL)
        current = current->right;
    return current;
}


// 노드를 삭제하는 함수입니다.
TreeNode* delete_node(TreeNode* root, element key)
{
    if (root == NULL) return root;

    if (compare(key, root->key) < 0)
        root->left = delete_node(root->left, key);
    else if (compare(key, root->key) > 0)
        root->right = delete_node(root->right, key);
    else {
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        TreeNode* temp = max_value_node(root->left);
        root->key = temp->key;
        root->left = delete_node(root->left, temp->key);
    }
    return root;
}

void menu()
{
    printf("삽입(i), 탐색(s), 출력(p), 삭제(d), 종료(q): ");
}

int main(void){
    char command;
    element e;
    TreeNode* root = NULL;
    TreeNode* tmp;

    do {
        menu();
        command = getchar();
        getchar();

        switch(command)
        {
            case 'i':
                printf("이름: ");
                fgets(e.name, MAX_NAME_SIZE, stdin);
                e.name[strcspn(e.name, "\n")] = 0; // fgets로 입력받은 개행 문자를 strcspn으로 찾아서 NULL로 변경해줍니다.

                printf("전화번호: ");
                fgets(e.phone, MAX_PHONE_SIZE, stdin);
                e.phone[strcspn(e.phone, "\n")] = 0;
                root = insert_node(root, e);
                break;
            case 's':
                printf("검색 이름: ");
                fgets(e.name, MAX_NAME_SIZE, stdin);
                e.name[strcspn(e.name, "\n")] = 0;
                tmp = search(root, e);
                if (tmp != NULL)
                    printf("'%s'의 전화번호: %s\n",e.name, tmp->key.phone);
                else
                    printf("탐색 실패\n");
                break;
            case 'p':
                display(root);
                printf("\n");
                break;
            case 'd':
                printf("삭제할 이름: ");
                fgets(e.name, MAX_NAME_SIZE, stdin);
                e.name[strcspn(e.name, "\n")] = 0;
                root = delete_node(root, e);
                printf("연락처에서 '%s'삭제\n", e.name);
                break;
        }
    } while (command != 'q');
    return 0;
}