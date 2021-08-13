/* CS2211a 2020 */
/* Assignment 05 */
/* Brendan Bain*/
/* 251086487 */
/* bbain7 */
/* Nov 29th 2020 */

#include "headers.h"
struct sentence* newSentence(void){ //creates new sentence and returns it
    struct sentence *temp = (struct sentence*)malloc(sizeof(struct sentence));
    temp->nextSent = NULL;
    temp->firstWord = NULL;
    return temp;
}
struct sentence* nextSentence(struct sentence* next){
    if(next->nextSent == NULL){
        next->nextSent = newSentence();
        next = next->nextSent;
        return next;
    }
    else{
        next = next->nextSent;
        return nextSentence(next);
    }
}

struct sentence* addSentence(LINKEDLIST* list){ //creates sentence at end of list
    if(list->firstSent == NULL){
        list->firstSent = newSentence();
        return list->firstSent;
    }
    else{
        struct sentence* temp = list->firstSent;
        return nextSentence(temp);
    }
}






struct word* newWord(void){
    struct word *temp = (struct word*)malloc(sizeof(struct word));
    temp->nextWord = NULL;
    temp->firstChar = NULL;
    return temp;
}

//ptr word points to first word in sentence
struct word* addWord(struct word* ptrWord){
    if(ptrWord == NULL){
        ptrWord = newWord();
        return ptrWord;
    }
    else{
        return addWord(ptrWord->nextWord);
    }


}




