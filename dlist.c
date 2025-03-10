#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
  int data;
  struct node *next, *prev;
} Node;

void create(Node **head, int value)
{
    Node *new = malloc(sizeof(Node));
    new->data = value;
    new->next = new->prev = new;
    *head = new;
    return;
}

void insert_tail(Node **head, int value)
{
    if (!*head)
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
    new->next = *head;
    new->prev = last;
    (*head)->prev = last->next = new;
    *head = new;
}

void bubble_sort(Node **head)
{
    if (!*head || (*head)->next == *head)
        return;

    bool swapped;
    Node *ptr1;

   do {
        swapped = false;
        ptr1 = *head;

        do {
            if (ptr1->next != *head && ptr1->data > ptr1->next->data) {
                int tmp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = tmp;
                swapped = true;
            }
            ptr1 = ptr1->next;
        } while (ptr1->next != *head);

   } while (swapped);
}

Node *split(Node *head)
{
    Node *fast = head, *slow = head;
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

/* merge two sorted doubly linked lists */
/* 
 * Refered from
 * https://www.geeksforgeeks.org/merge-sort-for-doubly-linked-list/
 */
Node *merge(Node *first, Node *second)
{
    if (!first)
        return second;
    if (!second)
        return first;

    /* Pick the smaller value between 
     * first and second sub-list.
     */
     if (first->data < second->data) {
         /*
          * Recursivly merge the rest of the lists and 
          * and link the result to the current node.
         */
        first->next = merge(first->next, second);
        if (first->next != NULL)
            first->next->prev = first;
        first->prev = NULL;
        return first;
     } else {
        second->next = merge(first, second->next);
        if (second->next != NULL)
            second->next->prev = second;
        second->prev = NULL;
        return second;
     }
}

Node *merge_sort(Node *head)
{
    if (!head || !head->next)
        return head;

    Node *second = split(head);
    head = merge_sort(head);
    second = merge_sort(second);
    return merge(head, second);
}

void display(Node *head)
{
    Node *tmp = head;
    printf("Traversal in forward direction \n");
    for (; tmp->next != head; tmp = tmp->next)
        printf("%d", tmp->data);
    printf("%d", tmp->data);
    printf("\nTraversal in reverse dircection");
    Node *last = head->prev;
    for (tmp = last; tmp->prev != last; tmp = tmp->prev) 
        printf("%d", tmp->data);
    printf("%d", tmp->data);
    printf("\n");
}

int main()
{
    Node *head = NULL;

    insert_tail(&head, 63);
    insert_tail(&head, 35);
    insert_tail(&head, 49);
    insert_tail(&head, 15);
    insert_tail(&head, 27);
    insert_tail(&head, 72);

    display(head);
    bubble_sort(&head);
    printf("List after executing bubble sort:\n");
    display(head);

    head = NULL;
    insert_head(&head, 47);
    insert_head(&head, 75);
    insert_head(&head, 2);
    insert_head(&head, 79);
    insert_head(&head, 23);

    display(head);
    printf("List after executing merge sort");
    head = merge_sort(head);
    display(head);

    return 0;
}
