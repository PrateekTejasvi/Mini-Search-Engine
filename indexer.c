#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "indexer.h"

void indexDocument(TrieNode *root, char *filename, int docID)
{
    FILE *fp = fopen(filename, "r");
    if (!fp)
    {
        printf("Cannot open %s\n", filename);
        return;
    }

    char word[100];
    while (fscanf(fp, "%99s", word) == 1)
    {
        insertWord(root, word, docID);
    }
    fclose(fp);
}
