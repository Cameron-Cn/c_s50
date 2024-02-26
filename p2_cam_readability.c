/* CS50x - Week 2
Problem Sets - Readability
Cameron */

#include <stdio.h>
#include <float.h>
#include <limits.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(void){
    //define vars
    char sentence[10000];

    //prompt user for some text
    printf("Howdy! Input your test sentence(s):\n");

    fgets(sentence, sizeof(sentence),stdin);

    // printf("%s\n", sentence);

    // count letters
    int letters = 0;
    int l = strlen(sentence);
    int i = 0;
    int letterCount = 0;
    int wordCount = 1; //to catch the last word (no space)
    int sentCount = 1; //last sentence does not have space

    for (i = 0; i < l; i++){
        if (isalpha (sentence[i])){  // we can put this all in one 'for' loop, but 
        letterCount++;               // did not do so in writing
        } 
    } 
    printf("letcount: %d\n", letterCount);

    for (i = 0; i < l; i++){
        if (sentence[i] == ' '){
            wordCount++;
        }
    }
    printf("wordcount: %d\n", wordCount);
       
       
    for (i = 0; i < l; i++){
        if ((sentence[i] == '.' || sentence[i] == '?' || sentence[i] == '!')\
        && sentence[i+1] == ' '){
            sentCount++;
        }
    }
    printf("sentcount: %d\n", sentCount);

    // declaring Coleman-Liau index variables
    float L = (((float)letterCount / (float)wordCount) *100);
    float S = (((float)sentCount / (float)wordCount) * 100);

    //printf("L = %.4f\nS = %.4f\n", L, S);

    // actual algorithm
    float readLevel = ((0.0588 * L) - (0.296 * S) - 15.8);
    printf("readlevel = %.1f\n", readLevel);


    // calculating the buckets
    if (readLevel < 1){
        printf("GRADED AT: BELOW 1\n");
    }
    if (readLevel > 16){
        printf("GRADED AT: 16+\n");
    }
    else if (1 <= readLevel <= 16){
        printf("GRADED AT: %.0f\n", readLevel);
    }
}
