#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_SIZE 10
#define MAX_PHONE_SIZE 15


typedef struct {
    char name[MAX_NAME_SIZE];
    char phone[MAX_PHONE_SIZE];
} element;

typedef struct TreeNode {
    element key;
    struct TreeNode* left, *right;
} TreeNode;


int compare(element e1, element e2)
{
    return strcmp(e1.name, e2.name);
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

    if (compare(key, node->key) < 0) 
        node->left = insert_node(node->left, key);
    else if (compare(key, node->key) > 0)
        node->right = insert_node(node->right, key);
    return node;
}

//max value를 찾는 함수이기 때문에 left가 아니라 right로 이동합니다.
TreeNode* max_value_node(TreeNode* node)
{
    TreeNode* current = node;
    while (current->right != NULL)
        current = current->right;
    return current;
}

TreeNode* delete_node(TreeNode* root, element key)
{
    if (root == NULL) return root;

    if (compare(key, root->key) < 0)
        root->left = delete_node(root->left, key);
    if (compare(key, root->key) > 0)
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

void help()
{
    printf("\n 삽입(i), 탐색(s), 출력(p), 삭제(d), 종료(q): ");
}

int main(void){
    char command;
    element e;
    TreeNode* root = NULL;
    TreeNode* tmp;

    do {
        help();
        command = getchar();
        getchar();
        switch(command)
        {
            case 'i':
                printf("이름: ");
                fgets(e.name, MAX_NAME_SIZE, stdin);
                printf("전화번호: ");
                fgets(e.phone, MAX_PHONE_SIZE, stdin);
                root = insert_node(root, e);
                break;
            case 'd':
                printf("삭제할 이름: ");
                fgets(e.name, MAX_NAME_SIZE, stdin);
                root = delete_node(root, e);
                break;
            case 's':
                printf("탐색할 이름: ");
                fgets(e.name, MAX_NAME_SIZE, stdin);
                tmp = search(root, e);
                if (tmp != NULL)
                    printf("전화번호: %s\n", tmp->key.phone);
                else
                    printf("탐색 실패\n");
                break;
        }

    } while (command != 'q');
    return 0;
}