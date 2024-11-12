#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertatfirst(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void deleteatfirst(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = *head;
    *head = temp->next;
    free(temp);
}

void deleteatend(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = *head;
    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        return;
    }
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void deleteatposition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = *head;

    if (position == 0) {
        deleteatfirst(head);
        return;
    }

    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range\n");
        return;
    }

    struct Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

void print(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, position, data;
    insertatfirst(&head, 10);
    insertatfirst(&head, 20);
    insertatfirst(&head, 30);
    insertatfirst(&head, 40);
    print(head);
    do {
        printf("\nEnter a choice:\n");
        printf("1. Insert at front\n");
        printf("2. Delete at front\n");
        printf("3. Delete at end\n");
        printf("4. Delete at position\n");
        printf("5. Print list\n");
        printf("6. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert at the front: ");
                scanf("%d", &data);
                insertatfirst(&head, data);
                break;
            case 2:
                deleteatfirst(&head);
                break;
            case 3:
                deleteatend(&head);
                break;
            case 4:
                printf("Enter the position at which you want to delete: ");
                scanf("%d", &position);
                deleteatposition(&head, position);
                break;
            case 5:
                print(head);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Please choose a valid option\n");
        }

    } while (choice != 6);

    return 0;
}
