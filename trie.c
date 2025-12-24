#include"trie.h"

TrieNode* createNode(){ 
    TrieNode *newnode; 
    newnode = (TrieNode*)(malloc(sizeof(TrieNode))); 
    newnode->isEndOfWord = 0; 
    newnode->list = NULL; 
    for(int i=0;i<SIZE;i++){ 
        newnode->child[i] = NULL;
    }
    return newnode;
}
