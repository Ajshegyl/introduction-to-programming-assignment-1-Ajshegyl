#include "cs50.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_valid_key(string key);

int main(int argc, string argv[])
{
    if (argc != 2 || !is_valid_key(argv[1]))
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];
    string plaintext = get_string("plaintext:  ");

    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char c = plaintext[i];
        if (isupper(c))
        {
            int pos = c - 'A';
            printf("%c", toupper(key[pos]));
        }
        else if (islower(c))
        {
            int pos = c - 'a';
            printf("%c", tolower(key[pos]));
        }
        else
        {
            printf("%c", c);
        }
    }
    printf("\n");
    return 0;
}

bool is_valid_key(string key)
{
    if (strlen(key) != 26)
        return false;

    bool seen[26] = {false};
    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(key[i]))
            return false;

        int pos = tolower(key[i]) - 'a';
        if (seen[pos])
            return false;
        seen[pos] = true;
    }

    return true;
}