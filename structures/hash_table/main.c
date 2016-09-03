#include <stdio.h>
#include <stdlib.h>
#include "hash_table.c"

int main() {
  HashTable *ht = create_hash_table();

  put(ht, 12, 1002);
  put(ht, 14, 1001);
  put(ht, 901, 1000);
  put(ht, 1, 1003);

  print_hash_table(ht);

  printf("Contains key 12? %d\n", contains_key(ht, 12));
  printf("Get key 12 %d\n", get(ht, 12));

  delete(ht, 12);

  printf("Contains key 12 after delete? %d\n", contains_key(ht, 12));

  print_hash_table(ht);

  return 0;
}