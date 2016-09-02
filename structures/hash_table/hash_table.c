#include <stdio.h>
#include <stdlib.h>
#include "hash_table.h"
#define SIZEOFHASH = 101;

HashTable* create_hash_table(){
    HashTable *ht = (HashTable*) malloc(sizeof(HashTable));
    int i; 
    for(i = 0; i < SIZEOFHASH; i++){
        ht->table[i] = NULL;
    }
    return ht;
}

void put(HashTable *ht, int key, int value){
    int h = key%SIZEOFHASH;
    while(ht->table[h] != NULL){
        if(ht->table[h]->key == key){
            ht->table[h]->value = value;
            break;
        }
        h = (h+1) % SIZEOFHASH;
    }

    if(ht->table[h] == NULL){
        Element *new = (Element*) malloc(sizeof(Element));
        new->key = key;
        new->value = value;
        ht->table[h] = new;
    }

}

int get(HashTable *ht, int key){
    int h = key % SIZEOFHASH;
    while(ht->table[h] != NULL){
        if(ht->table[h]->key == key){
            return ht->table[h]->value;
        }
        h = (h+1) % SIZEOFHASH;
    }
    return -100;
}

void remove(HashTable *ht, int key){
    int h = key % SIZEOFHASH;
    while(ht->table[h] != NULL){
        if(ht->table[h]->key == key){
            ht->table[h]->key = -1;
        }
        h = (h + 1) % SIZEOFHASH;
    }
}