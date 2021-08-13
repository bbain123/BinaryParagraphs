/* CS2211a 2020 */
/* Assignment 05 */
/* Brendan Bain*/
/* 251086487 */
/* bbain7 */
/* Nov 29th 2020 */

#ifndef ASN5_INSERT_H
#define ASN5_INSERT_H

#include "headers.h"
struct sentence* newSentence(void);
struct sentence* addSentence(LINKEDLIST*);
struct sentence* nextSentence(struct sentence*);
struct word* newWord(void);
struct word* addWord(struct word* ptrWord);

#endif //ASN5_INSERT_H
