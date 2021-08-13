/* CS2211a 2020 */
/* Assignment 05 */
/* Brendan Bain*/
/* 251086487 */
/* bbain7 */
/* Nov 29th 2020 */

#include "definitions.h"

int main(){
    LINKEDLIST* list;
    list = createControlStructure();	//create control
    char str[1000];

    inputParagraph(str, list);
    printSentences(list);
    searchForWord(list, str);
    userRemoveSentence(list, str);

    removeAllSentences(list);

    return 0;
}
