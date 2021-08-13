/* CS2211a 2020 */
/* Assignment 05 */
/* Brendan Bain*/
/* 251086487 */
/* bbain7 */
/* Nov 29th 2020 */

#include "insert.h"


void inputParagraph(char str[], LINKEDLIST *list){
    struct sentence *root = list->firstSent;
    printf("Enter some words:");
    fgets(str, 1000, stdin);
    int numberOfLines = 0;

    while(str[0] != '\n'){
        numberOfLines++;				//update number of input lines
        int sizeOfInput = 0;				//counts total length of string (counting \n)
        while(str[sizeOfInput] != '\n')
                sizeOfInput++;
        sizeOfInput++;

        struct sentence* workingSentence = addSentence(list);

        list->count = numberOfLines;				   //update the count of sentences (for control structure)
        workingSentence->linePos = numberOfLines - 1;

        int wordLength = 0;
        int numWords = 0;
        int beginWord;
        char prev = ' ';
        struct word *workingWord;

        for(int i = 0; i < sizeOfInput; i++){

            if(prev == ' ' && (str[i] != '\n' && str[i] != ' ')){	    	//current is a letter and prev is a space (beginning of word)
                numWords++;
                wordLength++;
                beginWord = i;								//get position of beginning of word in relation to whole input

                if(workingSentence->firstWord == NULL) {
                    workingWord = addWord(workingSentence->firstWord); 			//add new word to workingSentence
                    workingWord->wordPos = numWords - 1;					//update wordPos
                    workingSentence->firstWord = workingWord;
                }
                else {                          //there is another word before it
                    workingWord->nextWord = addWord(workingWord->nextWord);
                    workingWord = workingWord->nextWord;
                    workingWord->wordPos = numWords - 1;
                }
            }
            else if (prev != ' ' && (str[i] != '\n' && str[i] != ' ')){    	//current is a letter and prev is a letter (middle of word)
                wordLength++;
            }
            else if (prev != ' ' && (str[i] == ' ' || str[i] == '\n')){    //current is \n or space and prev is a letter (end of word)
                workingWord->firstChar = (char*)malloc(wordLength);
                for(int i = 0; i < wordLength; i++){
                    workingWord->firstChar[i] = str[beginWord + i];
                }
                workingWord->numChars = wordLength;
                wordLength = 0;
            }

            prev = str[i];
        }
        workingSentence->numWords = numWords;
        printf("Enter some words:");
        fgets(str, 1000, stdin);
    }
}

