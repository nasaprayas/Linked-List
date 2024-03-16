#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* create_node(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Error creating a new node.\n");
        exit(1); // Exiting program if memory allocation fails
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_at_beginning(struct Node** head, int data) {
    struct Node* new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

void insert_at_end(struct Node** head, int data) {
    struct Node* new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void insert_at_between(struct Node* head, int key, int data) {
    struct Node* new_node = create_node(data);
    struct Node* temp = head;
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node with key %d not found.\n", key);
        free(new_node); // Freeing the allocated memory
        return;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

int delete_node(struct Node** head, int key) {
    struct Node *temp = *head, *prev = NULL;
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return 0;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        return -1; // Node with given key not found
    }
    prev->next = temp->next;
    free(temp);
    return 0;
}

void print_list(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    insert_at_beginning(&head, 10);
    insert_at_beginning(&head, 20);

    insert_at_end(&head, 30);
    insert_at_end(&head, 40);

    printf("Original List: ");
    print_list(head);

    insert_at_between(head, 20, 16);
    printf("List after inserting 16 after 20: ");
    print_list(head);

    return 0;
}
