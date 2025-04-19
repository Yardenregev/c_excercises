#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;

void AddItem(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (NULL == new_node) {
        printf("Memory allocation failed\n");
        return;
    }

    new_node->data = data;
    new_node->next = NULL;

    if (NULL == head) {
        head = new_node;
    } else {
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new_node;
    }
}

void RemoveNode(int data) {
    if (NULL == head) {
        printf("List is empty\n");
        return;
    }

    Node* temp = head;
    Node* prev = NULL;

    if (temp->data == data) {
        head = head->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    if (NULL == temp) {
        printf("Value %d not found in list\n", data);
        return;
    }

    prev->next = temp->next;
    free(temp);
    temp = NULL;
}

void PrintList(void) {
    Node* temp = head;
    if (NULL == temp) {
        printf("List is empty\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void FreeList(void)
{
    Node* dummy = head;
    while(head != NULL)
    {
        dummy = head;
        head = head->next;
        free(dummy);
        dummy = NULL;
    }
}
