#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef struct node {
  struct node* prev;
  struct node* next;
  char* data;
} node_t;

node_t* first(node_t* current) {
  while (current->prev) {
    current = current->prev;
  }

  return current;
}

node_t* last(node_t* current) {
  while (current->next) {
    current = current->next;
  }

  return current;
}

node_t* insert(node_t* current, char* data) {
  size_t data_len = strlen(data);
  char* heap_data = malloc(data_len);
  memcpy(heap_data, data, data_len);

  if (current->data == 0) {
    current->data = heap_data;
    return current;
  }
  node_t* new_node = malloc(sizeof(node_t));
  new_node->prev = current;
  new_node->next = current->next;
  new_node->data = heap_data;
  current->next = new_node;

  return new_node;
}

node_t* find(node_t* current, char* data) {
  current = first(current);
  while (current) {
    if (!strcmp(current->data, data)) {
      return current;
    }
    current = current->next;
  }
  return 0;
}

node_t* delete(node_t* current) {
  node_t* retval;
  free(current->data);

  if (current->prev == 0 && current->next == 0) {
    current->data = 0;
    retval = current;
  } else if (current->prev == 0) {
    current->next->prev = 0;
    retval = current->next;
    free(current);
  } else if (current->next == 0) {
    current->prev->next = 0;
    retval = current->prev;
    free(current);
  } else {
    current->prev->next = current->next;
    current->next->prev = current->prev;
    retval = current->prev;
    free(current);
  }

  return retval;
}

void traverse(node_t* current) {
  current = first(current);
  while (current) {
    printf("- %s\n", current->data);
    current = current-> next;
  }
  puts("");
}

int main(int argc, char *argv[])
{
  node_t* list = malloc(sizeof(node_t));
  list = insert(list, "first");
  traverse(list);
  list = insert(list, "second");
  traverse(list);
  list = insert(list, "third");
  traverse(list);
  list = insert(list, "last");

  traverse(list);

  node_t* node = find(list, "third");
  list = delete(node);
  traverse(list);
  node = find(list, "second");
  list = delete(node);
  traverse(list);
  node = find(list, "last");
  list = delete(node);
  traverse(list);

  return 0;
}
