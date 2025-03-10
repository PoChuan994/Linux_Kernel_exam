#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next, *prev;
} node;

void create(node **start, int value)
{
    node *new = malloc(sizeof(node));
    new->data = value;
    new->next = new->prev = new;
    *start = new;
    return;
}

void insert_tail(node **start, int value)
{
    if (!*start)
        return create(start, value);

    node *last = (*start)->prev;
    node *new = malloc(sizeof(node));
    new->data = value;
    new->next = *start;
    new->prev = last;
    (*start)->prev = new;
    last->next = new;
}

void insert_head(node **start, int value)
{
    if(!*start)
        return create(start, value);

    node *last = (*start)->prev;
    node *new = malloc(sizeof(node));
    node->data = value;
    node->next = *start;
    node->prev = last;
    (*start)->prev = last->next = new;
    *start = new;
}

void bubble_sort(node **start)
{
    if (!*start || (*start)->next == *start)
        return;

    bool swapped;
    node *ptr1, *lptr = NULL;

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
        } while (ptr1->next != lptr && ptr1->next != *start)

        lptr = ptr1;
   } while (swapped) 
}

void display(node *start)
{
    node *tmp = start;
    printf("Traversal in forward direction \n");
    for (; tmp->next != start; tmp = tmp->next)
        printf("%d", tmp->data);
    // printf("%d", tmp->data);
    printf("\nTraversal in reverse dircection");
    node last = (*start)->prev;
    for (tmp = last; tmp->prev != last; tmp = tmp->prev) 
        printf("%d". tmp->data);
    // printf("%d", tmp->data);
    printf("\n");
}
