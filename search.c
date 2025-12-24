#include <stdio.h>
#include "search.h"

void displayResults(DocNode *head)
{
    if (!head)
    {
        printf("No documents found.\n");
        return;
    }

    DocNode *curr = head;
    while (curr)
    {
        printf("Document %d → Frequency %d\n",
               curr->docID, curr->frequency);
        curr = curr->next;
    }
}

void searchWord(TrieNode *root)
{
    char query[100];
    printf("Enter word to search: ");
    scanf("%s", query);

    TrieNode *result = searchTrie(root, query);
    if (!result)
    {
        printf("Word not found.\n");
        return;
    }

    printf("Word found in:\n");
    displayResults(result->docList);
}
