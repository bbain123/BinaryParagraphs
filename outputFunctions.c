/* CS2211a 2020 */
/* Assignment 05 */
/* Brendan Bain*/
/* 251086487 */
/* bbain7 */
/* Nov 29th 2020 */
#include "headers.h"

void printSentences(LINKEDLIST *list){
    printf("\nHere is your input one sentence at a time: \n");

    struct sentence *curSent = list->firstSent;
    while(curSent != NULL){
        struct word *curWord = curSent->firstWord;
        while(curWord != NULL){
            for(int i = 0; i < curWord->numChars; i++){
                printf("%c", curWord->firstChar[i]);
            }
            printf(" ");
            curWord = curWord->nextWord;
        }
        printf("\n");
        curSent = curSent->nextSent;
    }
}

void searchForWord(LINKEDLIST* list, char str[]){
    printf("\nEnter a word to search for:");
    fgets(str, 1000, stdin);

    while(str[0] != '\n'){
        int wrongWord = 0;
        int foundOne = 0;
        struct sentence* root = list->firstSent;

        while(root != NULL){
            struct word *curWord = root->firstWord;
            while(curWord != NULL){
                for(int i = 0; i < curWord->numChars; i++){
                    if(str[i] != curWord->firstChar[i])
                        wrongWord= 1;			//we know this word does not match
                }
                if (wrongWord == 0){   //check for end of word
                    if(str[curWord->numChars] == '\n'){     //if search for "check", and on word "checking", we need to make sure word we are on ends
                        printf("found as word %i in sentence %i\n", curWord->wordPos + 1, root->linePos + 1);
                        foundOne = 1;                   //found at least one instance of word to search for
                    }
                }
                curWord = curWord->nextWord;
                wrongWord = 0;
            }
            root = root->nextSent;
        }

        if(foundOne == 0){
            printf("No instances of this word could be found\n");
        }
        printf("\nEnter another word to search for:");
        fgets(str, 1000, stdin);
    }

}