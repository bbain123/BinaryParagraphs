/* CS2211a 2020 */
/* Assignment 05 */
/* Brendan Bain*/
/* 251086487 */
/* bbain7 */
/* Nov 29th 2020 */

#ifndef DEFINITIONS
#define DEFINITIONS
#include "headers.h"

LINKEDLIST* createControlStructure(void);
void inputParagraph(char[], LINKEDLIST*);
void printSentences(LINKEDLIST *list);
void searchForWord(LINKEDLIST*, char str[]);
void userRemoveSentence(LINKEDLIST* list, char str[]);
void removeAllSentences(LINKEDLIST* list);
void removeSentence(LINKEDLIST* list, int removePos);


#endif