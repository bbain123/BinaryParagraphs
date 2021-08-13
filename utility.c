/* CS2211a 2020 */
/* Assignment 05 */
/* Brendan Bain*/
/* 251086487 */
/* bbain7 */
/* Nov 29th 2020 */

#include "headers.h"

LINKEDLIST* createControlStructure(void){
    LINKEDLIST* list;
    list = (LINKEDLIST*) malloc(sizeof(LINKEDLIST));
    if(list){
        list->firstSent = NULL;
        list->count = 0;
    }
    return list;
}
