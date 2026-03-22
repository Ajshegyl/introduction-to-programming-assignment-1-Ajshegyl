#include <ctype.h>
#include "cs50.h"
#include <math.h>
#include <stdio.h>
#include <string.h>

// Function prototypes
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Prompt the user
    string text = get_string("Text: ");

    // Count letters, words, and sentences
    int letters   = count_letters(text);
    int words     = count_words(text);
    int sentences = count_sentences(text);

    // Compute averages per 100 words
    float L = 100.0 * letters / words;
    float S = 100.0 * sentences / words;

    // Coleman-Liau index
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // Print grade
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

// Count letters (a-z, A-Z)
int count_letters(string text)
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}

// Count words (words separated by spaces)
int count_words(string text)
{
    int count = 1; // at least one word
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == ' ')
        {
            count++;
        }
    }
    return count;
}

// Count sentences (end with '.', '!', '?')
int count_sentences(string text)
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }
    return count;
}