// dictionary.c — CS50 Speller implementation
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "dictionary.h"

// Number of buckets in hash table
#define N 26

// Node structure for linked list
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Hash table and global word counter
node *table[N];
unsigned int word_count = 0;

// HASH FUNCTION
unsigned int hash(const char *word)
{
    // Simple hash: first letter
    return tolower(word[0]) - 'a';
}

// LOAD DICTIONARY
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if (!file) return false;

    char word[LENGTH + 1];

    while (fscanf(file, "%45s", word) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (!n)
        {
            fclose(file);
            return false;
        }

        strcpy(n->word, word);
        unsigned int index = hash(word);
        n->next = table[index];
        table[index] = n;
        word_count++;
    }

    fclose(file);
    return true;
}

// CHECK WORD
bool check(const char *word)
{
    unsigned int index = hash(word);
    node *cursor = table[index];

    while (cursor)
    {
        if (strcasecmp(cursor->word, word) == 0)
            return true;
        cursor = cursor->next;
    }
    return false;
}

// SIZE OF DICTIONARY
unsigned int size(void)
{
    return word_count;
}

// UNLOAD DICTIONARY
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
    }
    return true;
}