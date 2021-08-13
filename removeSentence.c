/* CS2211a 2020 */
/* Assignment 05 */
/* Brendan Bain*/
/* 251086487 */
/* bbain7 */
/* Nov 29th 2020 */

#include "print.h"

void removeSentence(LINKEDLIST* list, int removePos){
    if(list->firstSent != NULL && list->count >= 1){    //check if there are lines to remove
        int posRemove = removePos - 1;
        struct sentence* curSent = list->firstSent;	//use this pointer to find sentence to remove

        while(curSent != NULL && curSent->linePos != posRemove) //set pointer to sentence to remove
            curSent = curSent->nextSent;

        if(curSent != NULL && curSent->numWords >= 1){			//if curSent is sentence to remove and it has at least 1 word

            while(curSent->numWords > 1){		//loop to delete all other words but the firstWord
                struct word* tempWord = curSent->firstWord;
                struct word* prevWord = curSent->firstWord;
                if(tempWord->nextWord != NULL){
                    while(tempWord->nextWord != NULL) { //make tempWord point to last word
                        prevWord = tempWord;            //make prevWord point to word before tempWord
                        tempWord = tempWord->nextWord;
                    }
                    prevWord->nextWord = NULL;          //cut access off

                    free(tempWord->firstChar);			//remove word string
                    free(tempWord);					    //remove word Structure
                    curSent->numWords = curSent->numWords - 1; //decrease count of words
                }

            }
            //by now, only one word is left and it is being pointed to by firstWord
            free(curSent->firstWord->firstChar);
            free(curSent->firstWord);


            if(posRemove == 0 && list->count > 1){      	//SENTENCE TO REMOVE IS FIRST SENTENCE AND THERE ARE OTHER SENTENCES
                struct sentence* temp = curSent->nextSent;
                list->firstSent = temp;
                list->count = list->count - 1;
                free(curSent);

                while(temp != NULL){			//decrease all line positions past deleted sentence
                    temp->linePos = temp->linePos - 1;
                    temp = temp->nextSent;
                }
            }

            else if(posRemove == 0 && list->count == 1){ 	//SENTENCE TO REMOVE IS FIRST AND ONLY SENTENCE
                list->firstSent = NULL;
                list->count = 0;
                free(curSent);
            }

            else if (posRemove > 0 && posRemove < list->count - 1){ //SENTENCE TO REMOVE IS IN THE MIDDLE
                struct sentence* temp = list->firstSent;
                while(temp->nextSent != curSent)		//set temp to the sentence before the sentence to remove
                    temp = temp->nextSent;
                temp->nextSent = curSent->nextSent;

                temp = curSent->nextSent;   			 //set temp to sentence after the sentence to remove
                while(temp != NULL){				//decrease all line positions past deleted sentence
                    temp->linePos = temp->linePos - 1;
                    temp = temp->nextSent;
                }
                list->count = list->count - 1;
                free(curSent);

            }

            else if(posRemove == list->count - 1 && list->count != 1){      //SENTENCE TO REMOVE IS THE LAST SENTENCE
                struct sentence* temp = list->firstSent;
                while(temp->nextSent != curSent)	//set temp to the sentence before the sentence to remove
                    temp = temp->nextSent;
                temp->nextSent = NULL;
                list->count = list->count - 1;
                free(curSent);
            }

            printf("\nSuccessfully removed sentence %i\n", posRemove + 1);
            printSentences(list);
            return;
        }
    }
    printf("Position to remove is invalid\n");
}


void userRemoveSentence(LINKEDLIST* list, char str[]){
    printf("\nEnter the sentence number to remove:");
    fgets(str, 1000, stdin);

    while(str[0] != '\n'){
        int numPos = atoi(str);
        removeSentence(list, numPos);
        printf("\nEnter the sentence number to remove:");
        fgets(str, 1000, stdin);
    }
}

void removeAllSentences(LINKEDLIST* list){
    printf("-----------REMOVING SENTENCES-----------");
    for(int i = list->count; i >= 1; i--)
        removeSentence(list, i);
    free(list);
    printf("---------------------------------------\n");
    printf("(theres nothing left)...Goodbye!");
}

