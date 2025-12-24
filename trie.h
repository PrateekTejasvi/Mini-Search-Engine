#ifndef TRIE_H
#define TRIE_H

#define ALPHABET_SIZE 26

typedef struct DocNode
{
    int docID;
    int frequency;
    struct DocNode *next;
} DocNode;

typedef struct TrieNode
{
    struct TrieNode *child[ALPHABET_SIZE];
    int isEndOfWord;
    DocNode *docList;
} TrieNode;

TrieNode *createTrieNode();
void insertWord(TrieNode *root, char *word, int docID);
TrieNode *searchTrie(TrieNode *root, char *word);
void freeTrie(TrieNode *root);

#endif
