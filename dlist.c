#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next, *prev;
} Node;

void create(node **head, int value)
{
    Node *new = malloc(sizeof(Node));
    new->data = value;
    new->next = new->prev = new;
    *start = new;
    return;
}

void insert_tail(Node **head, int value)
{
    if (!*start)
        return create(head, value);

    Node *last = (*head)->prev;
    Node *new = malloc(sizeof(Node));
    new->data = value;
    new->next = *head;
    new->prev = last;
    (*head)->prev = new;
    last->next = new;
}

void insert_head(Node **head, int value)
{
    if(!*head)
        return create(head, value);

    Node *last = (*head)->prev;
    Node *new = malloc(sizeof(Node));
    new->data = value;
    new->next = *start;
    new->prev = last;
    (*head)->prev = last->next = new;
    *head = new;
}

void bubble_sort(Node **head)
{
    if (!*head || (*head)->next == *head)
        return;

    bool swapped;
    Node *ptr1, lptr = NULL;

   do {
        swapped = false;
        ptr1 = *start;

        do {
            if (ptr1->next != *start && ptr1->data > ptr1->next->data) {
                int tmp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next = tmp;
                swapped = true;
            }
            ptr1 = ptr1->next;
        } while (ptr1->next != lptr && ptr1->next != *head)

        lptr = ptr1;
   } while (swapped) 
}

Node *split(Node *head)
{
    Node *fast = head, slow = head;
    while (fast->next != head && fast->next->next != head) {
        fast = fast->next->next;
        slow = slow->next;
    }
    
    /* split the list into two havles */
    Node *tmp = slow->next;
    slow->next = NULL;
    if (tmp != NULL)
        tmp->prev = NULL;
    return tmp;
}

void display(Node *head)
{
    Node *tmp = start;
    printf("Traversal in forward direction \n");
    for (; tmp->next != head; tmp = tmp->next)
        printf("%d", tmp->data);
    // printf("%d", tmp->data);
    printf("\nTraversal in reverse dircection");
    node last = (*head)->prev;
    for (tmp = last; tmp->prev != last; tmp = tmp->prev) 
        printf("%d". tmp->data);
    // printf("%d", tmp->data);
    printf("\n");
}
