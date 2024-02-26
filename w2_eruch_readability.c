/*
//Coleman-Liau index

// index = 0.0588 * L - 0.296 * S - 15.8

// L is the average # of letters per 100 words in the text
//S is the  average # of sentences per 100 words in the text

*/
#include <stdio.h>
#include <float.h>
#include <limits.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(void)
{
    // define vars
    char sentence[10000];

    // prompt user for some text
    printf("Howdy! Input your test sentence(s):\n");

    fgets(sentence, sizeof(sentence), stdin);

    printf("%s\n", sentence);

    // count letters
    int letters = 0;
    int l = strlen(sentence);
    int i = 0;
    int letterCount = 0;
    int wordCount = 1;
    int sentenceCount = 1;

    for (i = 0; i < l; i++)
    {
        if (isalpha(sentence[i]))
        {
            letterCount++;
        }
        else if (sentence[i] == ' ')
        {
            wordCount++;
        }
        else if ((sentence[i] == '.' || sentence[i] == '?' || sentence[i] == '!') && sentence[i + 1] == ' ')
        {
            sentenceCount++;
        }
    }

    float L = ((float)letterCount / wordCount * 100);
    float S = ((float)sentenceCount / wordCount * 100);
    float CL_index = (0.0588 * L) - (0.296 * S) - 15.8;

    printf("Letter count is %d\n", letterCount);
    printf("Word count is %d\n", wordCount);
    printf("Sentence count is %d\n", sentenceCount);
    printf("Ave letters is %.4f\n", L);
    printf("Ave sentences is %.4f\n", S);
    printf("Coleman-Liau index is %.1f\n", CL_index);
    if (CL_index < 1)
    {
        printf("Grade Level is below 1\n");
    }
    else if (CL_index > 16)
    {
        printf("Grade level is above 16\n");
    }
    else
    {
        printf("Grade level is %.0f\n", CL_index);
    }
}