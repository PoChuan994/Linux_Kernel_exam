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

    struct node *last = (*start)->prev;
    struct node *new = malloc(sizeof(node));
    new->data = value;
    new->next = *start;
    new->prev = last;
    (*start)->prev = new;
    last->next = new;
}

void insert_head(node **start, int value)
{
    if(!start)
        return create(start, value);

    node last = (*start)->prev;
    node new = malloc(sizeof(node));
    node->data = value;
    node->next = *start;
    node->prev = last;
    (*start)->prev = last->next = new;
    *start = new;
}
