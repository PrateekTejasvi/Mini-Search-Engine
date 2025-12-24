#include <stdio.h>
#include "ui.h"
#include "search.h"

void startMenu(TrieNode *root)
{
    int choice;

    while (1)
    {
        printf("\n==== MINI SEARCH ENGINE ====\n");
        printf("1. Search Word\n");
        printf("2. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            searchWord(root);
            break;
        case 2:
            printf("Exiting...\n");
            return;
        default:
            printf("Invalid choice.\n");
        }
    }
}
