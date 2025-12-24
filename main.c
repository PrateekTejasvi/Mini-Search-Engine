#include <stdio.h>
#include <string.h>
#include "trie.h"
#include "indexer.h"

int main()
{
    TrieNode *root = createTrieNode();

    indexDocument(root, "data/doc1.txt", 1);
    indexDocument(root, "data/doc2.txt", 2);

    char query[100];
    printf("Enter word to search: ");
    scanf("%s", query);

    TrieNode *result = searchTrie(root, query);

    if (!result)
    {
        printf("Word not found.\n");
    }
    else
    {
        DocNode *curr = result->docList;
        printf("Found in:\n");
        while (curr)
        {
            printf("Document %d → Frequency %d\n",
                   curr->docID, curr->frequency);
            curr = curr->next;
        }
    }

    freeTrie(root);
    return 0;
}
