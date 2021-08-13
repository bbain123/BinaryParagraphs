
/* CS2211a 2020 */
/* Assignment 05 */
/* Brendan Bain*/
/* 251086487 */
/* bbain7 */
/* Nov 29th 2020 */

#ifndef HEADERS
#define HEADERS

#include <stdio.h>
#include <stdlib.h>

struct word{
    char *firstChar; //points to first character
    int numChars; //number of characters in word
    int wordPos; //position of word in sentence (starting from 0)
    struct word *nextWord; //points to the word after it
};


struct sentence{
    int linePos; //position of sentence (starting from 0)
    int numWords; //number of words in sentence
    struct word *firstWord; //points to the first word in sentence
    struct sentence *nextSent; //points to the next sentence after
};

typedef struct{
    struct sentence *firstSent;
    int count;
}LINKEDLIST;


#endif