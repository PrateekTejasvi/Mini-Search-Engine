#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "trie.h"

TrieNode *createTrieNode()
{
    TrieNode *node = malloc(sizeof(TrieNode));
    node->isEndOfWord = 0;
    node->docList = NULL;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        node->child[i] = NULL;
    return node;
}

DocNode *addOrUpdateDoc(DocNode *head, int docID)
{
    DocNode *curr = head;
    while (curr)
    {
        if (curr->docID == docID)
        {
            curr->frequency++;
            return head;
        }
        curr = curr->next;
    }
    DocNode *newNode = malloc(sizeof(DocNode));
    newNode->docID = docID;
    newNode->frequency = 1;
    newNode->next = head;
    return newNode;
}

void insertWord(TrieNode *root, char *word, int docID)
{
    TrieNode *curr = root;
    for (int i = 0; word[i]; i++)
    {
        if (!isalpha(word[i]))
            continue;
        int index = tolower(word[i]) - 'a';
        if (!curr->child[index])
            curr->child[index] = createTrieNode();
        curr = curr->child[index];
    }
    curr->isEndOfWord = 1;
    curr->docList = addOrUpdateDoc(curr->docList, docID);
}

TrieNode *searchTrie(TrieNode *root, char *word)
{
    TrieNode *curr = root;
    for (int i = 0; word[i]; i++)
    {
        if (!isalpha(word[i]))
            continue;
        int index = tolower(word[i]) - 'a';
        if (!curr->child[index])
            return NULL;
        curr = curr->child[index];
    }
    return curr->isEndOfWord ? curr : NULL;
}

void freeTrie(TrieNode *root)
{
    if (!root)
        return;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        freeTrie(root->child[i]);

    DocNode *curr = root->docList;
    while (curr)
    {
        DocNode *temp = curr;
        curr = curr->next;
        free(temp);
    }
    free(root);
}
