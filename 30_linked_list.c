#include <io_utils.h>
#include <stdlib.h>

typedef struct ListNode {
    int value;
    struct ListNode *next;
} ListNode;

ListNode *CreateNode(int value) {
    ListNode *node = malloc(sizeof(struct ListNode));
    if (!node) exit(1);
    node->value = value;
    node->next = NULL;
    return node;
}

// 记住：传了参就是复制了！
// 这个 node 是个复制品，但是指向同一个内存！
//void DestroyNode(ListNode *node) {}
// 因此，我们传递指针的指针！
// 这样也方便把这个指针设为空！
void DestroyNode(ListNode **node_ptr) {
    (*node_ptr) -> next = NULL;
    free(*node_ptr);
    *node_ptr = NULL;
}

ListNode *CreateList(int array[], int length) {
    if (length <= 0) return NULL;
    ListNode *head = CreateNode(array[0]);
    ListNode *current = head;
    for (int i=1; i<length; i++) {
        current->next = CreateNode(array[i]);
        current = current->next;
    }
    return head;
}

void PrintList(ListNode *head) {
    while (head) {
        printf("%d ", head->value);
        head = head->next;  // head is a copy, 不影响外面
    }
    printf("\n");
}

void DestroyList(ListNode **head_ptr) {
    if (!head_ptr || !(*head_ptr)) return;
    ListNode *current = *head_ptr;
    while (current) {
        ListNode *to_be_destroy = current;
        current = current->next;
        DestroyNode(&to_be_destroy);
    }
    *head_ptr = NULL;
}

void InsertNode(ListNode **head_ptr, int value, int index) {
    if (!head_ptr || index < 0) return;
    ListNode *new_node = CreateNode(value);
    if (index == 0) {
        new_node->next = *head_ptr;
        *head_ptr = new_node;
    } else {
        if (!(*head_ptr)) {
            *head_ptr = CreateNode(0);
        }
        ListNode* current = *head_ptr;
        while (index > 1) {
            if (!current->next) {
                current->next = CreateNode(0);
            }
            current = current->next;
            index--;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

void DeleteNode(ListNode **head_ptr, int index) {
    if (!head_ptr || index < 0) return;
    ListNode *current = *head_ptr;
    if (index == 0) {
        *head_ptr = current->next;
        DestroyNode(&current);
        return;
    }
    while (index > 1) {
        if (!current->next) return;
        current = current->next;
        index--;
    }
    if (!current->next) return;
    ListNode* node_to_destroy = current->next;
    current->next = current->next->next;
    DestroyNode(&node_to_destroy);
}


int main() {
    ListNode *node = CreateNode(0);
    DestroyNode(&node);

    int array[] = {1, 2, 3, 4, 5};
    ListNode *head = CreateList(array, 5);
    PrintList(head);
    InsertNode(&head, 100, 0);
    InsertNode(&head, 200, 3);
    InsertNode(&head, 300, 6);
    InsertNode(&head, 400, 9);
    PrintList(head);
    DestroyList(&head);

    InsertNode(&head, 10, 0);
    PrintList(head);
    DestroyList(&head);
    InsertNode(&head, 10, 10);
    PrintList(head);
    DestroyList(&head);

    head = CreateList(array, 5);
    DeleteNode(&head, 2);
    PrintList(head);  // 1 2 4 5
    DeleteNode(&head, 2);
    PrintList(head);  // 1 2 5
    DeleteNode(&head, 2);
    PrintList(head);  // 1 2
    DeleteNode(&head, 2);
    PrintList(head);  // 1 2
    DeleteNode(&head, 0);
    PrintList(head);  // 2
    DeleteNode(&head, 0);
    PrintList(head);  //
    PRINT_HEX(head);  // 此时已经完全被销毁
    return 0;
}