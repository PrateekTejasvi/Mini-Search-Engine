#ifndef TRIE_H
#define TRIE_H

#include<stdio.h> 
#include<stdlib.h>

#define SIZE 26 

typedef struct DocNode{
    int docID; 
    int freq; 
    struct DocNode *next;
}DocNode;

typedef struct TrieNode{
    struct TrieNode *child[SIZE]; 
    int isEndOfWord; 
    DocNode *list;
}TrieNode;

TrieNode* createNode();
void insertWord(TrieNode *root,char *word,int docID);
TrieNode* searchTrie(TrieNode *root,char *word); 
void freeTrie(TrieNode *root); 

#endif
