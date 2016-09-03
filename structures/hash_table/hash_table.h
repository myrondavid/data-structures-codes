#ifndef HASH_TABLE_H
#define HASH_TABLE_H

  typedef struct element Element;

  typedef struct hash_table HashTable;

  HashTable* create_hash_table();

  void put(HashTable *ht, int key, int value);

  int get(HashTable *ht, int key);

  void delete(HashTable *ht, int key);

  int contains_key(HashTable *ht, int key);

  void print_hash_table(HashTable *ht);

#endif /* HASH_TABLE_H */