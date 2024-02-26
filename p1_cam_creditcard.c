/* Project 1 for Cs50
* 2024-02-20 | Credit Cards

*/

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>

int card1(char card[], int numlen);
int card2(char card[], int numlen);

int main(void){
    char card[17]; // defining the CC
    int cardSum = 0;
    int cardSum2 = 0;
    bool isValid = false;

    printf("Credit Card Checker!\nInput a Card Number:\n");
    scanf("%s", &card);

    // ensure the entered number is valid
    // trying based on length
    // method works, but is janky...
    if (strlen(card) == 13 || strlen(card) == 15 || strlen(card) == 16){
       // printf("Valid number\n");
        isValid = true;
    }
    else {
        printf("Invalid entry!\n");
    }

    // printing the card issuer
    if (strlen(card) == 13 || strlen(card) == 16 && card[0] == '4'){
        printf("VISA\n");
        isValid = true;
    }
    if (strlen(card) == 15 && card[0] == '3' && card[1] == '4' || card[1] == '7'){
        printf("AMEX\n");
        isValid = true;
    }
    if (strlen(card) == 16 && card[0] == '5'){
        printf("MASTER\n");
        isValid = true;
    }
    else if (isValid = false){
        printf("Invalid card!\n");
        return 0;
    }

    int numlen = strlen(card);
    printf("Strlen: %d\n", strlen(card));
    printf("numlen: %d\n", numlen);

    cardSum = card1(card,numlen);
    printf("CardSum: %d\n",cardSum);

    cardSum2 = card2(card,numlen);
    printf("CardSum2: %d\n",cardSum2);

    if ((cardSum + cardSum2) % 10 == 0 || isValid == true){
        printf("Card is valid!\n");
    }
    else {
        printf("Card is invalid!\n");
    }


}

// Luhn's 1 round of calc
int card1(char card[], int numlen){
    int cardSum = 0;
    int i, j, k;
    
    for (i = numlen - 1; i > 0 ; i -= 2){
        j = (card[i-1] - '0')*2;
        //printf("j1:%i\n",j);
        k = j % 10;
        j /= 10;
        cardSum += (k + j);    
    } return cardSum;
}
//Luhn's 2nd round of calc
int card2(char card[], int numlen){
    int cardSum2 = 0;
    int i, j, k;

    for (i = numlen - 1; i >= 0 ; i -= 2){
        j = (card[i] - '0'); // i forgot NOT to *2 here...
        //printf("j2:%i\n",j);
        k = j % 10;
        j /= 10;
        cardSum2 += (k + j);     
    } return cardSum2;
}
