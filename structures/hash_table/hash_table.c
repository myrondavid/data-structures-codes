#include <stdio.h>
#include <stdlib.h>
#include "hash_table.h"

#define MAX_ELEMENTS 11

int hash(int key) {
  return key % MAX_ELEMENTS;
}

struct element {
  int key;
  int value;
  Element *next_element;
};

struct hash_table {
  Element *table[MAX_ELEMENTS];
};

HashTable* create_hash_table() {
  HashTable *ht = malloc(sizeof(HashTable));

  int i;
  for(i = 0; i < MAX_ELEMENTS; ++i) {
    ht->table[i] = NULL;
  }

  return ht;
}

void put(HashTable *ht, int key, int value) {
  int h = hash(key);

  Element *new_element = (Element*) malloc(sizeof(Element));
  new_element->key = key;
  new_element->value = value;
  new_element->next_element = NULL;

  if(ht->table[h] == NULL) {
    ht->table[h] = new_element;
  } else {
    new_element->next_element = ht->table[h];
    ht->table[h] = new_element;
  }
}

int get(HashTable *ht, int key) {
  int h = hash(key);

  if(ht->table[h] != NULL) {
    Element *element = ht->table[h];

    while(element != NULL) {
      if(element->key == key) return element->value;

      element = element->next_element;
    }
  }

  return -1;
}

void delete(HashTable *ht, int key) {
  int h = hash(key);

  if(ht->table[h] != NULL) {
    Element *element = ht->table[h];
    Element *prev_element;

    while(element != NULL && element->key != key) {
      prev_element = element;
      element = element->next_element;
    }

    if(element != NULL) {
      if(prev_element == NULL) ht->table[h] = element->next_element;
      else prev_element->next_element = element->next_element;
    }

    free(element);
  }
}

int contains_key(HashTable *ht, int key) {
  int h = hash(key);

  if(ht->table[h] != NULL) {
    Element *element = ht->table[h];

    while(element != NULL) {
      if(element->key == key) return 1;

      element = element->next_element;
    }
  }

  return 0;
}

void print_elements(Element *element) {
  if(element == NULL) return;

  printf("%d - %d\n", element->key, element->value);

  print_elements(element->next_element);
}

void print_hash_table(HashTable *ht) {
  int i;

  for(i = 0; i < MAX_ELEMENTS; ++i) {
    if(ht->table[i] != NULL) print_elements(ht->table[i]);
  }
}