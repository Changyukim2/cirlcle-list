#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct listnode {
    element data;
    struct listnode* link;
} listnode;

void print_list(listnode* head) {
    listnode* p;
    if (head == NULL) return;
    p = head->link;
    do {
        printf("%d -> ", p->data);
        p = p->link;
    } while (p != head->link);
    printf("\n");
}

listnode* insert_first(listnode* head, element data) {
    listnode* node = (listnode*)malloc(sizeof(listnode));
    node->data = data;
    if (head == NULL) {
        head = node;
        node->link = head;
    }
    else {
        node->link = head->link;
        head->link = node;
    }
    return head;
}

listnode* insert_last(listnode* head, element data) {
    listnode* node = (listnode*)malloc(sizeof(listnode));
    node->data = data;
    if (head == NULL) {
        head = node;
        node->link = head;
    }
    else {
        node->link = head->link;
        head->link = node;
        head = node;
    }
    return head;
}

listnode* delete_first(listnode* head) {
    if (head == NULL) {
        printf("List is empty.\n");
    }
    else if (head->link == head) {
       
        free(head);
        head = NULL;
    }
    else {
        listnode* temp = head->link;
        head->link = temp->link;
        free(temp);
    }
    return head;
}

listnode* delete_last(listnode* head) {
    if (head == NULL) {
        printf("List is empty.\n");
    }
    else if (head->link == head) {
        
        free(head);
        head = NULL;
    }
    else {
        listnode* prev = head;
        listnode* current = head->link;
        while (current->link != head) {
            prev = current;
            current = current->link;
        }
        prev->link = head;
        free(current);
    }
    return head;
}

int main(void) {
    listnode* head = NULL;
    int num;

    while (1) {
        printf("**** MENU ****\n");
        printf("1. INSERT FIRST\n");
        printf("2. INSERT LAST\n");
        printf("3. DELETE FIRST\n");
        printf("4. DELETE LAST\n");
        printf("5. PRINT list\n");
        printf("0. EXIT\n\n");
        printf("Enter the menu: ");
        scanf("%d", &num);

        int data;
        switch (num) {
        case 1:
           
            printf("Enter the data to insert: ");
            scanf("%d", &data);
            head = insert_first(head, data);
            break;
        case 2:
            
            printf("Enter the data to insert: ");
            scanf("%d", &data);
            head = insert_last(head, data);
            break;
        case 3:
            
            head = delete_first(head);
            printf("First node deleted.\n\n");
            break;
        case 4:
            
            head = delete_last(head);
            printf("Last node deleted.\n\n");
            break;
        case 5:
            
            print_list(head);
            break;
        case 0:
            printf("Exit the program.\n");
            exit(0);
        default:
            printf("Invalid menu option.\n");
            break;
        }
    }

    return 0;
}