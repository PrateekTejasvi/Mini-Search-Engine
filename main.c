#include "trie.h"
#include "indexer.h"
#include "ui.h"

int main()
{
    TrieNode *root = createTrieNode();

    indexDocument(root, "data/doc1.txt", 1);
    indexDocument(root, "data/doc2.txt", 2);

    startMenu(root);

    freeTrie(root);
    return 0;
}
