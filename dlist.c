#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next, *prev;
} node;

void insert_tail(struct node **start, int value) {
  if (!*start) {
    node *new = malloc(sizeof(node));
    new->data = value;
    new->next = new_node->prev = new_node;
    *start = new_node;
    return;
  }
  struct node *last = (*start)->prev;
  struct node *new = malloc(sizeof(node));
  new->data = value;
  new->next = *start;
  new->prev = last;
  (*start)->prev = new;
  last->next = new;
}
