#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#define SIZEOFHASH = 101;

  typedef struct element Element;
  typedef struct hash_table HashTable;

  struct element {
    int key;
    int value;
  };

  struct hash_table {
      Element *table[SIZEOFHASH];
  };

  HashTable* create_hash_table();
  void put(HashTable *ht, int key, int value);
  int get(HashTable *ht, int key);
  void remove(HashTable *ht, int key);
  int contains_key(HashTable *ht, int key);
  void print_hash_table(HashTable *ht);

#endif /* HASH_TABLE_H */